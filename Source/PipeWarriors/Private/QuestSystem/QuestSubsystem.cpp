// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestSystem/QuestSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "QuestSystem/QuestPanelWidget.h"
#include "QuestSystem/QuestSettings.h"
#include "QuestSystem/QuestNode.h"

void UQuestSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	auto playerController = UGameplayStatics::GetPlayerController(&InWorld, 0);
	
	if (playerController != nullptr)
	{
		const UQuestSettings* settings = GetDefault<UQuestSettings>();
		questPanel = CreateWidget<UQuestPanelWidget>(playerController, settings->QuestPanelWidgetClass);
		questPanel->AddToViewport(0);
	}
}

void UQuestSubsystem::CreateNewQuest(UQuestNode* questNode)
{
	quests.AddUnique(questNode);
	questPanel->AddQuestNote(questNode->FormatQuestDescription());
}

void UQuestSubsystem::RemoveQuest(FString QuestName)
{
	for (auto quest : quests)
	{
		if (quest->QuestName == QuestName)
		{
			int32 index = quests.Find(quest);
			questPanel->DeleteQuestNote(index);

			quests.Remove(quest);

			break;
		}
	}
}
