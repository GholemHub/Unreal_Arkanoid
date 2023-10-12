// Fill out your copyright notice in the Description page of Project Settings.

#include "ARK_GameModeBase.h"

AARK_GameModeBase::AARK_GameModeBase()
{
    FVector LocationOfNewEnemy = FVector::ZeroVector;
    UE_LOG(LogTemp, Warning, TEXT("Add the spawned actor to the array1"));
    for (int32 i = 0; i < 5; i++)
    {
        UE_LOG(LogTemp, Warning, TEXT("Add the spawned actor to the array2"));
        if (EnemyClassToSpawn)
        {
            UE_LOG(LogTemp, Warning, TEXT("Add the spawned actor to the array3"));
            FActorSpawnParameters SpawnParams;
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
            
            LocationOfNewEnemy.X += (i + 100);
            auto SpawnedActor = GetWorld()->SpawnActor<AARK_EnemyPawn>(EnemyClassToSpawn, LocationOfNewEnemy, FRotator::ZeroRotator, SpawnParams);

            if (SpawnedActor)
            {
                // Add the spawned actor to the array
                UE_LOG(LogTemp, Warning, TEXT("Add the spawned actor to the array"));
                SpawnedActors.Add(SpawnedActor);
            }
        }
    }
}
