// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/GameStatisticsDataWidget.h"
#include "Components/TextBlock.h"

#include "Kismet/GameplayStatics.h"
#include "ARK_GameModeBase.h"

int UGameStatisticsDataWidget::GetCountOfBlocks() const 
{
		return ReturnValue();
}

int UGameStatisticsDataWidget::ReturnValue() const
{
	auto CurrentGameMode = Cast<AARK_GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return CurrentGameMode->EmenyCountFloat;
}
