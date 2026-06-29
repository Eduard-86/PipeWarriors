// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueComponent.h"
#include "DialogueSystem/DialogueWidget.h"

UDialogueComponent::UDialogueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDialogueComponent::UpdateDialogueState(FString newState)
{
	if (newState == "END")
		EndDialogue();

	LastRow = newState;
	FName rowName = FName(*LastRow);
	FDialogueRow* currentRow = DialogueTable->FindRow<FDialogueRow>(rowName, TEXT("DialogueSystem"));

	if (currentRow != nullptr)
	{
		DialogueWidget->SetupDialogueData(*currentRow);
		DialogueWidget->ClearAnswers();

		// Установка вариантов ответа
		TArray<FString> ParsedOptions;
		FString Options = currentRow->nextTextOptions;
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
	if (DialogueWidgetClass)
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

