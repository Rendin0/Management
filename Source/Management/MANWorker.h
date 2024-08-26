// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "MANObject.h"
#include <string>

/**
 * 
 */
class MANAGEMENT_API MANWorker : private MANObject
{
public:
	void Debug(const wchar_t* message) const;
	void Move(int x, int y);
	void Init(AActor* actor);

	virtual void Update() = 0;
	virtual void Begin() = 0;

protected:


private:
};


#define CREATE_WORKER(ClassName, FunctionName)\
extern "C" __declspec(dllexport) MANWorker* __cdecl FunctionName()\
{\
    return new ClassName();\
}