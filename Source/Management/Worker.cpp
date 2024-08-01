// Fill out your copyright notice in the Description page of Project Settings.


#include "Worker.h"

#include "ResourceNode.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

AWorker::AWorker(const FObjectInitializer& FObjectInitializer)
	:Super(FObjectInitializer)
{
}

void AWorker::Init()
{
	UPaperFlipbookComponent* flipbook = this->GetRenderComponent();
	flipbook->SetFlipbook(LoadObject<UPaperFlipbook>(NULL, L"/Game/Assets/Workers/Cat/Idle/Cat_Idle"));
}

void AWorker::MineResourceNode(AResourceNode* targetNode)
{
	if (targetNode)
	{
		targetNode->GetResource(inventory);
	}
}
