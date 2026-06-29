#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DialogueStructs.generated.h"

USTRUCT(BlueprintType)
struct FDialogueRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString textType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText text;

	// Например: 1|2|3;  5|8
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString nextTextOptions;
};