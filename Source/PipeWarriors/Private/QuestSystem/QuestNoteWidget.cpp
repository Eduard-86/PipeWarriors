// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestNoteWidget.h"
#include "Components/TextBlock.h"

void UQuestNoteWidget::UpdateText(FText newText)
{
	NoteText->SetText(newText);
}
