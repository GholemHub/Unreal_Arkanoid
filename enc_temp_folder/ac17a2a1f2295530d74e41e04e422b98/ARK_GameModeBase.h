// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemy/ARK_EnemyPawn.h"
#include "ARK_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AARK_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AARK_GameModeBase();
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AARK_EnemyPawn> EnemyClassToSpawn;

	UPROPERTY(VisibleAnywhere, Category = "Spawning")
	TArray<AARK_EnemyPawn* > SpawnedActors;

};
