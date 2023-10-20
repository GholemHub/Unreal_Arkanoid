// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MoveComponent.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMoveComponent, InputMappingContext);
	DOREPLIFETIME(UMoveComponent, MovementInputAction);
}

// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	
		GetOwner()->SetReplicates(true);
		GetOwner()->SetReplicateMovement(true);
	
}

// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	auto Owner = GetOwner();
	//UE_LOG(LogTemp, Error, TEXT("Owner->GetActorLocation().Y1  :: %f"), Owner->GetActorLocation().Y);
	if (Owner != nullptr)
	{
		if (Owner->GetActorLocation().Y <= -BorderLimit)
		{
			Owner->SetActorLocation(FVector(0.f, -BorderLimit, 0.0f));
		}
		if (Owner->GetActorLocation().Y >= BorderLimit)
		{	
			Owner->SetActorLocation(FVector(0.f, BorderLimit, 0.0f));	
		}
	}
}

bool UMoveComponent::Server_Move_Validate(const FInputActionValue& Value)
{
	return true;
}

void UMoveComponent::Server_Move_Implementation(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	auto Owner = GetOwner();
	if (Owner != nullptr)
	{
		if (APawn* OwningPawn = Cast<APawn>(Owner))
		{
			if (MovementVector.X <= 0.0)
			{
				//UE_LOG(LogTemp, Error, TEXT("Location1 :: %f :: %f"), MovementVector.Y, MovementVector.X);
					MoveLeft(OwningPawn, MovementVector.X);
			}
			else {
				//UE_LOG(LogTemp, Error, TEXT("Location2 :: %f :: %f"), MovementVector.Y, MovementVector.X);
				MoveRight(OwningPawn, MovementVector.X);
			}		
		}
	}
}

bool UMoveComponent::Client_Move_Validate(const FInputActionValue& Value)
{
	return true;
}

void UMoveComponent::Client_Move_Implementation(const FInputActionValue& Value)
{

	
	const FVector2D MovementVector = Value.Get<FVector2D>();

	auto Owner = GetOwner();
	if (Owner != nullptr)
	{
		if (APawn* OwningPawn = Cast<APawn>(Owner))
		{
			if (MovementVector.X <= 0.0)
			{
				//UE_LOG(LogTemp, Error, TEXT("Location1 :: %f :: %f"), MovementVector.Y, MovementVector.X)
				MoveLeft(OwningPawn, MovementVector.X);
			}
			else {
				//UE_LOG(LogTemp, Error, TEXT("Location2 :: %f :: %f"), MovementVector.Y, MovementVector.X);
				MoveRight(OwningPawn, MovementVector.X);
			}
		}
	}
}


void UMoveComponent::Move(const FInputActionValue& Value)
{
	if (GetOwner()->HasAuthority())
	{
		Server_Move(Value);
	}
	else
	{
		Client_Move(Value);
	}
	
}

void UMoveComponent::MoveLeft(APawn* Pawn, float Speed)
{
	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
	UE_LOG(LogTemp, Error, TEXT("NewPosition :: %f :: %f"), NewPosition.X, Speed);
	if (NewPosition.Y >= -1300)
	{
		UE_LOG(LogTemp, Error, TEXT("NewPosition2 :: %f :: %f"), NewPosition.X, Speed);
		FVector LocalOffset(0.f, Speed * 100, 0.0f);
		Pawn->AddActorLocalOffset(LocalOffset);	

	}
}

void UMoveComponent::MoveRight(APawn* Pawn, float Speed)
{
	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
	if (NewPosition.Y <= 1300)
	{
		FVector LocalOffset(0.f, Speed * 100, 0.0f);
		Pawn->AddActorLocalOffset(LocalOffset);
	}
}