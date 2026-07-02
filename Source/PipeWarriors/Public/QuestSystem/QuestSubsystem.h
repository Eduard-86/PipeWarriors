// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "QuestSubsystem.generated.h"

class UQuestPanelWidget;

UCLASS()
class PIPEWARRIORS_API UQuestSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UQuestPanelWidget* questPanel;

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UQuestPanelWidget> QuestWidgetClass;

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
};
