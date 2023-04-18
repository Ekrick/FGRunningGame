// Fill out your copyright notice in the Description page of Project Settings.


#include "RGObstacleSpawnManager.h"
#include "Components/StaticMeshComponent.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnableObstacle.h"


ARGObstacleSpawnManager::ARGObstacleSpawnManager()
{
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectMesh->SetupAttachment(GetRootComponent());
}

void ARGObstacleSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARGObstacleSpawnManager::SpawnTimer(DeltaTime);
	ARGObstacleSpawnManager::SpawnObject();
	ARGObstacleSpawnManager::ZigZag(DeltaTime);
}


void ARGObstacleSpawnManager::ZigZag(float Deltatime)
{
	float minPos = 100.0f;
	float maxPos = 1100.0f;

	FVector ActorPosition = this->GetActorLocation();

	if (ActorPosition.Y >= maxPos || ActorPosition.Y <= minPos)
	{
		MoveSpeed *= -1;
	}

	ActorPosition.Y += MoveSpeed * Deltatime;

	SetActorLocation(ActorPosition);
}

void ARGObstacleSpawnManager::SpawnObject()
{
	if (b_canSpawn)
	{
	FVector SpawnPoint = this->GetActorLocation();
	GetWorld()->SpawnActor<ARGSpawnableObjectBase>(ARGSpawnerBase::SpawnedObject, SpawnPoint, FRotator::ZeroRotator);
	b_canSpawn = false;
	}
}

void ARGObstacleSpawnManager::SpawnTimer(float dt)
{
	if (!b_canSpawn)
	{
		if (f_currentTimer <= f_timerMax)
		{
			f_currentTimer += dt;
		}
		else
		{
			b_canSpawn = true;
			f_currentTimer = 0;
		}
	}
}



