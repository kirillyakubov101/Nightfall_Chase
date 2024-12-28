// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interact.h"
#include "RitualStone.generated.h"

UCLASS()
class NIGHTFALL_CHASE_API ARitualStone : public AActor, public IInteract
{
	GENERATED_BODY()
	
public:	
	ARitualStone();

protected:
	virtual void BeginPlay() override;


public:
	// Inherited via IInteract
	void Interact_Implementation(AActor* Interactor) override;
	virtual void InteractProcess(AActor* Interactor) override;
	//End of IInteract

protected:
	void CompleteInteraction();

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	bool bHasRitualDone = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RitualTime = 3.f;

private:
	FOnInteractCompleteSignature OnInteractCompleteDelegate;
	FTimerHandle MyTimerHandle;
};
