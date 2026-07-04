// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueSystem/DialogueStructs.h"

#include "DialogueAnswer.generated.h"


class UTextBlock;
class UButton;
class UDialogueComponent;

UCLASS(Abstract)
class PIPEWARRIORS_API UDialogueAnswer : public UUserWidget
{
	GENERATED_BODY()

public:
	
protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* AnswerButton;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* AnswerTextBlock;

	UPROPERTY()
	FDialogueRow DialogueRow;

	UPROPERTY()
	UDialogueComponent* DialogueComponent;

	UFUNCTION()
	void ProcessAnswerSelection();

	virtual void NativeConstruct() override;


public:
	UFUNCTION()
	void SetupDialogueRow(FDialogueRow& row);

	UFUNCTION()
	void AttachDialogueComponent(UDialogueComponent* dialogueComp);
};
