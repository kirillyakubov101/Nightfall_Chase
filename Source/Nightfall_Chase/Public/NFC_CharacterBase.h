// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractInstigator.h"
#include "InteractionDelegates.h"
#include "NFC_CharacterBase.generated.h"

UCLASS()
class NIGHTFALL_CHASE_API ANFC_CharacterBase : public ACharacter, public IInteractInstigator
{
	GENERATED_BODY()

public:
	ANFC_CharacterBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SubscribeToInteractDelegate(FOnInteractCompleteSignature& OutDelegate, float timer) override;

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void BeginRitual(float timer);

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void PlayerCompleteRitual();
};
