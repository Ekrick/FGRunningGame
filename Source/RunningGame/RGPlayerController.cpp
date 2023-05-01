

#include "RGPlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "RGCharacter.h"

ARGPlayerController::ARGPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;


}

void ARGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SpawnPlayers();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

}

void ARGPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}



void ARGPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction_1, ETriggerEvent::Triggered, this, &ARGPlayerController::Move_1);

		EnhancedInputComponent->BindAction(MoveAction_2, ETriggerEvent::Triggered, this, &ARGPlayerController::Move_2);

	}
}


void ARGPlayerController::Move_1(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();

	if (Controller != nullptr)
	{
		FVector position = Player1->GetActorLocation();
		position.Y += MovementValue * MovementSpeed;
		Player1->SetActorLocation(position);
	}
}

void ARGPlayerController::Move_2(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();

	if (Controller != nullptr)
	{
		FVector position = Player2->GetActorLocation();
		position.Y += MovementValue * MovementSpeed;
		Player2->SetActorLocation(position);
	}
}

void ARGPlayerController::SpawnPlayers()
{
	Player1 = GetWorld()->SpawnActor<ARGCharacter>(SpawnedCharacter_1, Spawn1, FRotator::ZeroRotator);

	Player2 = GetWorld()->SpawnActor<ARGCharacter>(SpawnedCharacter_2, Spawn2, FRotator::ZeroRotator);
}
