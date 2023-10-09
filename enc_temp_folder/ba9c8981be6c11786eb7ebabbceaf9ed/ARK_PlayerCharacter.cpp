// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ARK_PlayerCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"




// Sets default values
AARK_PlayerCharacter::AARK_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARK_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}

}

void AARK_PlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Error, TEXT("Location :: %f"), MovementVector.Y);
	

	if (GetActorLocation().X >= -970.f)
	{
		const FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, MovementVector.Y);
	}
	else if (MovementVector.Y > 0)
	{
		const FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, MovementVector.Y);
	}

	const FVector Right = GetActorRightVector();
	AddMovementInput(Right, MovementVector.X);

}

// Called every frame
void AARK_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARK_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementInputAction, ETriggerEvent::Triggered, this, &AARK_PlayerCharacter::Move);
	}//Casting to Enhanced
	

}

