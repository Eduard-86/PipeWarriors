// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"
#include "EndQuestDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PIPEWARRIORS_API UEndQuestDataAsset : public UOnLevelTriggerDataAsset
{
	GENERATED_BODY()

public:
	virtual void TriggerAction_Implementation(UWorld* world) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString QuestNameToEnd;
};
