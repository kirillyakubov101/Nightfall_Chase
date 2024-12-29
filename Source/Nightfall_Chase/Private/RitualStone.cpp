// Fill out your copyright notice in the Description page of Project Settings.


#include "RitualStone.h"
#include "RitualInstigator.h"

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
	if(instance)
	{
		TSharedPtr<FOnRitualCompleteSignature> OutDelegate = MakeShared<FOnRitualCompleteSignature>();
		OutDelegate->BindUObject(this, &ARitualStone::CompleteRitual);

		instance->StartRitual(RitualTime, OutDelegate);
		
	}
}

void ARitualStone::CompleteRitual()
{
	UE_LOG(LogTemp, Warning, TEXT("RITUAL: DONE"));
	bHasRitualDone = true;
}

