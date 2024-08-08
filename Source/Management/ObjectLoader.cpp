// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectLoader.h"

#include "MANObject.h"


bool ObjectLoader::MANLoadLibrary(const FString& path)
{
	//CompileLibrary(path);

	userModule = LoadLibrary(L"O:/UserScripts/PlayerManagement.dll");
	if (!userModule)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Failed to load user DLL");
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::FromInt(static_cast<int32>(GetLastError())));
		return false;
	}

	createUserCode = (CreateUserCodeFunc)(GetProcAddress(userModule, "CreateUserCode"));

	if (!createUserCode)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, L"Failed to load create user code func");
		FreeLibrary(userModule);
		return false;
	}

	return createUserCode() != nullptr;
	//return false;
}

void ObjectLoader::MANUnloadLibrary()
{
	if (userModule)
	{
		FreeLibrary(userModule);
		userModule = nullptr;
	}
}

MANObject* ObjectLoader::CreateUserObject()
{
	return createUserCode();
}

void ObjectLoader::CompileLibrary(const FString& path)
{
	const char* charPath = TCHAR_TO_UTF8(*path);

	//system("echo clang++ -c \"" + *charPath + *"\" -o O:/UserScripts/UserWorker.obj -I \"O:/UnrealProjects/Management/Source/Management\"");
	system("clang++ -c \"O:/Visual Studio/Projects/PlayerManagement/PlayerManagement/FirstWorker.cpp\" -o \"O:/UserScripts/UserWorker.obj\" -I \"O:/UnrealProjects/Management/Source/Management\"");
	system("clang++ -shared -o O:/UserScripts/UserCode.dll O:/UserScripts/UserWorker.obj");
	system("pause");
}

