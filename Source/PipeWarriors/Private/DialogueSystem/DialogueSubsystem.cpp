// Fill out your copyright notice in the Description page of Project Settings.
#include "DialogueSystem/DialogueSubsystem.h"

#include "DialogueSystem/DialogueComponent.h"
#include "EngineUtils.h"

void UDialogueSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	UE_LOG(LogDialogueSystem, Log, TEXT("Dialogue subsystem started..."));

	for (TActorIterator<AActor> It(&InWorld); It; ++It)
	{
		AActor* actor = *It;
		if (actor && actor->GetComponentByClass(UDialogueComponent::StaticClass()))
		{
			actorsWithDialogue.AddUnique(actor);
		}
	}

	int32 actorCount = actorsWithDialogue.Num();
	UE_LOG(LogDialogueSystem, Log, TEXT("Count of actors with dialogue :  %d"), actorCount);

}

void UDialogueSubsystem::ChangeDialogueByNPCName(FText NPCName, UDataTable* newDialogue)
{
	for (auto actor : actorsWithDialogue)
	{
		auto dialogueComp = actor->GetComponentByClass<UDialogueComponent>();
		if (dialogueComp->CheckName(NPCName))
		{
			dialogueComp->SetNewTable(newDialogue);
			break;
		}
	}
}
