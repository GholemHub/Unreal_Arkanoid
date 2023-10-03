// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "ARK_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class ARKANOID_API AARK_PlayerController : public APlayerController
{
	GENERATED_BODY()
		
protected:
	UPROPERTY(EditAnywhere, Category = Input)
		UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* MovementInputAction;
	virtual void SetupInputComponent() override;
	void Move(const FInputActionValue& Value);
};
