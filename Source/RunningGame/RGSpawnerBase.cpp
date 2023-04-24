

#include "RGSpawnerBase.h"
#include "RGSpawnableObstacle.h"


ARGSpawnerBase::ARGSpawnerBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARGSpawnerBase::BeginPlay()
{
	Super::BeginPlay();

	f_currentTimer = FMath::FRandRange(TimerMin, TimerMax);
}
	
void ARGSpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARGSpawnerBase::SpawnTimer(DeltaTime);
	ARGSpawnerBase::ProjectilePooler();
}


void ARGSpawnerBase::ProjectilePooler()
{
	if (b_canSpawn)
	{
		if (PoolArray.IsEmpty())
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			PoolArray.Add(newprojectile);
		}
		else if (PoolArray.Num() < ProjectileCount)
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			PoolArray.Add(newprojectile);
		}
		else
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> pooledprojectile = PoolArray[0];
			if (pooledprojectile->GetActorLocation().X < 0)
			{
				FVector spawnpoint = this->GetActorLocation();
				spawnpoint.X -= 100.f;
				pooledprojectile->SetActorLocation(spawnpoint);
				PoolArray.RemoveSingle(pooledprojectile);
				PoolArray.Add(pooledprojectile);
			}
		}
	}
}

TObjectPtr<ARGSpawnableObstacle> ARGSpawnerBase::SpawnObject()
{
	FVector spawnpoint = this->GetActorLocation();
	spawnpoint.X -= 100.f;
	TObjectPtr<ARGSpawnableObstacle> spawnobject = GetWorld()->SpawnActor<ARGSpawnableObstacle>(SpawnedObject, spawnpoint, FRotator::ZeroRotator);
	return spawnobject;
}

void ARGSpawnerBase::SpawnTimer(float dt)
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

