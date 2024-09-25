
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "MANObject.h"
#include <string>
#include <map>

class MANResourceNode;

/**
 * 
 */
class MAN_API MANWorker : private MANObject
{
public:

	void  Debug(const wchar_t* message) const;
	void Init(AActor* actor);
	void MoveTo(const MANObject& object);
	void MoveTo(const MANObject* object);
	void MoveTo(const std::pair<double, double> position);
	MANResourceNode* FindNearestResourceNode() const;
	int MineResourceNode(MANResourceNode* node);
	std::map<std::string, int>* GetInventory() const;

	virtual void Update() = 0;
	virtual void Begin() = 0;

	virtual ~MANWorker() override = default;
protected:


private:

};


#define CREATE_WORKER(ClassName, FunctionName)\
extern "C" __declspec(dllexport) MANWorker* __cdecl FunctionName()\
{\
    return new ClassName();\
}