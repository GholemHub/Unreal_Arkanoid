// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ARK_PlayerController.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AARK_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MovementInputAction, ETriggerEvent::Triggered, this, &AARK_PlayerController::Move);
	}//Casting to Enhanced

}

void AARK_PlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	const FVector Forward = GetPawn()->GetActorForwardVector();
	GetPawn()->AddMovementInput(Forward, MovementVector.Y);
	const FVector Right = GetPawn()->GetActorRightVector();
	GetPawn()->AddMovementInput(Right, MovementVector.X);

}