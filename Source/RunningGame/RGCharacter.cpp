// Fill out your copyright notice in the Description page of Project Settings.


#include "RGCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RGPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"



ARGCharacter::ARGCharacter()
{


	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PlayerCapsule"));

	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);
	SetRootComponent(CapsuleComponent);


	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetRootComponent());
	static FName MeshCollisionProfileName(TEXT("PlayerMesh"));
	PlayerMesh->SetCollisionProfileName(MeshCollisionProfileName);
}


void ARGCharacter::BeginPlay()
{
	Super::BeginPlay();


	
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
	if (m_health <= 0)
	{
		PlayerDeath();
	}
}

void ARGCharacter::PlayerDeath()
{
	TObjectPtr<ARGPlayerController> playerpawn = Cast<ARGPlayerController>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (playerpawn)
	{
		playerpawn->SaveScore();
		UKismetSystemLibrary::PrintString(this, "dead", true, true, FLinearColor::Red, 2.f);
		UGameplayStatics::OpenLevel(GetWorld(), FName("BP_MainMenu"), true);
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
		PlayerDeath();
	}
}

