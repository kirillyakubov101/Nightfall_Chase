// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGoalTracker.h"
#include "NFC_CharacterBase.h"

UPlayerGoalTracker::UPlayerGoalTracker()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UPlayerGoalTracker::BeginPlay()
{
	Super::BeginPlay();

	ANFC_CharacterBase* PlayerChar = Cast<ANFC_CharacterBase>(GetOwner());
	if (PlayerChar)
	{
		PlayerChar->OnShrinePrayedDelegate.AddUObject(this, &UPlayerGoalTracker::CompleteShrine);
	}
	
}

void UPlayerGoalTracker::CompleteShrine()
{
	AmountOfShrinesComplete++;
}


