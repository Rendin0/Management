// Fill out your copyright notice in the Description page of Project Settings.


#include "MANWorker.h"

#include "CoreMinimal.h"
#include "Engine/Engine.h"

void MANWorker::Debug(const std::string& message) const
{
	if (boundActor && GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, message.c_str());
}

void MANWorker::Init(AActor* actor)
{
	SetBoundActor(actor);
}
