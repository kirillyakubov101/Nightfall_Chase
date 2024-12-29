// Fill out your copyright notice in the Description page of Project Settings.


#include "NFC_CharacterBase.h"

// Sets default values
ANFC_CharacterBase::ANFC_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANFC_CharacterBase::StartRitual(float RitualTime, TSharedPtr<FOnRitualCompleteSignature> OutDelegate)
{
	bIsRitualInstigatorBusy = true;
	OnRitualCompleteDelegate = OutDelegate;
	StartRitualEvent(); //BP- EVENT

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ANFC_CharacterBase::FinishRitual_Implementation, RitualTime, false);
}

void ANFC_CharacterBase::FinishRitual_Implementation()
{
	Execute_FinishRitual(this);
	OnRitualCompleteDelegate->ExecuteIfBound();
	bIsRitualInstigatorBusy = false;
	if (OnShrinePrayedDelegate.IsBound())
	{
		OnShrinePrayedDelegate.Broadcast();
	}
}

void ANFC_CharacterBase::StopRitual_Implementation()
{
	if (OnRitualCompleteDelegate.IsValid() && OnRitualCompleteDelegate->IsBound())
	{
		OnRitualCompleteDelegate->Unbind();
		if (GetWorld()->GetTimerManager().IsTimerActive(TimerHandle))
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		}

		bIsRitualInstigatorBusy = false;
	}
}

bool ANFC_CharacterBase::IsRitualInstigatorBusy() const
{
	return bIsRitualInstigatorBusy;
}

void ANFC_CharacterBase::InterruptPlayerAction()
{
	StopRitual_Implementation();
}


