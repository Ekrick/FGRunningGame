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

private:
	bool b_active = true;
	bool b_pastplayer = false;

	void CheckPassed();
	
protected:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> CollisionArea;

	
	void ResetToLocation(FVector position);

	bool GetActive() { return b_active; }

	bool GetPassed() { return b_pastplayer; }

	UFUNCTION()
		void Disappear();

	UFUNCTION()
		void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
