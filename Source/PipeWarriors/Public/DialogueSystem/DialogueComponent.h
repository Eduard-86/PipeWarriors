// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "DialogueComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDialogueSystem, Log, All);

class UDialogueWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIPEWARRIORS_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDialogueComponent();

	UFUNCTION(BlueprintCallable)
	void UpdateDialogueState(FString newState);

	UFUNCTION(BlueprintCallable)
	void StartDialogue();

	UFUNCTION(BlueprintCallable)
	void EndDialogue();

	UFUNCTION()
	bool CheckName(FText name);
	UFUNCTION()
	void SetNewTable(UDataTable* newTable);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	UDataTable* DialogueTable;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FText NPCName;

	UPROPERTY()
	FString LastRow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "NPC")
	TSubclassOf<UDialogueWidget> DialogueWidgetClass;

	UPROPERTY()
	UDialogueWidget* DialogueWidget;

	TArray<FString> ParseOptions(const FString& Options, const FString& Separator = TEXT("|"));
};
