
#include "Player/ARK_Player_Pawn.h"

#include "Components/MoveComponent.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
// Sets default values
AARK_Player_Pawn::AARK_Player_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MoveComponent = CreateDefaultSubobject<UMoveComponent>(TEXT("MoveComponent"));
}

// Called when the game starts or when spawned
void AARK_Player_Pawn::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
			UE_LOG(LogTemp, Error, TEXT("Location1"));
		}
	}
}

// Called every frame
void AARK_Player_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARK_Player_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(MoveComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementInputAction, ETriggerEvent::Triggered, MoveComponent, &UMoveComponent::Move);
		UE_LOG(LogTemp, Error, TEXT("Location"));
	}//Casting to Enhanced
}