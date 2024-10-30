// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "WorkerController.h"
#include "ObjectLoader.h"
#include "MANWorker.h"
#include "Inventory.h"

#include "Worker.generated.h"

class UInventory;
class AResourceNode;

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

	int MineResourceNode(AResourceNode* targetNode) override;
	void MoveTo(const FVector& position) override;
	void DebugMessage(const FString& message) const override;
	MANResourceNode* FindNearestResourceNode() const override;
	TMap<FName, int32> GetInventory() const override;
	void Log(const wchar_t* message);

	void Tick(float deltaTime) override;
	void BeginPlay() override;
	void BeginDestroy() override;

	void UnloadUserScript();
	void LoadUserScript(MANWorker* script);
protected:

private:
	MANWorker* userScript = nullptr;

	double moveSpeed = 10.;
};
