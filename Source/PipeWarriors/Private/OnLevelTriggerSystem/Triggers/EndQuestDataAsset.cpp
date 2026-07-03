// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLevelTriggerSystem/Triggers/EndQuestDataAsset.h"
#include "QuestSystem/QuestSubsystem.h"

void UEndQuestDataAsset::TriggerAction_Implementation(UWorld* world)
{
	auto questSubsystem = world->GetSubsystem<UQuestSubsystem>();
	if (questSubsystem != nullptr)
	{
		questSubsystem->RemoveQuest(QuestNameToEnd);
	}
}
