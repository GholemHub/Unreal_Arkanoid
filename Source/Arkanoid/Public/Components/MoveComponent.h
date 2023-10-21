// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "InputActionValue.h"

#include "MoveComponent.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOID_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMoveComponent();
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Replicated)
		UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, Replicated)
		UInputAction* MovementInputAction;
	UPROPERTY(EditAnywhere, Category = Border)
		float BorderLimit = 1200;

	

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
public:	


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	/*UFUNCTION(Server, Reliable, WithValidation)
	void Server_Move(const FInputActionValue& Value);

	UFUNCTION(Client, Reliable, WithValidation)
	void Client_Move(const FInputActionValue& Value);*/

	void Move(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable, WithValidation)
	void MoveL(const FInputActionValue& Value);

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_MoveL(const FInputActionValue& Value);

	UPROPERTY(Replicated)
		FVector ReplicatedLocation;

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_UpdateLocation(FVector NewLocation);

	/*void MoveLeft(APawn* Pawn, float Speed);
	void MoveRight(APawn* Pawn, float Speed);*/
};
