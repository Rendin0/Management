// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectLoader.h"

#include <boost/dll/import.hpp>
#include <boost/function.hpp>


bool ObjectLoader::MANLoadLibrary(const FString& path)
{
	lib = boost::dll::shared_library(*path);
	if (!lib.is_loaded())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Cannot load library");
		return false;
	}

	createUserObject = lib.get<MANWorker* __cdecl()>("CreateUserCode");

	if (!createUserObject)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Cannot load create user code func");
		return false;
	}

	return true;
}

void ObjectLoader::MANUnloadLibrary()
{


}

MANWorker* ObjectLoader::CreateUserObject()
{
	if (createUserObject)
		return createUserObject();

	return nullptr;
}

void ObjectLoader::CompileLibrary(const FString& path)
{

}



