// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Windows.h>

class MANObject;

/**
 * 
 */
class MANAGEMENT_API ObjectLoader
{
public:
	ObjectLoader() = default;

	bool MANLoadLibrary(const FString& path);
	void MANUnloadLibrary();

	MANObject* CreateUserObject();

	void CompileLibrary(const FString& path);
private:
	HMODULE userModule = nullptr;
	
	typedef MANObject* (*CreateUserCodeFunc)();
	CreateUserCodeFunc createUserCode;
};
