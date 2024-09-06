// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInventory::BeginPlay()
{
	Super::BeginPlay();

	items.Reserve(10);
}

void UInventory::AddItem(FName name, int32 amount)
{
	int32* value = items.Find(name);

	if (value)
		(*value) += amount;
	else
		items.Emplace(name, amount);
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

TMap<FName, int32> UInventory::GetItems() const
{
	return items;
}

