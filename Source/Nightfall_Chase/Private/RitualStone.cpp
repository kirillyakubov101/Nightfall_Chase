// Fill out your copyright notice in the Description page of Project Settings.


#include "RitualStone.h"
#include "InteractInstigator.h"
#include "TimerManager.h"

ARitualStone::ARitualStone()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ARitualStone::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARitualStone::Interact_Implementation(AActor* Interactor)
{
	if (Interactor == nullptr || bHasRitualDone) { return; }
	InteractProcess(Interactor);
}

void ARitualStone::InteractProcess(AActor* Interactor)
{
	if (Interactor == nullptr) { return; }

	IInteractInstigator* instance = Cast<IInteractInstigator>(Interactor);
	if(instance)
	{
		instance->SubscribeToInteractDelegate(OnInteractCompleteDelegate, RitualTime);

		GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &ARitualStone::CompleteInteraction, RitualTime, false);
	}
}


void ARitualStone::CompleteInteraction()
{
	OnInteractCompleteDelegate.ExecuteIfBound();
	OnInteractCompleteDelegate.Unbind();
	bHasRitualDone = true;
}

