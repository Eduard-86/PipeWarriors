// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "DialogueComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDialogueSystem, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStartDialog, UDialogueComponent*, DialogComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEndDialog, UDialogueComponent*, DialogComponent);


class UDialogueWidget;
class UTexture2D;

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
	bool CheckName(FString name);
	UFUNCTION()
	void SetNewTable(UDataTable* newTable);
public:

	UPROPERTY(BlueprintAssignable)
	FStartDialog DialogStartDelegate;

	UPROPERTY(BlueprintAssignable)
	FEndDialog DialogEndDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	UDataTable* DialogueTable;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FText NPC_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FString SystemCharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	UTexture2D* NPC_Portrait;

	UPROPERTY()
	FString LastRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	TSubclassOf<UDialogueWidget> DialogueWidgetClass;

	UPROPERTY()
	UDialogueWidget* DialogueWidget;

	TArray<FString> ParseOptions(const FString& Options, const FString& Separator = TEXT("|"));
};
