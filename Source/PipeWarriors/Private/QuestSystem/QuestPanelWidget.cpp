// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestPanelWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

void UQuestPanelWidget::AddQuestNote(FText description)
{
	auto note = NewObject<UTextBlock>(this);
	note->SetText(description);
	QuestsBox->AddChildToVerticalBox(note);
}

void UQuestPanelWidget::UpdateQuestNote(int32 noteIndex, FText description)
{
	auto note = Cast<UTextBlock>(QuestsBox->GetChildAt(noteIndex));
	note->SetText(description);

}

void UQuestPanelWidget::DeleteQuestNote(int32 noteIndex)
{
	auto note = QuestsBox->GetChildAt(noteIndex);
	note->MarkAsGarbage();

	QuestsBox->RemoveChildAt(noteIndex);
}
