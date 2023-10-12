// Fill out your copyright notice in the Description page of Project Settings.

#include "ARK_GameModeBase.h"

void AARK_GameModeBase::BeginPlay()
{
    FVector LocationOfNewEnemy = FVector(1200.f,0.f,0.f);
    for (int32 i = 0; i < EnemyCount; i++)
    {
        for (int32 j = 0; j < EnemyCount; j++)
        {
            if (EnemyClassToSpawn)
            {
                FActorSpawnParameters SpawnParams;
                SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
 
                LocationOfNewEnemy.Y += (j + 220);
                auto SpawnedActor = GetWorld()->SpawnActor<AARK_EnemyPawn>(EnemyClassToSpawn, LocationOfNewEnemy, FRotator::ZeroRotator, SpawnParams);

                if (SpawnedActor)
                {
                    SpawnedActors.Add(SpawnedActor);
                }
            }
        }
        LocationOfNewEnemy.Y = 0;
        LocationOfNewEnemy.X += (i + 120);  
    }
}
