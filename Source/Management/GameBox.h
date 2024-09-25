// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameBox.generated.h"

class UMainWidget;
class AResourceNode;
class AWorker;


UCLASS()
class MANAGEMENT_API AGameBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameBox();

	UFUNCTION()
	void CreateWorker();
	void MANLoadLibrary();
	void UnloadLibrary();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainWidget> mainWidgetClass;

	UPROPERTY()
	UMainWidget* mainWidget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void CreateMainWidget();
	void AddFunctionsToButtons();

	TFunction<void()> onBegin;
	TFunction<void()> onTick;
};
