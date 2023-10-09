// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MoveComponent.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	UE_LOG(LogTemp, Error, TEXT("Location2"));

}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMoveComponent::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	//UE_LOG(LogTemp, Error, TEXT("Location :: %f :: %f"), MovementVector.Y, MovementVector.X );
	auto Owner = GetOwner();
	if (Owner != nullptr)
	{
		// Check if the owning actor is a pawn
		if (APawn* OwningPawn = Cast<APawn>(Owner))
		{

			if (MovementVector.X <= 0.0)
			{
				UE_LOG(LogTemp, Error, TEXT("Location1  :: %f"), MovementVector.X);
				MoveLeft(OwningPawn, MovementVector.X);
			}
			else {
				UE_LOG(LogTemp, Error, TEXT("Location2  :: %f"), MovementVector.X);
				MoveRight(OwningPawn, MovementVector.X);
			}			
		}
	}
}

void UMoveComponent::MoveLeft(APawn* Pawn, float Speed)
{
	
	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
	UE_LOG(LogTemp, Error, TEXT("NewPosition :: %f :: %f"), NewPosition.X, Speed);
	if (NewPosition.Y >= -1300)
	{
		// Move the platform to the right
		//Pawn->SetActorLocation(NewPosition);
		UE_LOG(LogTemp, Error, TEXT("NewPosition :: %f :: %f"), NewPosition.X, Speed);
		FVector LocalOffset(0.f, Speed * 100, 0.0f);
		Pawn->AddActorLocalOffset(LocalOffset);

	}
}

void UMoveComponent::MoveRight(APawn* Pawn, float Speed)
{
	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
	if (NewPosition.Y <= 1300)
	{
		// Move the platform to the right
		//Pawn->SetActorLocation(NewPosition);
		UE_LOG(LogTemp, Error, TEXT("NewPosition :: %f :: %f"), NewPosition.X, Speed);
		FVector LocalOffset(0.f, Speed * 100, 0.0f);
		Pawn->AddActorLocalOffset(LocalOffset);

	}
}

