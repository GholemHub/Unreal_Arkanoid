// Fill out your copyright notice in the Description page of Project Settings.
#include "Ball/ARK_BallActor.h"
#include "Components/StaticMeshComponent.h"

#include "Enemy/ARK_EnemyPawn.h"
#include "Player/ARK_Player_Pawn.h"

#include "Math/UnrealMathUtility.h"

// Sets default values
AARK_BallActor::AARK_BallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

    MeshComponent->SetNotifyRigidBodyCollision(true);
}

void AARK_BallActor::RespawnActor()
{
    FVector Location = FVector(300.f, 0.f, 0.f);
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    GetWorld()->SpawnActor<AARK_BallActor>(AARK_BallActor::StaticClass(), Location, FRotator::ZeroRotator, SpawnParams);
}

// Called when the game starts or when spawned
void AARK_BallActor::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComponent->AddImpulse(GetActorForwardVector() * 1000, NAME_None, true);
}
void AARK_BallActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
    FVector ImpulseDirection = FVector::ZeroVector;
    if (Other && Other->IsA(AARK_Player_Pawn::StaticClass()))
    {
        // Determine the position of the hit relative to the platform's center
        FVector PlatformCenter = Other->GetActorLocation();
        float HitPositionY = HitLocation.Y - PlatformCenter.Y;

        if (HitPositionY > 0)
        {
            ImpulseDirection = FVector(0.0f, HitPositionY / 10, 0.0f);
        }
        else
        {
            ImpulseDirection = FVector(0.0f, HitPositionY / 10, 0.0f);
        }

        // Apply the impulse without changing velocity
        FVector NewVelocity = MeshComponent->GetComponentVelocity() + ImpulseDirection * 50;

        NewVelocity = NewVelocity.GetSafeNormal() * MaxSpeed;

        MeshComponent->SetPhysicsLinearVelocity(NewVelocity);
    }

    if (Other)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ball collided with a wall! :: %s"), *Other->GetName());
        // Apply the impulse without changing velocity
        FVector NewVelocity = MeshComponent->GetComponentVelocity();

        NewVelocity = NewVelocity.GetSafeNormal() * MaxSpeed;

        MeshComponent->SetPhysicsLinearVelocity(NewVelocity);
    }
}


// Called every frame
void AARK_BallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

