// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueSystem/DialogueStructs.h"
#include "DialogueWidget.generated.h"

class UImage;
class UTextBlock;
class UVerticalBox;
class UDataTable;
class UDialogueAnswer;
class UDialogueComponent;

UCLASS(Abstract)
class PIPEWARRIORS_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* NPCImage;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* NPCBlock;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVerticalBox* AnswersBox;

	UPROPERTY()
	FDialogueRow  DialogueRow;
	UPROPERTY()
	UDialogueComponent* DialogueComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UDialogueAnswer> DialogueAnswerClass;

public:
	UFUNCTION()
	void SetupDialogueData(FDialogueRow& dialogue);

	UFUNCTION()
	void AttachDialogueComponent(UDialogueComponent* dialogueComp);

	UFUNCTION()
	void AddAnswer(FDialogueRow& answer);

	UFUNCTION()
	void ClearAnswers();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
};
