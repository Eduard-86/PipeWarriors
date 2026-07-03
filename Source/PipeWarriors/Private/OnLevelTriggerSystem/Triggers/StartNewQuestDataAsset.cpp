// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLevelTriggerSystem/Triggers/StartNewQuestDataAsset.h"
#include "QuestSystem/QuestSubsystem.h"
#include "QuestSystem/QuestNode.h"

void UStartNewQuestDataAsset::TriggerAction_Implementation(UWorld* world)
{
	auto questSubsystem = world->GetSubsystem<UQuestSubsystem>();
	if (questSubsystem != nullptr)
	{
		auto quest = NewObject<UQuestNode>();
		quest->QuestName = NewQuestName;
		quest->Description = QuestDescription;
		questSubsystem->CreateNewQuest(quest);
	}
}