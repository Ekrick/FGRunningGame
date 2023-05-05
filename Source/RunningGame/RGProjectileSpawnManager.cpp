// Fill out your copyright notice in the Description page of Project Settings.


#include "RGProjectileSpawnManager.h"
ARGProjectileSpawnManager::ARGProjectileSpawnManager()
{
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectMesh->SetupAttachment(GetRootComponent());
}

void ARGProjectileSpawnManager::BeginPlay()
{
	Super::BeginPlay();

	speed = MoveSpeed;
}

void ARGProjectileSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARGProjectileSpawnManager::ZigZag(DeltaTime);
}

void ARGProjectileSpawnManager::ZigZag(float Deltatime)
{
	float minPos = 200.0f;
	float maxPos = 1000.0f;

	FVector ActorPosition = this->GetActorLocation();

	if (ActorPosition.Y >= maxPos)
	{
		speed = -MoveSpeed;
	}
	else if (ActorPosition.Y <= minPos)
	{
		speed = MoveSpeed;
	}

	ActorPosition.Y += speed * Deltatime;

	SetActorLocation(ActorPosition);
}
