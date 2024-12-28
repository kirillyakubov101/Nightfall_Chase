// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionDelegates.h"
#include "InteractInstigator.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInstigator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NIGHTFALL_CHASE_API IInteractInstigator
{
	GENERATED_BODY()

public:
	virtual void SubscribeToInteractDelegate(FOnInteractCompleteSignature& OutDelegate, float timer) = 0;
};
