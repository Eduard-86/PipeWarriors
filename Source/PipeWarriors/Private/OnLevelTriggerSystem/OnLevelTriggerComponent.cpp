// Fill out your copyright notice in the Description page of Project Settings.

#include "OnLevelTriggerSystem/OnLevelTriggerComponent.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"

UOnLevelTriggerComponent::UOnLevelTriggerComponent() : Super()
{
}

void UOnLevelTriggerComponent::ActivateAllTriggers()
{
	for (auto trigger : triggers)
	{
		trigger->TriggerAction();
	}
}

void UOnLevelTriggerComponent::ActivateTriggerByName(FText name)
{
	for (auto trigger : triggers)
	{
		if (trigger->isNameValid(name))
		{
			trigger->TriggerAction();
			break;
		}
	}
}