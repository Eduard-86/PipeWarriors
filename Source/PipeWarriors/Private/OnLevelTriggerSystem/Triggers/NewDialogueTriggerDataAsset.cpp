// Fill out your copyright notice in the Description page of Project Settings.

#include "OnLevelTriggerSystem/Triggers/NewDialogueTriggerDataAsset.h"
#include "DialogueSystem/DialogueSubsystem.h"

void UNewDialogueTriggerDataAsset::TriggerAction_Implementation(UWorld* world)
{
	auto dialogueSubsystem = world->GetSubsystem<UDialogueSubsystem>();
	if (dialogueSubsystem != nullptr)
	{
		dialogueSubsystem->ChangeDialogueByNPCName(NPCName, newDialogueTable);
	}
}
