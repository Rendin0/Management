	// Fill out your copyright notice in the Description page of Project Settings.


	#include "MANWorker.h"

	#include "Worker.h"

	void MANWorker::Debug(const wchar_t* message) const
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->DebugMessage(FString(message));
	}

	void MANWorker::Init(AActor* actor)
	{
		SetBoundActor(actor);
	}

	void MANWorker::MoveTo(const MANObject& object)
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->MoveTo(object.GetBoundActor()->GetActorLocation());
	}

	void MANWorker::MoveTo(const MANObject* object)
	{
		MoveTo(*object);
	}

	void MANWorker::MoveTo(const std::pair<double, double> position)
	{
		if (boundActor)
			Cast<AWorker>(boundActor)->MoveTo(FVector(position.first, 0, position.second));
	}

	std::pair<double, double> MANWorker::FindNearestResourceNode() const
	{
		FVector position{};

		if (boundActor)
			position = Cast<AWorker>(boundActor)->FindNearestResourceNode();


		return std::pair<double, double>(position.X, position.Z);
	}
