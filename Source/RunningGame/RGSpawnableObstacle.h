// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnableObstacle.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAME_API ARGSpawnableObstacle : public ARGSpawnableObjectBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
