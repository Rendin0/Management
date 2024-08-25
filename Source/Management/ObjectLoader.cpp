// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectLoader.h"

#include "MANWorker.h"

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

	return true;
}

void ObjectLoader::MANUnloadLibrary()
{


}


void ObjectLoader::CompileLibrary(const FString& path)
{

}



