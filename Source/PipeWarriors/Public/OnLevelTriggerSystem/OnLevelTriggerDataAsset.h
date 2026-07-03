// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OnLevelTriggerDataAsset.generated.h"

UCLASS(Abstract)
class PIPEWARRIORS_API UOnLevelTriggerDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
	FText TriggerName;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TriggerAction(UWorld* world);

	virtual void TriggerAction_Implementation(UWorld* world);

	UFUNCTION(BlueprintCallable)
	bool isNameValid(FText name);
};
