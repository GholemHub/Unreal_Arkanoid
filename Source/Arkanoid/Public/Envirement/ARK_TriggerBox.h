// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ARK_TriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AARK_TriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	AARK_TriggerBox();
protected:
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
};
