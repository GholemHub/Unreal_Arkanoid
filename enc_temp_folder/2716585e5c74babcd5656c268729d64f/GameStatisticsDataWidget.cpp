// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameStatisticsDataWidget.h"
#include "Components/TextBlock.h"

#include "Kismet/GameplayStatics.h"
#include "ARK_GameModeBase.h"

int UGameStatisticsDataWidget::GetCountOfBlocks() const 
{
	auto CurrentGameMode = Cast<AARK_GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
		auto Count = CurrentGameMode->EmenyCountFloat;
		//CountOfBlocksTextBlock->SetText(FText::AsNumber(Count));
		UE_LOG(LogTemp, Warning, TEXT("!!!!!!!!!!!!!::%d, %i"), Count, CurrentGameMode->EmenyCountFloat);
		return ReturnValue();
}

int UGameStatisticsDataWidget::ReturnValue()const
{
	auto CurrentGameMode = Cast<AARK_GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	return CurrentGameMode->EmenyCountFloat;
}
