// Fill out your copyright notice in the Description page of Project Settings.


#include "Worker.h"

// Unreal Headers
#include "PaperFlipbookComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbook.h"
#include "Engine/Engine.h"

// Custom Headers
#include "MANResourceNode.h"
#include "ResourceNode.h"
#include "MANWorker.h"


AWorker::AWorker(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;

	inventory = CreateDefaultSubobject<UInventory>(L"UInventory");
}

void AWorker::InitFlipbook(const FString& path)
{
	UPaperFlipbookComponent* flipbook = this->GetRenderComponent();
	flipbook->SetFlipbook(LoadObject<UPaperFlipbook>(NULL, *path));
}

int AWorker::MineResourceNode(AResourceNode* targetNode)
{
	if (FVector::Dist2D(GetActorLocation(), targetNode->GetActorLocation()) > 5.)
		return 2; // Too far away

	return targetNode->GetResource(inventory);
}

void AWorker::MoveTo(const FVector& location)
{
	const FVector currentLocation = GetActorLocation();

	SetActorLocation(currentLocation + ((location - currentLocation).GetSafeNormal() * moveSpeed));
}

void AWorker::DebugMessage(const FString& message) const
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, message);
}

MANResourceNode* AWorker::FindNearestResourceNode() const
{
	TArray<AActor*> outActors{};

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AResourceNode::StaticClass(), outActors);

	if (outActors.IsEmpty())
		return nullptr;

	AResourceNode* nearest = Cast<AResourceNode>(outActors[0]);

	for (const auto& actor : outActors)
	{
		if (FVector::Dist2D(GetActorLocation(), actor->GetActorLocation()) < FVector::Dist2D(GetActorLocation(), nearest->GetActorLocation()))
			nearest = Cast<AResourceNode>(actor);
	}

	return nearest->GetAPINode();
}

TMap<FName, int32> AWorker::GetInventory() const
{
	return inventory->GetItems();
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
		LoadUserScript(Cast<AObjectLoader>(loader)->CreateUserObject<MANWorker>("CreateUserCode"));

	if (userScript)
		userScript->OnWorkerCreate();

}

void AWorker::BeginDestroy()
{
	Super::BeginDestroy();

	if (userScript)
		userScript->OnDestroy();

	UnloadUserScript();
}

void AWorker::UnloadUserScript()
{
	if (userScript)
		userScript->OnScriptUnload();

	delete userScript;
	userScript = nullptr;
}

void AWorker::LoadUserScript(MANWorker* script)
{
	userScript = script;

	if (userScript)
	{
		userScript->Init(this);
		userScript->Begin();
	}
}
