// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"
#include "Kismet/GameplayStatics.h"
#include "NFC_CharacterBase.h"


void UPlayerWidget::InitPlayerWidget(ACharacter* Owner)
{
    if (Owner)
    {
        ANFC_CharacterBase* Player = Cast<ANFC_CharacterBase>(Owner);
        if (Player)
        {
            Player->OnShrinePrayedDelegate.AddUObject(this, &UPlayerWidget::OnGoalUpdated);
            UE_LOG(LogTemp, Warning, TEXT("Delegate added in NativeConstruct"));
        }
    }
}

void UPlayerWidget::UpdateGoalFunc()
{
	UE_LOG(LogTemp, Warning, TEXT("UpdateGoalFunc"));
	OnGoalUpdated();
}
