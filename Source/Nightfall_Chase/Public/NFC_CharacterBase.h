// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RitualInstigator.h"
#include "InteractionDelegates.h"
#include "NFC_CharacterBase.generated.h"

UCLASS()
class NIGHTFALL_CHASE_API ANFC_CharacterBase : public ACharacter, public IRitualInstigator
{
	GENERATED_BODY()

public:
	ANFC_CharacterBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Inherited via IRitualInstigator
	virtual void StartRitual(float RitualTime, TSharedPtr<FOnRitualCompleteSignature> OutDelegate) override;

	virtual void FinishRitual_Implementation() override;

	virtual void StopRitual_Implementation() override;

	UFUNCTION(BlueprintCallable)
	void InterruptPlayerAction();

protected:
	TSharedPtr<FOnRitualCompleteSignature> OnRitualCompleteDelegate;
	FTimerHandle TimerHandle;
};
