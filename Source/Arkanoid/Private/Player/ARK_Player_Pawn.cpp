// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ARK_Player_Pawn.h"

// Sets default values
AARK_Player_Pawn::AARK_Player_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARK_Player_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARK_Player_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARK_Player_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

