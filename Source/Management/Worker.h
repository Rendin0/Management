// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "Worker.generated.h"


class UInventory;
class AResourceNode;

/**
 *
 */
UCLASS()
class MANAGEMENT_API AWorker : public APaperFlipbookActor
{
	GENERATED_BODY()

public:
	AWorker(const FObjectInitializer& FObjectInitializer);


	UPROPERTY()
	UInventory* inventory;

	void Init();
	void MineResourceNode(AResourceNode* targetNode);
protected:


private:

};
