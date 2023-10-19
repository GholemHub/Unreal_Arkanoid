// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameStatisticsDataWidget.generated.h"

/**
 * 
 */
class UTextBlock;

UCLASS()
class ARKANOID_API UGameStatisticsDataWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		int GetCountOfBlocks() const;

	int ReturnValue()const;
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CountOfBlocksTextBlock;
};
