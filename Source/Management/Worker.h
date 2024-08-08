// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "WorkerController.h"
#include "ObjectLoader.h"


#include "Worker.generated.h"

class UInventory;
class AResourceNode;
class MANWorker;

/**
 *
 */
UCLASS()
class MANAGEMENT_API AWorker : public APaperFlipbookActor, public WorkerController
{
	GENERATED_BODY()

public:
	AWorker(const FObjectInitializer& FObjectInitializer);


	UPROPERTY()
	UInventory* inventory;

	void InitFlipbook(const FString& path);
	void MineResourceNode(AResourceNode* targetNode);

	void MoveTo(AActor* target) override;
	void DebugMessage(const FString& message) override;

	void Tick(float deltaTime) override;
	void BeginPlay() override;


protected:

private:
	MANWorker* userScript = nullptr;
	ObjectLoader loader;
};
