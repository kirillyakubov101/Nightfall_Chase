// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTFALL_CHASE_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void InitPlayerWidget(ACharacter* Owner);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnGoalUpdated();

	//wrapper func to call the bp event
	void UpdateGoalFunc();
};
