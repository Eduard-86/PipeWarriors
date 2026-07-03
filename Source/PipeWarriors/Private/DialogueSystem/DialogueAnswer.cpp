// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueAnswer.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "DialogueSystem/DialogueComponent.h"
#include "OnLevelTriggerSystem/OnLevelTriggerDataAsset.h"

void UDialogueAnswer::ProcessAnswerSelection()
{
	if (!DialogueRow.TriggerAsset.IsNull())
	{
		DialogueRow.TriggerAsset.LoadSynchronous();
		DialogueRow.TriggerAsset->TriggerAction(GetWorld());
	}

	DialogueComponent->UpdateDialogueState(DialogueRow.nextTextOptions);
}

void UDialogueAnswer::NativeConstruct()
{
	Super::NativeConstruct();

	if (AnswerButton)
	{
		AnswerButton->OnClicked.AddDynamic(this, &UDialogueAnswer::ProcessAnswerSelection);
	}
}

void UDialogueAnswer::SetupDialogueRow(FDialogueRow& row)
{
	DialogueRow = row;
	AnswerTextBlock->SetText(DialogueRow.text);
}

void UDialogueAnswer::AttachDialogueComponent(UDialogueComponent* dialogueComp)
{
	DialogueComponent = dialogueComp;
}