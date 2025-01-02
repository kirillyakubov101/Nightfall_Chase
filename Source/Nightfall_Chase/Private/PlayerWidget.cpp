// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"
#include "Kismet/GameplayStatics.h"
#include "NFC_CharacterBase.h"
#include "RitualStone.h"


void UPlayerWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UPlayerWidget::InitPlayerWidget(ACharacter* Owner)
{
    if (Owner)
    {
        ANFC_CharacterBase* Player = Cast<ANFC_CharacterBase>(Owner);
        if (Player)
        {
            Player->OnShrinePrayedDelegate.AddUObject(this, &UPlayerWidget::OnGoalUpdated);
        }
    }
}

void UPlayerWidget::UpdateGoalFunc()
{
	OnGoalUpdated();
}
