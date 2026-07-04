// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestNoteWidget.generated.h"

class UTextBlock;

UCLASS()
class PIPEWARRIORS_API UQuestNoteWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* NoteText;

	UFUNCTION()
	void UpdateText(FText newText);
};
