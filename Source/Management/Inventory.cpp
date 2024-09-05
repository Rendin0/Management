// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInventory::AddItem(FName name, int32 amount)
{
	int32* value = nullptr;
	if (items.Contains(name))
		value = items.Find(name);

	FString message = FString::Printf(L"Pointer: %p", value);

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, message);

	//if (value)
	//	(*value) += amount;
	//else
	//	items.Add(name, amount);
}

void UInventory::GiveItem(FName name, int32 amount, UInventory* reciever)
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

