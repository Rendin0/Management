// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;

	items = TMap<FName, int32>();
}

void UInventory::AddItem(FName name, int32 amount)
{
	bool value = Check(name);

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(L"Pointer to: %d", value));

	//if (value)
	//	items.Add(name, amount + (*value));
	//else
	//	items.Emplace(name, amount);
}

void UInventory::TakeItem(FName name, int32 amount, UInventory* reciever)
{
	int32* value = items.Find(name);

	if (value)
	{
		*value -= amount;

		if (*value <= 0)
		{
			// If the quantity requested is greater than the quantity available, give whatever is left over
			amount += *value;

			items.Remove(name);
		}

		reciever->AddItem(name, amount);
	}
}

bool UInventory::Check(FName name)
{
	return items.Contains(name);
}

