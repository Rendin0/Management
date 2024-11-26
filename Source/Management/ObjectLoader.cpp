// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectLoader.h"

#include "MANWorker.h"

namespace boost
{
	void throw_exception(std::exception const&) {}
}


AObjectLoader::AObjectLoader(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void AObjectLoader::Init(const FString& pathToDLL)
{
	MANLoadLibrary(pathToDLL);
}

bool AObjectLoader::MANLoadLibrary(const FString& path)
{

	lib = FPlatformProcess::GetDllHandle(*path);
	if (!lib)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Can not load library"));
		return false;
	}

	return true;
}

bool AObjectLoader::MANUnloadLibrary()
{
	if (lib)
	{
		FPlatformProcess::FreeDllHandle(lib);
		lib = nullptr;
	}

	return true;
}

