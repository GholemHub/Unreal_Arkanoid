// Fill out your copyright notice in the Description page of Project Settings.

#include "ARK_GameModeBase.h"
#include "UI/GameStatisticsDataWidget.h"

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
    EmenyCountFloat = SpawnedActors.Num();
    UE_LOG(LogTemp, Warning, TEXT("111111::%d"), EmenyCountFloat)//here i dont have a real count of arr
}

//void AARK_GameModeBase::RemoveEnemy(AActor* Actor)
//{
//    if (SpawnedActors.Num() > 0)
//    {
//        AARK_EnemyPawn* EnemyToRemove = Cast<AARK_EnemyPawn>(Actor);
//        
//        SpawnedActors.Remove(EnemyToRemove);
//        EnemyToRemove->Destroy();
//        EmenyCountFloat = SpawnedActors.Num();
//        UE_LOG(LogTemp, Warning, TEXT("EmenyCount3 ___ %i"), EmenyCountFloat);
//
//       
//    }
//}

void AARK_GameModeBase::RemoveEnemy(AActor* Actor)
{
    if (SpawnedActors.Contains(Actor))
    {
        // Cast Actor to AARK_EnemyPawn if it's not null
        AARK_EnemyPawn* EnemyToRemove = Cast<AARK_EnemyPawn>(Actor);

        if (EnemyToRemove)
        {
            // Destroy the actor
            EnemyToRemove->Destroy();

            // Remove it from the SpawnedActors array
            SpawnedActors.Remove(EnemyToRemove);

            // Update the EmenyCountFloat
            EmenyCountFloat = SpawnedActors.Num();
            UE_LOG(LogTemp, Warning, TEXT("EmenyCount3 ___ %i"), EmenyCountFloat);

            // After updating the count, you can call the UI update function if needed
            UGameStatisticsDataWidget* StatisticsWidget; // Declare a variable to store the reference

            // Inside a function where you want to create and store the reference
            StatisticsWidget = CreateWidget<UGameStatisticsDataWidget>(GetWorld(), widgetBlackLines); // Replace YourWidgetClass with the actual class of your widget

            if (StatisticsWidget)
            {
                StatisticsWidget->GetCountOfBlocks();
            }
        }
    }
}
