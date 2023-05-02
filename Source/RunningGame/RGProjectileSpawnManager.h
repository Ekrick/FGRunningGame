// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RGSpawnerBase.h"
#include "RGProjectileSpawnManager.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAME_API ARGProjectileSpawnManager : public ARGSpawnerBase
{
	GENERATED_BODY()

public:
	ARGProjectileSpawnManager();

private:
	float speed;

	void ZigZag(float Deltatime);


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		TObjectPtr<UStaticMeshComponent> ObjectMesh;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float MoveSpeed = 500.0f;
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
