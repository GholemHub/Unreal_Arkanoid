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
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere)
		UInputAction* MovementInputAction;
	UPROPERTY(EditAnywhere, Category = Border)
		float BorderLimit = 1200;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Move(const FInputActionValue& Value);
	void MoveLeft(APawn* Pawn, float Speed);
	void MoveRight(APawn* Pawn, float Speed);
		
};
