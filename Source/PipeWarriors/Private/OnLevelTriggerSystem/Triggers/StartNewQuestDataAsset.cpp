// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLevelTriggerSystem/Triggers/StartNewQuestDataAsset.h"
#include "QuestSystem/QuestSubsystem.h"
#include "QuestSystem/QuestNode.h"

void UStartNewQuestDataAsset::TriggerAction(UWorld* world)
{
	auto questSubsystem = world->GetSubsystem<UQuestSubsystem>();
	if (questSubsystem != nullptr)
	{
		auto quest = NewObject<UQuestNode>();
		quest->QuestName = NewQuestName;
		quest->Description = QuestDescription;
		quest->successProgress = QuestSuccessProgress;
		questSubsystem->CreateNewQuest(quest);
	}
}