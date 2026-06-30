// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueComponent.h"
#include "DialogueSystem/DialogueWidget.h"

DEFINE_LOG_CATEGORY(LogDialogueSystem);

UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDialogueComponent::UpdateDialogueState(FString newState)
{
	LastRow = newState;
	FName rowName = FName(*LastRow);
	FDialogueRow* row = DialogueTable->FindRow<FDialogueRow>(rowName, TEXT("DialogueSystem"));

	if (row != nullptr)
	{
		DialogueWidget->SetupDialogueData(*row);
		DialogueWidget->ClearAnswers();

		// Установка вариантов ответа
		TArray<FString> ParsedOptions;
		FString Options = row->nextTextOptions;
		Options.ParseIntoArray(ParsedOptions, TEXT("|"), true);

		for (auto& option : ParsedOptions)
		{
			FName AnswerName = FName(*option);
			DialogueWidget->AddAnswer(*DialogueTable->FindRow<FDialogueRow>(AnswerName, TEXT("DialogueSystem")));
		}
	}
	else
	{
		EndDialogue();
	}

}

void UDialogueComponent::StartDialogue()
{
	LastRow = "START";

	if (DialogueWidgetClass == nullptr)
	{
		UE_LOG(LogDialogueSystem, Error, TEXT("Dialogue widget class in blueprint defauts is null"));
	}
	else
	{
		APlayerController* playerController = GetWorld()->GetFirstPlayerController();
		if (playerController)
		{
			DialogueWidget = CreateWidget<UDialogueWidget>(playerController, DialogueWidgetClass);
			DialogueWidget->AddToViewport(0);
			DialogueWidget->AttachDialogueComponent(this);

			UpdateDialogueState(LastRow);
		}
	}
}

void UDialogueComponent::EndDialogue()
{
	if (DialogueWidget)
	{
		DialogueWidget->RemoveFromParent();
		DialogueWidget = nullptr;
	}
}

