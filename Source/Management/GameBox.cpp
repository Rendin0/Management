// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBox.h"

#include "MainWidget.h"
#include "ResourceNode.h"
#include "Kismet/GameplayStatics.h"
#include "Worker.h"
#include "Engine/Engine.h"
#include "WorkerFactory.h"

// Sets default values
AGameBox::AGameBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SetStandartVariables();
	SetUserVariables();

}

void AGameBox::TestFuncion()
{
	AWorkerFactory* workerFactory = Cast<AWorkerFactory>(UGameplayStatics::GetActorOfClass(GetWorld(), AWorkerFactory::StaticClass()));
	workerFactory->CreateWorker();
}

void AGameBox::SetOnBegin(TFunction<void()> _onBegin)
{
	onBegin = _onBegin;
}

void AGameBox::SetOnTick(TFunction<void()> _onTick)
{
	onTick = _onTick;
}

TArray<AResourceNode*> AGameBox::GetAllResourceNodes()
{
	TArray<AActor*> baseActors;
	TArray<AResourceNode*> resourceNodes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AResourceNode::StaticClass(), baseActors);

	for (auto& actor : baseActors)
	{
		resourceNodes.Add(Cast<AResourceNode>(actor));
	}

	return resourceNodes;
}

TArray<AWorker*> AGameBox::GetAllWorkers()
{
	// Todo

	return TArray<AWorker*>();
}

void AGameBox::BeginPlay()
{
	Super::BeginPlay();

	CreateMainWidget();

	onBegin();
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
		mainWidget->testButton->OnClicked.AddDynamic(this, &AGameBox::TestFuncion);
	}
}

void AGameBox::SetStandartVariables()
{
	// Ticks every one second
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;
}

void AGameBox::SetUserVariables()
{
	onBegin = []() {};
	onTick = []() {};
}

void AGameBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	onTick();
}

