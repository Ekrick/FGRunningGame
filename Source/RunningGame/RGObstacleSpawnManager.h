// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RGSpawnerBase.h"
#include "RGSpawnableObjectBase.h"
#include "RGObstacleSpawnManager.generated.h"

/**
 * 
 */

class UStaticMeshComponent;

UCLASS()
class RUNNINGGAME_API ARGObstacleSpawnManager : public ARGSpawnerBase
{
	GENERATED_BODY()
	
public:
	ARGObstacleSpawnManager();



private:

	//spawn variables
	bool b_canSpawn = true;

	float f_currentTimer = 0;

	float f_interval;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	TObjectPtr<UStaticMeshComponent> ObjectMesh;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float MoveSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float f_timerMax = 3.0f;

private:
	virtual void SpawnObject() override;

	void SpawnTimer(float Deltatime);

	void ZigZag(float Deltatime);

public:

	virtual void Tick(float DeltaTime) override;
};
