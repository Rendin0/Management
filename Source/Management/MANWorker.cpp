	// Fill out your copyright notice in the Description page of Project Settings.


	#include "MANWorker.h"

	#include "Worker.h"

	void MANWorker::Debug(const wchar_t* message) const
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->DebugMessage(FString(message));
	}

	void MANWorker::Move(int x, int y)
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->Move(x, y);

	}

	void MANWorker::Init(AActor* actor)
	{
		SetBoundActor(actor);
	}
