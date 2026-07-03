// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"

bool UOnLevelTriggerDataAsset::isNameValid(FText name)
{
	return TriggerName.IdenticalTo(name);
}
void UOnLevelTriggerDataAsset::TriggerAction_Implementation(UWorld* world) { }

