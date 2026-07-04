// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DialogueSubsystem.generated.h"

class UDialogueComponent;

UCLASS()
class PIPEWARRIORS_API UDialogueSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	TArray<AActor*> actorsWithDialogue;
public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UFUNCTION(BlueprintCallable)
	void ChangeDialogueByNPCName(FString NPCName, UDataTable* newDialogue);
};
