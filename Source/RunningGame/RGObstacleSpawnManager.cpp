// Fill out your copyright notice in the Description page of Project Settings.


#include "RGObstacleSpawnManager.h"
#include "Components/StaticMeshComponent.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnableObstacle.h"


ARGObstacleSpawnManager::ARGObstacleSpawnManager()
{
	PrimaryActorTick.bCanEverTick = true;
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectMesh->SetupAttachment(GetRootComponent());
}

void ARGObstacleSpawnManager::BeginPlay()
{
	Super::BeginPlay();

	f_currentTimer = FMath::FRandRange(TimerMin, TimerMax);

}

void ARGObstacleSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARGObstacleSpawnManager::SpawnTimer(DeltaTime);
	ARGObstacleSpawnManager::ProjectilePooler();
	ARGObstacleSpawnManager::ZigZag(DeltaTime);
}


void ARGObstacleSpawnManager::ZigZag(float Deltatime)
{
	float minPos = 200.0f;
	float maxPos = 1000.0f;

	FVector ActorPosition = this->GetActorLocation();

	if (ActorPosition.Y >= maxPos || ActorPosition.Y <= minPos)
	{
		MoveSpeed *= -1;
	}

	ActorPosition.Y += MoveSpeed * Deltatime;

	SetActorLocation(ActorPosition);
}

void ARGObstacleSpawnManager::ProjectilePooler()
{
	if (b_canSpawn)
	{
		if (ProjectileArray.IsEmpty())
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			ProjectileArray.Add(newprojectile);
		}
		else if (ProjectileArray.Num() < ProjectileCount)
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			ProjectileArray.Add(newprojectile);
		}
		else
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> pooledprojectile = ProjectileArray[0];
			if (pooledprojectile->GetActorLocation().X < 0)
			{
				FVector spawnpoint = this->GetActorLocation();
				spawnpoint.X -= 100.f;
				pooledprojectile->SetActorLocation(spawnpoint);
				ProjectileArray.RemoveSingle(pooledprojectile);
				ProjectileArray.Add(pooledprojectile);
			}
		}
	}
}

TObjectPtr<ARGSpawnableObstacle> ARGObstacleSpawnManager::SpawnObject()
{
	FVector spawnpoint = this->GetActorLocation();
	spawnpoint.X -= 100.f;
	TObjectPtr<ARGSpawnableObstacle> spawnobject = GetWorld()->SpawnActor<ARGSpawnableObstacle>(SpawnedObject, spawnpoint, FRotator::ZeroRotator);
	return spawnobject;
}

void ARGObstacleSpawnManager::SpawnTimer(float dt)
{
	if (!b_canSpawn)
	{
		if (f_currentTimer >= 0)
		{
			f_currentTimer -= dt;
		}
		else
		{
			b_canSpawn = true;
			f_currentTimer = FMath::FRandRange(TimerMin, TimerMax);
		}
	}
}



