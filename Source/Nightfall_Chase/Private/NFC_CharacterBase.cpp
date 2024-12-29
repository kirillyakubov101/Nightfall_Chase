// Fill out your copyright notice in the Description page of Project Settings.


#include "NFC_CharacterBase.h"

// Sets default values
ANFC_CharacterBase::ANFC_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANFC_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANFC_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANFC_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANFC_CharacterBase::StartRitual(float RitualTime, FOnRitualCompleteSignature& OutDelegate)
{
	OnRitualCompleteDelegate = OutDelegate;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ANFC_CharacterBase::FinishRitual_Implementation, RitualTime, false);
}

void ANFC_CharacterBase::FinishRitual_Implementation()
{
	OnRitualCompleteDelegate.ExecuteIfBound();
	UE_LOG(LogTemp, Warning, TEXT("Player: DONE"));
}

void ANFC_CharacterBase::StopRitual_Implementation()
{
	if (OnRitualCompleteDelegate.IsBound())
	{
		OnRitualCompleteDelegate.Unbind();
		if (GetWorld()->GetTimerManager().IsTimerActive(TimerHandle))
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		}
	}
}

void ANFC_CharacterBase::InterruptPlayerAction()
{
	StopRitual_Implementation();
}


