// Fill out your copyright notice in the Description page of Project Settings.


#include "TEST/TEST_PlatformActor.h"

// Sets default values
ATEST_PlatformActor::ATEST_PlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATEST_PlatformActor::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	
}

// Called every frame
void ATEST_PlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		Location += FVector(50 * DeltaTime, 0, 0);
		SetActorLocation(Location);
	}
}

