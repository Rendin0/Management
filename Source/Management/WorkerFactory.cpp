// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerFactory.h"
#include "Kismet/GameplayStatics.h"
#include "Worker.h"


AWorkerFactory::AWorkerFactory(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
}

void AWorkerFactory::CreateWorker()
{
	AWorker* worker = GetWorld()->SpawnActor<AWorker>(AWorker::StaticClass());
	worker->InitFlipbook(L"/Game/Assets/Workers/Cat/Idle/Cat_Idle");
}
