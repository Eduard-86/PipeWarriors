// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueWidget.h"
#include "DialogueSystem/DialogueStructs.h"
#include "DialogueSystem/DialogueAnswer.h"
#include "DialogueSystem/DialogueComponent.h"

#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UDialogueWidget::SetupDialogueData(FDialogueRow& dialogue)
{
	DialogueRow = dialogue;

	NPCBlock->SetText(DialogueRow.text);

}

void UDialogueWidget::AttachDialogueComponent(UDialogueComponent* dialogueComp)
{
	DialogueComponent = dialogueComp;
}



void UDialogueWidget::AddAnswer(FDialogueRow& answer)
{
	UDialogueAnswer* answerWidget = CreateWidget<UDialogueAnswer>(GetOwningPlayer(), DialogueAnswerClass);
	answerWidget->SetupDialogueRow(answer);
	answerWidget->AttachDialogueComponent(DialogueComponent);
	AnswersBox->AddChildToVerticalBox(answerWidget);
}

void UDialogueWidget::ClearAnswers()
{
	AnswersBox->ClearChildren();
}

void UDialogueWidget::NativeConstruct()
{
	APlayerController* playerController = GetOwningPlayer();
	if (playerController)
	{
		FInputModeUIOnly InputMode;
		InputMode.SetWidgetToFocus(TakeWidget());
		playerController->SetInputMode(InputMode);
		playerController->bShowMouseCursor = true;
	}
}
void UDialogueWidget::NativeDestruct()
{
	APlayerController* playerController = GetOwningPlayer();
	if (playerController)
	{
		FInputModeGameOnly InputMode;
		playerController->SetInputMode(InputMode);
		playerController->bShowMouseCursor = false;
	}
}

FReply UDialogueWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Enter)
	{
		DialogueComponent->EndDialogue();
	}
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}
