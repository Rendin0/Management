// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <boost/dll/shared_library.hpp>
#include "Engine/Engine.h"

#include "MANWorker.h"

template <class C>
concept DerivedFromMANObject = std::is_base_of<MANObject, C>::value;


/**
 *
 */


class MANAGEMENT_API ObjectLoader
{
public:
	ObjectLoader() = default;

	bool MANLoadLibrary(const FString& path);
	void MANUnloadLibrary();

	template <DerivedFromMANObject Cl>
	Cl* CreateUserObject(const std::string& functionName);

	void CompileLibrary(const FString& path);
private:

	boost::dll::shared_library lib;

};

template<DerivedFromMANObject Cl>
inline Cl* ObjectLoader::CreateUserObject(const std::string& functionName)
{
	auto createUserObjectFunc = lib.get<Cl * __cdecl()>(functionName);

	if (createUserObjectFunc)
		return createUserObjectFunc();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Cannot load create user code func");
	return nullptr;
}