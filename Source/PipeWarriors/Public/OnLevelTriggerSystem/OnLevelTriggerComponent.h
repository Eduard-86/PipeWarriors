// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnLevelTriggerComponent.generated.h"

class UOnLevelTriggerDataAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIPEWARRIORS_API UOnLevelTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOnLevelTriggerComponent();

	UFUNCTION(BlueprintCallable)
	void ActivateAllTriggers();

	UFUNCTION(BlueprintCallable)
	void ActivateTriggerByName(FText name);

protected:
	UPROPERTY(EditInstanceOnly)
	TArray<TSoftObjectPtr<UOnLevelTriggerDataAsset>> triggers;
};
