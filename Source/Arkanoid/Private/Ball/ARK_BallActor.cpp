
// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/StaticMeshComponent.h"

#include "Player/ARK_Player_Pawn.h"
#include "Ball/ARK_BallActor.h"

// Sets default values
AARK_BallActor::AARK_BallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

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
    
    // Check if the ball has collided with a wall

    

    if (Other)// && Other->IsA(AARK_Player_Pawn::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Ball collided with a wall! :: %s"), *Other->GetName());
        
        auto CurrentVelocity = MeshComponent->GetComponentVelocity();
        auto Vecolity = CurrentVelocity.Size();
        if (Vecolity > MaxSpeed)
        {
            FVector ScaledVelocity = CurrentVelocity.GetSafeNormal() * MaxSpeed;
            MeshComponent->SetPhysicsLinearVelocity(ScaledVelocity);
        }
    }
}

// Called every frame
void AARK_BallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    //MeshComponent->SetPhysicsLinearVelocity(GetActorTransform().GetLocation());
    
    
}

