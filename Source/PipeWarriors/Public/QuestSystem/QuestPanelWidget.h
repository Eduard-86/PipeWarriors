// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestPanelWidget.generated.h"

class UTextBlock;
class UVerticalBox;

UCLASS()
class PIPEWARRIORS_API UQuestPanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* MainText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* QuestsBox;

	UFUNCTION(BlueprintCallable)
	void AddQuestNote(FText description);
	UFUNCTION(BlueprintCallable)
	void UpdateQuestNote(int32 noteIndex, FText description);
	UFUNCTION(BlueprintCallable)
	void DeleteQuestNote(int32 noteIndex);
};
