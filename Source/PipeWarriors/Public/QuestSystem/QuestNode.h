// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestNode.generated.h"

/**
 * 
 */
UCLASS()
class PIPEWARRIORS_API UQuestNode : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	FText QuestName;

	int32 currentProgress = 0;
	int32 successProgress = 1;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	bool bHideProgress = false;

public:
	FText FormatQuestDescription();
};
