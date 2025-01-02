// Fill out your copyright notice in the Description page of Project Settings.


#include "RitualStone.h"
#include "RitualInstigator.h"

//static
FOnShrineApproachedSignature ARitualStone::OnShrineApproachedDelegate;

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

	IRitualInstigator* instance = Cast<IRitualInstigator>(Interactor);
	if(instance && !instance->IsRitualInstigatorBusy())
	{
		TSharedPtr<FOnRitualCompleteSignature> OutDelegate = MakeShared<FOnRitualCompleteSignature>();
		OutDelegate->BindUObject(this, &ARitualStone::CompleteRitual);

		instance->StartRitual(RitualTime, OutDelegate);
		
	}
}

void ARitualStone::ApproachShrine()
{
	OnShrineApproachedDelegate.ExecuteIfBound();
}

void ARitualStone::CompleteRitual()
{
	UE_LOG(LogTemp, Warning, TEXT("RITUAL: DONE"));
	bHasRitualDone = true;
}

