// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MANAGEMENT_API WorkerController
{
public:
	virtual void MoveTo(const FVector& location) = 0;
	virtual void DebugMessage(const FString& message) const = 0;
	virtual FVector FindNearestResourceNode() const = 0;
};
