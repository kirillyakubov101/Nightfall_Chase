// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionDelegates.h"
#include "RitualInstigator.generated.h"

DECLARE_DELEGATE(FOnRitualCompleteSignature);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class URitualInstigator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NIGHTFALL_CHASE_API IRitualInstigator
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void FinishRitual();
	virtual void FinishRitual_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopRitual();
	virtual void StopRitual_Implementation() = 0;

	virtual void StartRitual(float RitualTime, FOnRitualCompleteSignature& OutDelegate) = 0;
};
