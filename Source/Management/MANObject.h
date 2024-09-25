// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#ifdef MANAGEMENT_EXPORTS
#define MAN_API __declspec(dllexport)
#else
#define MAN_API __declspec(dllimport)
#endif

class AActor;


/**
 * 
 */
class MAN_API MANObject
{
public:
	MANObject() = default;

	friend class MANResourceNode;
	friend class MANWorker;

	virtual ~MANObject() = default;
protected:
	void SetBoundActor(AActor* actor);
	AActor* boundActor;
	AActor* GetBoundActor() const;


private:


};
