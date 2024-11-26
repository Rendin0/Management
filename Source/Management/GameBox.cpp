// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBox.h"

#include "MainWidget.h"
#include "ResourceNode.h"
#include "Worker.h"
#include "WorkerFactory.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFileManager.h"

// Sets default values
AGameBox::AGameBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AGameBox::CreateWorker()
{
	AWorkerFactory* workerFactory = Cast<AWorkerFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorkerFactory::StaticClass()));
	workerFactory->CreateWorker();
}

void AGameBox::MANLoadLibrary()
{
	AObjectLoader* objectLoader = Cast<AObjectLoader>(UGameplayStatics::GetActorOfClass(GetWorld(), AObjectLoader::StaticClass()));

	TArray<AActor*> workers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorker::StaticClass(), workers);

	// Path to %APPDATA%/Management/PlayerDLLs/
	FString pathToDLL = FPaths::EngineUserDir() + L"../../../Roaming/Management/PlayerDLLs/";
	objectLoader->MANLoadLibrary(FPaths::Combine(pathToDLL, mainWidget->dllNameInput->GetText().ToString()));

	for (auto& i : workers)
	{
		// Loads Func from DLL with name from widget
		Cast<AWorker>(i)->LoadUserScript(objectLoader->CreateUserObject<MANWorker>(mainWidget->funcNameInput->GetText().ToString()));
	}
}

void AGameBox::UnloadLibrary()
{
	AObjectLoader* objectLoader = Cast<AObjectLoader>(UGameplayStatics::GetActorOfClass(GetWorld(), AObjectLoader::StaticClass()));

	TArray<AActor*> workers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorker::StaticClass(), workers);

	for (auto& i : workers)
	{
		Cast<AWorker>(i)->UnloadUserScript();
	}

	objectLoader->MANUnloadLibrary();
}



void AGameBox::BeginPlay()
{
	Super::BeginPlay();

	CreateMainWidget();
}

void AGameBox::CreateMainWidget()
{
	APlayerController* controller = GEngine->GetFirstLocalPlayerController(GetWorld());
	check(controller);
	mainWidget = CreateWidget<UMainWidget>(controller, mainWidgetClass);

	AddFunctionsToButtons();

	check(mainWidget);
	mainWidget->AddToPlayerScreen();
}

void AGameBox::AddFunctionsToButtons()
{
	if (mainWidget)
	{
		mainWidget->createWorker->OnClicked.AddDynamic(this, &AGameBox::CreateWorker);
		mainWidget->unloadLibrary->OnClicked.AddDynamic(this, &AGameBox::UnloadLibrary);
		mainWidget->loadLibrary->OnClicked.AddDynamic(this, &AGameBox::MANLoadLibrary);
	}
}


