// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGSpawnerBase.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnableObstacle.h"
#include "RGObstacleSpawnManager.generated.h"

class ARGSpawnableObstacle;
class UStaticMeshComponent;

UCLASS()
class RUNNINGGAME_API ARGObstacleSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:
	ARGObstacleSpawnManager();



private:

	//spawn variables
	bool b_canSpawn = true;

	float f_currentTimer;


	TArray<TObjectPtr<ARGSpawnableObstacle>> ProjectileArray;


public:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<ARGSpawnableObstacle>SpawnedObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	TObjectPtr<UStaticMeshComponent> ObjectMesh;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float MoveSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float TimerMax = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float TimerMin = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	int ProjectileCount = 5;

private:
	TObjectPtr<ARGSpawnableObstacle> SpawnObject();

	void ProjectilePooler();

	void SpawnTimer(float Deltatime);

	void ZigZag(float Deltatime);

public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
