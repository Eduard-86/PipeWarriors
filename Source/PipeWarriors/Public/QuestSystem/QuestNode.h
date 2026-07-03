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
	FString QuestName;

	UPROPERTY()
	FText Description;

public:
	FText FormatQuestDescription();
};
