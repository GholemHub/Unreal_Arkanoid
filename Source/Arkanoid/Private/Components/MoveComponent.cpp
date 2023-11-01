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



// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	
		GetOwner()->SetReplicates(true);
		GetOwner()->SetReplicateMovement(true);
}

void UMoveComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMoveComponent, ReplicatedLocation);
}

// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//auto Owner = GetOwner();
	//UE_LOG(LogTemp, Error, TEXT("Owner->GetActorLocation().Y1  :: %f"), Owner->GetActorLocation().Y);
	/*if (Owner != nullptr)
	{
		if (Owner->GetActorLocation().Y <= -BorderLimit)
		{
			Owner->SetActorLocation(FVector(0.f, -BorderLimit, 0.0f));
		}
		if (Owner->GetActorLocation().Y >= BorderLimit)
		{
			Owner->SetActorLocation(FVector(0.f, BorderLimit, 0.0f));
		}
	}*/
}

//bool UMoveComponent::Server_Move_Validate(const FInputActionValue& Value)
//{
//	return true;
//}
//
//void UMoveComponent::Server_Move_Implementation(const FInputActionValue& Value)
//{
//	const FVector2D MovementVector = Value.Get<FVector2D>();
//
//	auto Owner = GetOwner();
//	if (Owner != nullptr)
//	{
//		if (APawn* OwningPawn = Cast<APawn>(Owner))
//		{
//			if (MovementVector.X <= 0.0)
//			{
//				//UE_LOG(LogTemp, Error, TEXT("Location1 :: %f :: %f"), MovementVector.Y, MovementVector.X);
//				MoveLeft(OwningPawn, MovementVector.X);
//			}
//			else {
//				//UE_LOG(LogTemp, Error, TEXT("Location2 :: %f :: %f"), MovementVector.Y, MovementVector.X);
//				MoveRight(OwningPawn, MovementVector.X);
//			}
//		}
//	}
//}
//
//bool UMoveComponent::Client_Move_Validate(const FInputActionValue& Value)
//{
//	return true;
//}
//
//void UMoveComponent::Client_Move_Implementation(const FInputActionValue& Value)
//{
//	
//}


void UMoveComponent::Move(const FInputActionValue& Value)
{

	const FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Error, TEXT("Value :: %f :: %f"), MovementVector.Y, MovementVector.X)
		if (GetNetMode() == NM_DedicatedServer) {
			return;
		}
	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		UpdateServerLocation(MovementVector.X, MovementVector.Y);
	}
	else {
		UpdateServerLocation(MovementVector.X, MovementVector.Y);
	}

	

	//if (GetOwner()->HasAuthority())
	//{
	//	//MoveL(Value);  // Server performs movement
	//	const FVector2D MovementVector = Value.Get<FVector2D>();
	//	UE_LOG(LogTemp, Error, TEXT("Server:: %f"), MovementVector.X)



	//		//Server_UpdateLocation_Implementation(GetOwner()->GetActorLocation());
	//}
	//else
	//{
	//	//Client_MoveL(Value);  // Client performs movement
	//	const FVector2D MovementVector = Value.Get<FVector2D>();
	//	UE_LOG(LogTemp, Error, TEXT("Client2:: %f"), MovementVector.X)
	//		//Server_UpdateLocation_Implementation(GetOwner()->GetActorLocation());
	//}
}

void UMoveComponent::UpdateServerLocation_Implementation(float X, float Y)
{
	
		auto Owner = GetOwner();
	if (Owner != nullptr)
	{
		if (APawn* OwningPawn = Cast<APawn>(Owner))
		{
			if (X <= 0.0)
			{
				if (GetOwner()->HasAuthority()) {

				
				//UE_LOG(LogTemp, Error, TEXT("Location Server :: %f :: %f"), MovementVector.Y, MovementVector.X)
				FVector LocalOffset(0.f, X * 100, 0.0f);
				Owner->AddActorLocalOffset(LocalOffset);
				}
				// Update the replicated location on the server
				//Server_UpdateLocation_Implementation(Owner->GetActorLocation());
				}
			else 
				{
					//UE_LOG(LogTemp, Error, TEXT("Location Client :: %f :: %f"), MovementVector.Y, MovementVector.X)
						FVector LocalOffset(0.f, X * 100, 0.0f);

					ReplicatedLocation = Owner->GetActorLocation();

					Owner->AddActorLocalOffset(LocalOffset);
					//Server_UpdateLocation_Implementation(Owner->GetActorLocation());
			}
		}
	}
}



void UMoveComponent::Client_MoveL_Implementation(const FInputActionValue& Value)
{
	
}

void UMoveComponent::Server_UpdateLocation_Implementation(FVector NewLocation)
{
	UE_LOG(LogTemp, Error, TEXT("NewLocation1 %f :: %f"), NewLocation.Y, NewLocation.X)
	ReplicatedLocation = NewLocation;
	UE_LOG(LogTemp, Error, TEXT("ReplicatedLocation1 %f :: %f"), ReplicatedLocation.Y, ReplicatedLocation.X)
}

void UMoveComponent::MoveL_Implementation(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Error, TEXT("The Location 111 :: %f :: %f"), MovementVector.Y, MovementVector.X)
	auto Owner = GetOwner();
	if (Owner != nullptr)
	{
		if (APawn* OwningPawn = Cast<APawn>(Owner))
		{
			if (MovementVector.X <= 0.0)
			{
					if (Owner->HasAuthority()) {
						UE_LOG(LogTemp, Error, TEXT("Location Server :: %f :: %f"), MovementVector.Y, MovementVector.X)
						FVector LocalOffset(0.f, MovementVector.X * 100, 0.0f);
						Owner->AddActorLocalOffset(LocalOffset);
						
						// Update the replicated location on the server
						Server_UpdateLocation_Implementation(Owner->GetActorLocation());
					}
					else {
						UE_LOG(LogTemp, Error, TEXT("Location Client :: %f :: %f"), MovementVector.Y, MovementVector.X)
						FVector LocalOffset(0.f, MovementVector.X * 100, 0.0f);
						
						ReplicatedLocation = Owner->GetActorLocation();
						
						Owner->AddActorLocalOffset(LocalOffset);
						Server_UpdateLocation_Implementation(Owner->GetActorLocation());
					}
			}
			else {
				//UE_LOG(LogTemp, Error, TEXT("Location2 :: %f :: %f"), MovementVector.Y, MovementVector.X);
				FVector LocalOffset(0.f, MovementVector.X * 100, 0.0f);
				Owner->AddActorLocalOffset(LocalOffset);
			}
		}
	}
}

//void UMoveComponent::MoveLeft(APawn* Pawn, float Speed)
//{
//	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
//	UE_LOG(LogTemp, Error, TEXT("NewPosition :: %f :: %f"), NewPosition.X, Speed);
//	if (NewPosition.Y >= -1300)
//	{
//		UE_LOG(LogTemp, Error, TEXT("NewPosition2 :: %f :: %f"), NewPosition.X, Speed);
//		FVector LocalOffset(0.f, Speed * 100, 0.0f);
//		Pawn->AddActorLocalOffset(LocalOffset);
//
//	}
//}
//
//void UMoveComponent::MoveRight(APawn* Pawn, float Speed)
//{
//	FVector NewPosition = Pawn->GetActorLocation() + FVector(0, Speed, 0);
//	if (NewPosition.Y <= 1300)
//	{
//		FVector LocalOffset(0.f, Speed * 100, 0.0f);
//		Pawn->AddActorLocalOffset(LocalOffset);
//	}
//}