// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGSpawnableObstacle.h"
#include "RGSpawnerBase.generated.h"



UCLASS()
class RUNNINGGAME_API ARGSpawnerBase : public AActor
{
	GENERATED_BODY()

public:
	ARGSpawnerBase();

private:

	//spawn variables
	bool b_canSpawn = true;

	float f_currentTimer;


	TArray<TObjectPtr<ARGSpawnableObstacle>> PoolArray;


public:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
		TSubclassOf<ARGSpawnableObstacle>SpawnedObject;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float TimerMax = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float TimerMin = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
		int ProjectileCount = 5;

private:
	TObjectPtr<ARGSpawnableObstacle> SpawnObject();

	void ProjectilePooler();

	void RandomDespawns();

	void DespawnActive();

	void SpawnTimer(float Deltatime);


public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
