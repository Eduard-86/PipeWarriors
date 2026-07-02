// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"
#include "StartNewQuestDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PIPEWARRIORS_API UStartNewQuestDataAsset : public UOnLevelTriggerDataAsset
{
	GENERATED_BODY()

public:
	virtual void TriggerAction(UWorld* world) override;
};
