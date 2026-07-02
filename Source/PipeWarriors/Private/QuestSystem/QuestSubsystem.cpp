// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestSystem/QuestSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "QuestSystem/QuestPanelWidget.h"
#include "QuestSystem/QuestSettings.h"

void UQuestSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	auto playerController = UGameplayStatics::GetPlayerController(&InWorld, 0);
	
	if (playerController != nullptr)
	{
		const UQuestSettings* settings = GetDefault<UQuestSettings>();
		questPanel = CreateWidget<UQuestPanelWidget>(playerController, settings->QuestWidgetClass);
		questPanel->AddToViewport(0);
	}
}
