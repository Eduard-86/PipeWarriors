// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLevelTriggerSystem/Triggers/StartNewQuestDataAsset.h"
#include "QuestSystem/QuestSubsystem.h"

void UStartNewQuestDataAsset::TriggerAction(UWorld* world)
{
	auto questSubsystem = world->GetSubsystem<UQuestSubsystem>();
	if (questSubsystem != nullptr)
	{
		questSubsystem->CreateNewQuest();
	}
}