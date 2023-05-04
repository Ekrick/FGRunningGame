

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
	ARGSpawnerBase::RandomDespawns();
	ARGSpawnerBase::DifficultyScaling(DeltaTime);
}


void ARGSpawnerBase::ProjectilePooler()
{
	if (b_canSpawn)
	{
		if (PoolArray.IsEmpty())
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			newprojectile->SetSpeed(f_speed);
			PoolArray.Add(newprojectile);
		}
		else if (PoolArray.Num() < ProjectileCount)
		{
			b_canSpawn = false;
			TObjectPtr<ARGSpawnableObstacle> newprojectile = SpawnObject();
			newprojectile->SetSpeed(f_speed);
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
				pooledprojectile->ResetToLocation(spawnpoint);
				pooledprojectile->SetSpeed(f_speed);
				PoolArray.RemoveSingle(pooledprojectile);
				PoolArray.Add(pooledprojectile);
			}
		}
	}
}

void ARGSpawnerBase::RandomDespawns()
{
	for (int i = 0; i < PoolArray.Num(); i++)
	{
		TObjectPtr<ARGSpawnableObstacle> obstacle = PoolArray[i];
		if (obstacle->GetActive() && obstacle->GetPassed())
		{
			obstacle->Disappear();
			DespawnActive();
			break;
		}
	}
}

void ARGSpawnerBase::DespawnActive()
{
	int roll = FMath::RandRange(1, 4);
	if (roll > 1)
		return;
	for (int i = 0; i < PoolArray.Num(); i++)
	{
		TObjectPtr<ARGSpawnableObstacle> obstacle = PoolArray[i];
		if (obstacle->GetActive() && !obstacle->GetPassed())
		{
			obstacle->Disappear();
			return;
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

void ARGSpawnerBase::DifficultyScaling(float Deltatime)
{
	f_difficulty += Deltatime;
	if (f_difficulty >= 10)
	{
		f_difficulty = 0;
		i_difficulty += 1;
	}

	f_speed = 2000 + (i_difficulty * 100);


	TimerMin = 1 / FMath::Sqrt(i_difficulty + 1);
	TimerMax = TimerMin + 1.f;

	if (i_difficulty > 12)
	{
		TimerMin = 0.25f;
		TimerMax = 0.1f;
	}
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

