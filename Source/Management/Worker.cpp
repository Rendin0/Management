// Fill out your copyright notice in the Description page of Project Settings.


#include "Worker.h"

// Unreal Headers
#include "PaperFlipbookComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbook.h"
#include "Engine/Engine.h"

// Custom Headers
#include "ResourceNode.h"
#include "MANWorker.h"

AWorker::AWorker(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;

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

	auto loader = UGameplayStatics::GetActorOfClass(GetWorld(), AObjectLoader::StaticClass());

	if (loader)
	{
		userScript = Cast<AObjectLoader>(loader)->CreateUserObject<MANWorker>("CreateUserCode");
	}

	if (userScript)
	{
		userScript->Init(this);
		userScript->Begin();
	}
}
