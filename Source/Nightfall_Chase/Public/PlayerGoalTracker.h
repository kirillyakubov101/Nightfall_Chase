// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerGoalTracker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NIGHTFALL_CHASE_API UPlayerGoalTracker : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerGoalTracker();

public:
	UFUNCTION(BlueprintPure)
	FORCEINLINE bool IsGoalReached() const { return AmountOfShrinesToPray == AmountOfShrinesComplete; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	int32 AmountOfShrinesToPray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 AmountOfShrinesComplete;

private:
	void CompleteShrine();

};
