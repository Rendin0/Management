// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"

#include "MANWorker.h"

#include "ObjectLoader.generated.h"

template <class C>
concept DerivedFromMANObject = std::is_base_of<MANObject, C>::value;


/**
 *
 */

UCLASS()
class MANAGEMENT_API AObjectLoader : public AActor
{
	GENERATED_BODY()

public:
	AObjectLoader(const FObjectInitializer& FObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void Init(const FString& pathToDLL);

	bool MANLoadLibrary(const FString& path);
	bool MANUnloadLibrary();

	template <DerivedFromMANObject Cl>
	Cl* CreateUserObject(const FString& functionName);

private:
	void* lib;

};

template<DerivedFromMANObject Cl>
inline Cl* AObjectLoader::CreateUserObject(const FString& functionName)
{
	using UserObjectGetFunc = Cl* (__cdecl*)();

	if (!lib)
		return nullptr;

	UserObjectGetFunc createUserObjectFunc = (UserObjectGetFunc)FPlatformProcess::GetDllExport(lib, *functionName);

	if (createUserObjectFunc)
		return createUserObjectFunc();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Cannot load create user code func");
	return nullptr;
}