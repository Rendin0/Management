// Fill out your copyright notice in the Description page of Project Settings.


#include "Worker.h"

#include "ResourceNode.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "MANWorker.h"
#include "Engine/Engine.h"


AWorker::AWorker(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;

	loader = ObjectLoader();
}

void AWorker::InitFlipbook(const FString& path)
{
	UPaperFlipbookComponent* flipbook = this->GetRenderComponent();
	flipbook->SetFlipbook(LoadObject<UPaperFlipbook>(NULL, *path));
}

void AWorker::MineResourceNode(AResourceNode* targetNode)
{
	{
		targetNode->GetResource(inventory);
	}
}

void AWorker::MoveTo(AActor* target)
{
	// Todo
}

void AWorker::DebugMessage(const FString& message)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, message);
}

void AWorker::Move(int x, int y)
{
	SetActorLocation(GetActorLocation() + FVector(x, 0, y));
}

void AWorker::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if (userScript)
	{
		userScript->Update();
	}
}

void AWorker::BeginPlay()
{
	Super::BeginPlay();

	if (loader.MANLoadLibrary("O:/Visual Studio/Projects/PlayerManagement/x64/Debug/PlayerManagement.dll"))
	{
		//FString pointerString = FString::Printf(TEXT("Pointer Address: %p"), loader.CreateUserObject());
		userScript = loader.CreateUserObject();
		//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, pointerString);
	}

	if (userScript)
	{
		FString pointerString = FString::Printf(TEXT("Pointer Address: %p"), userScript);
		userScript->Init(this);
		userScript->Begin();
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, pointerString);
	}
}
