// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "WorkerFactory.generated.h"

/**
 * 
 */
UCLASS()
class MANAGEMENT_API AWorkerFactory : public APaperFlipbookActor
{
	GENERATED_BODY()
	

public:
	AWorkerFactory(const FObjectInitializer& FObjectInitializer);

	UFUNCTION()
	void CreateWorker();

protected:


private:


};
