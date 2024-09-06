// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <map>

/**
 * 
 */
class MANAGEMENT_API WorkerController
{
public:
	virtual void MoveTo(const FVector& location) = 0;
	virtual void DebugMessage(const FString& message) const = 0;
	virtual class MANResourceNode* FindNearestResourceNode() const = 0;
	virtual int MineResourceNode(class AResourceNode* targetNode) = 0;
	virtual TMap<FName, int32> GetInventory() const = 0;

};
