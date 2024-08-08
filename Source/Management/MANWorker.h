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
	void Debug(const std::string& message) const;
	void Init(AActor* actor);

	virtual void Update() = 0;
	virtual void Begin() = 0;

protected:


private:
};
