// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"

#include "ResourceNode.generated.h"
/**
 * 
 */

class UInventory;

UCLASS()
class MANAGEMENT_API AResourceNode : public APaperFlipbookActor
{
	GENERATED_BODY()
	

public:
	AResourceNode(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	void GetResource(UInventory* reciever);

	TMap<FName, float> resources;
protected:
	

private:
	UFUNCTION(BlueprintCallable)
	void AddResource(FName name, float chance);

};