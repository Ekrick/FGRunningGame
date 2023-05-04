// Fill out your copyright notice in the Description page of Project Settings.


#include "RGCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RGPlayerController.h"
//#include "Camera/CameraComponent.h"
//#include "Components/InputComponent.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "GameFramework/Controller.h"
//#include "GameFramework/SpringArmComponent.h"
//#include "EnhancedInputComponent.h"
//#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ARGCharacter::ARGCharacter()
{

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PlayerCapsule"));
	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);
	SetRootComponent(CapsuleComponent);

	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->TargetArmLength = 500.0f;
	//CameraBoom->bUsePawnControlRotation = false;

	//FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	//FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//FollowCamera->bUsePawnControlRotation = false;

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetRootComponent());
	static FName MeshCollisionProfileName(TEXT("PlayerMesh"));
	PlayerMesh->SetCollisionProfileName(MeshCollisionProfileName);
}

// Called when the game starts or when spawned
void ARGCharacter::BeginPlay()
{
	Super::BeginPlay();

	//if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	//	{
	//		Subsystem->AddMappingContext(MappingContext, 0);
	//	}
	//}
	
	m_health = 3;
}

void ARGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CharacterGravity();
	OutOfBounds();
}

void ARGCharacter::PlayerHit()
{
	m_health --;
	UKismetSystemLibrary::PrintString(this, "hit", true, true, FLinearColor::Red, 2.f);
	CheckDeath();
}

void ARGCharacter::CheckDeath()
{
	if (m_health <= 0)
	{
		TObjectPtr<ARGPlayerController> playerpawn = Cast<ARGPlayerController>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (playerpawn)
		{
			playerpawn->SaveScore();
			UKismetSystemLibrary::PrintString(this, "dead", true, true, FLinearColor::Red, 2.f);
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
	}
}

void ARGCharacter::CharacterGravity()
{
	FVector startposition = this->GetActorLocation();
	startposition.Z -= 100.f;
	FVector endposition = startposition - FVector(0.f, 0.f, 5.f);

	FHitResult hitresult;
	FCollisionQueryParams collisionparams;

	bool b_hit = GetWorld()->LineTraceSingleByChannel(hitresult, startposition, endposition, ECC_Visibility, collisionparams);

	if (!b_hit)
	{
		FVector pos = this->GetActorLocation();
		pos.Z -= 5.f;
		this->SetActorLocation(pos);
	}
}

void ARGCharacter::OutOfBounds()
{
	if (this->GetActorLocation().Z < -200)
	{
		UKismetSystemLibrary::PrintString(this, "dead", true, true, FLinearColor::Red, 2.f);
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}


//void ARGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
//	{
//		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARGCharacter::Move);
//
//		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
//		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
//	}
//}
//
//
//void ARGCharacter::Move(const FInputActionValue& Value)
//{
//	float MovementValue = Value.Get<float>();
//
//	if (Controller != nullptr)
//	{
//		const FVector PlayerRight = GetActorRightVector();
//
//		AddMovementInput(PlayerRight, MovementValue);
//	}
//}
