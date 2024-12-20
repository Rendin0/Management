// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"


#include "Inventory.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MANAGEMENT_API UInventory : public UActorComponent
{
	GENERATED_BODY()

	friend class AResourceNode;
public:	
	UInventory();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TakeItem(FName name, int32 amount, UInventory* reciever);
	// Moves item from this inventory to reciever

	UFUNCTION(BlueprintCallable)
	bool Check(FName name);

	TMap<FName, int32> GetItems() const;
protected:


private:

	UPROPERTY()
	TMap<FName, int32> items;

	void AddItem(FName name, int32 amount);

};
