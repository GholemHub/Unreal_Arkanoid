// Fill out your copyright notice in the Description page of Project Settings.


#include "Envirement/ARK_TriggerBox.h"
#include "Ball/ARK_BallActor.h"

AARK_TriggerBox::AARK_TriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AARK_TriggerBox::OnOverlapBegin);
}

void AARK_TriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	OtherActor->SetActorLocation(FVector(300.f, 0.f, 40.f));

	auto Rotation = OtherActor->GetActorRotation();
	auto NewRotation = FRotator(Rotation.Pitch, Rotation.Yaw, Rotation.Roll);
	bool bTeleportPhysics = true;
		OtherActor->SetActorRotation(NewRotation);
	
	auto CastedActor = Cast<AARK_BallActor>(OtherActor);

	CastedActor->MeshComponent->AddImpulse(GetActorForwardVector() * 2000, NAME_None, true);
}
