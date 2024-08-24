// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <boost/dll/shared_library.hpp>
#include "Engine/Engine.h"
#include "MANWorker.h"


/**
 *
 */

typedef MANWorker* (__cdecl *CreateUserCodeFunc)();

class MANAGEMENT_API ObjectLoader
{
public:
	ObjectLoader() = default;

	bool MANLoadLibrary(const FString& path);
	void MANUnloadLibrary();

	MANWorker* CreateUserObject();

	void CompileLibrary(const FString& path);
private:

	boost::dll::shared_library lib;

	CreateUserCodeFunc createUserObject;
};

