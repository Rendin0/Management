	// Fill out your copyright notice in the Description page of Project Settings.


	#include "MANWorker.h"

	#include "Worker.h"

	void MANWorker::Debug(const std::wstring& message) const
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->DebugMessage(message.c_str());
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
