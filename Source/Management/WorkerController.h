// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MANAGEMENT_API WorkerController
{
public:
	virtual void MoveTo(AActor* target) = 0;
	virtual void DebugMessage(const FString& message) = 0;
};
