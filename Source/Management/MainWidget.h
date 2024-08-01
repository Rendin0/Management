// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"

#include "MainWidget.generated.h"

/**
 *
 */
UCLASS()
class MANAGEMENT_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UMainWidget(const FObjectInitializer& ObjectInitializer);


	// Adds dynamic function from class to button with name buttonName

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* testButton;
protected:


private:


};


