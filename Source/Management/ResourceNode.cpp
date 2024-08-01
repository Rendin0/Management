// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceNode.h"

#include "Inventory.h"

AResourceNode::AResourceNode(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

}

void AResourceNode::GetResource(UInventory* reciever)
{
	for (auto& resource : resources)
	{
		if (FMath::RandRange(0, 10000) / 10000.f < resource.Value)
			reciever->AddItem(resource.Key, 1);
	}
}

void AResourceNode::AddResource(FName name, float chance)
{
	float* item = resources.Find(name);

	if (item)
		*item = chance;
	else
		resources.Add(name, chance);
}
