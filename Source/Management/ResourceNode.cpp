// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceNode.h"
#include "MANResourceNode.h"

#include "Inventory.h"

AResourceNode::AResourceNode(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	apiNode.Init(this);
}

int AResourceNode::GetResource(UInventory* reciever)
{
	int errorType = 1;
	for (auto& resource : resources)
	{
		if (FMath::RandRange(0, 10000) / 10000.f < resource.Value)
		{
			reciever->AddItem(resource.Key, 1);
			errorType = 0;
		}
	}

	return errorType;
}

MANResourceNode* AResourceNode::GetAPINode()
{
	return &apiNode;
}

void AResourceNode::AddResource(FName name, float chance)
{
	float* item = resources.Find(name);

	if (item)
		*item = chance;
	else
		resources.Add(name, chance);
}
