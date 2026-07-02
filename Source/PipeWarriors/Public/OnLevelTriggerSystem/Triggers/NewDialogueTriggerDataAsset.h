// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"
#include "NewDialogueTriggerDataAsset.generated.h"

UCLASS()
class PIPEWARRIORS_API UNewDialogueTriggerDataAsset : public UOnLevelTriggerDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FText NPCName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	UDataTable* newDialogueTable;

	virtual void TriggerAction(UWorld* world) override;
};
