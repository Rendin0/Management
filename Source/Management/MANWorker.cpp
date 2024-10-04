// Fill out your copyright notice in the Description page of Project Settings.


#include "MANWorker.h"
#include "MANResourceNode.h"

#include "ResourceNode.h"
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

MANResourceNode* MANWorker::FindNearestResourceNode() const
{
	MANResourceNode* resourceNode = nullptr;

	if (boundActor)
		resourceNode = Cast<AWorker>(boundActor)->FindNearestResourceNode();


	return resourceNode;
}

int MANWorker::MineResourceNode(MANResourceNode* node)
{
	if (boundActor)
		return Cast<AWorker>(boundActor)->MineResourceNode(Cast<AResourceNode>(node->GetBoundActor()));

	return -1;
}

const wchar_t* MANWorker::GetInventory()
{
	std::wstring inv{};

	if (boundActor)
	{
		auto items = Cast<AWorker>(boundActor)->GetInventory();

		if (items.IsEmpty())
			return L"";

		for (const auto& item : items)
		{
			std::wstring first = *(item.Key.ToString());
			int second = item.Value;

			inv += L"{" + first + L":" + std::to_wstring(second) + L"}";
		}
	}

	static const wchar_t* toReturn = inv.c_str();
	Debug(toReturn);
	return toReturn;
}

void MANWorker::OnWorkerCreate()
{
}

void MANWorker::OnDestroy()
{
}

void MANWorker::OnScriptUnload()
{
}
