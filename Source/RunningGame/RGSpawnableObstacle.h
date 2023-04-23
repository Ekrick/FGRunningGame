// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnableObstacle.generated.h"

class UBoxComponent;

UCLASS()
class RUNNINGGAME_API ARGSpawnableObstacle : public ARGSpawnableObjectBase
{
	GENERATED_BODY()
public:
	ARGSpawnableObstacle();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> CollisionArea;

	UFUNCTION()
	void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
