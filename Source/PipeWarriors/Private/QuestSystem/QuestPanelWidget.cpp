// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestPanelWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "QuestSystem/QuestSettings.h"
#include "QuestSystem/QuestNoteWidget.h"

void UQuestPanelWidget::AddQuestNote(FText description)
{
	//const UQuestSettings* settings = GetDefault<UQuestSettings>();
	//auto note = CreateWidget<UQuestNoteWidget>(GetOwningPlayer(), settings->QuestNoteWidgetClass);
	//note->UpdateText(description);
	//QuestsBox->AddChildToVerticalBox(note);
}

void UQuestPanelWidget::DeleteQuestNote(int32 noteIndex)
{
	//auto note = QuestsBox->GetChildAt(noteIndex);
	//note->MarkAsGarbage();
	//note->RemoveFromParent();
}
