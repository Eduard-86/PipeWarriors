// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueComponent.h"
#include "DialogueSystem/DialogueWidget.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"

DEFINE_LOG_CATEGORY(LogDialogueSystem);

UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDialogueComponent::UpdateDialogueState(FString newState)
{
	UE_LOG(LogDialogueSystem, Log, TEXT("Update dialogue to row: %s"), *newState);

	if (newState.IsEmpty() || !DialogueTable)
	{
		EndDialogue();
		return;
	}

	LastRow = newState;
	FDialogueRow* row = DialogueTable->FindRow<FDialogueRow>(FName(*LastRow), TEXT("DialogueSystem"));

	if (row != nullptr)
	{
		if (!row->TriggerAsset.IsNull())
		{
			row->TriggerAsset.LoadSynchronous();
			row->TriggerAsset->TriggerAction(GetWorld());
		}

		DialogueWidget->SetupDialogueData(*row);
		DialogueWidget->SetNPCName(NPC_Name);
		DialogueWidget->SetNPCPortrait(NPC_Portrait);
		DialogueWidget->ClearAnswers();

		for (auto& option : ParseOptions(row->nextTextOptions))
		{
			DialogueWidget->AddAnswer(*DialogueTable->FindRow<FDialogueRow>(FName(*option), TEXT("DialogueSystem")));
		}
	}
	else
	{
		UE_LOG(LogDialogueSystem, Error, TEXT("Invalid dialogue row: %s"), *newState);
		EndDialogue();
	}

}

void UDialogueComponent::StartDialogue()
{
	UE_LOG(LogDialogueSystem, Log, TEXT("Dialogue was started"));
	LastRow = "START";

	if (DialogueTable == nullptr)
	{
		EndDialogue();
		return;
	}
		

	checkf(DialogueWidgetClass != nullptr, TEXT("Dialogue widget class in blueprint defaults is null"))

	auto controller = GetWorld()->GetFirstPlayerController();
	if (controller != nullptr)
	{
		DialogStartDelegate.Broadcast(this);

		DialogueWidget = CreateWidget<UDialogueWidget>(controller, DialogueWidgetClass);
		DialogueWidget->AddToViewport(0);
		DialogueWidget->AttachDialogueComponent(this);

		UpdateDialogueState(LastRow);
	}
}

void UDialogueComponent::EndDialogue()
{
	UE_LOG(LogDialogueSystem, Log, TEXT("Dialogue was ended"));

	DialogEndDelegate.Broadcast(this);

	if (DialogueWidget)
	{
		DialogueWidget->RemoveFromParent();
		DialogueWidget = nullptr;
	}
}

bool UDialogueComponent::CheckName(FString name)
{
	return SystemCharacterName == name;
}

void UDialogueComponent::SetNewTable(UDataTable* newTable)
{
	DialogueTable = newTable;
}

TArray<FString> UDialogueComponent::ParseOptions(const FString& Options, const FString& Separator)
{
	TArray<FString> ParsedOptions;
	Options.ParseIntoArray(ParsedOptions, *Separator, true);
	return ParsedOptions;
}

