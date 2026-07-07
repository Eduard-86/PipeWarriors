#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "DialogueStructs.generated.h"

class UOnLevelTriggerDataAsset;

USTRUCT(BlueprintType)
struct FDialogueRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString textType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText text;

	// Разделитель   " | "
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString nextTextOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UOnLevelTriggerDataAsset> TriggerAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DialogTrigger;
};