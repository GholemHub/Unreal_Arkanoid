// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/ARK_EnemyPawn.h"
#include "Ball/ARK_BallActor.h"
// Sets default values
AARK_EnemyPawn::AARK_EnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARK_EnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARK_EnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARK_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AARK_EnemyPawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	if (Other && Other->IsA(AARK_BallActor::StaticClass()))
	{
		Destroy();
	}
}

