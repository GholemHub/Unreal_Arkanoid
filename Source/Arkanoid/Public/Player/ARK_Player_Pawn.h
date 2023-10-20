#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Components/MoveComponent.h"

#include "ARK_Player_Pawn.generated.h"

class UInputMappingContext;
class UInputAction;
class UMoveComponent;

UCLASS()
class ARKANOID_API AARK_Player_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARK_Player_Pawn();

protected:
	UPROPERTY(EditAnywhere, Category = Input)
		UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* MovementInputAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UMoveComponent* MoveComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CubeMeshComponent;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};