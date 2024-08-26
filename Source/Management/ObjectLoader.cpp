// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectLoader.h"

#include "MANWorker.h"

#include <boost/dll/import.hpp>
#include <boost/function.hpp>

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

	try
	{
		lib.load(TCHAR_TO_UTF8(*path));
	}
	catch (const std::exception& ex)
	{
		FString errorMsg = FString::Printf(TEXT("Lib Error: %s"), UTF8_TO_TCHAR(ex.what()));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, errorMsg);
	}
	if (!lib.is_loaded())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Cannot load library");
		return false;
	}

	return true;
}

