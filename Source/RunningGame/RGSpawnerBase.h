// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnerBase.generated.h"

UCLASS()
class RUNNINGGAME_API ARGSpawnerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARGSpawnerBase();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARGSpawnableObjectBase>SpawnedObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SpawnObject();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
