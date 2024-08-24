// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#ifdef MANAGEMENT_EXPORTS
#define MANAGEMENT_API __declspec(dllexport)
#else
#define MANAGEMENT_API __declspec(dllimport)
#endif

class AActor;


/**
 * 
 */
class MANAGEMENT_API MANObject
{
public:
	void SetBoundActor(AActor* actor);

protected:
	AActor* boundActor;

private:


};
