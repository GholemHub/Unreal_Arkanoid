// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARK_BallActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class ARKANOID_API AARK_BallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARK_BallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxSpeed)
		float MaxSpeed = 500;

	UFUNCTION()
		virtual void NotifyHit(
			UPrimitiveComponent* MyComp,
			AActor* Other,
			UPrimitiveComponent* OtherComp,
			bool bSelfMoved,
			FVector HitLocation,
			FVector HitNormal,
			FVector NormalImpulse,
			const FHitResult& Hit
		) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
