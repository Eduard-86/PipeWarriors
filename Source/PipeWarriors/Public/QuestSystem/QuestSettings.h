// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "QuestSettings.generated.h"

class UQuestPanelWidget;
class UQuestNoteWidget;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Quest settings"))
class PIPEWARRIORS_API UQuestSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="UI")
	TSubclassOf<UQuestPanelWidget> QuestPanelWidgetClass;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UQuestNoteWidget> QuestNoteWidgetClass;
};
