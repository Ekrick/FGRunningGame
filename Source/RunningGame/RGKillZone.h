// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGKillZone.generated.h"

class UBoxComponent;

UCLASS()
class RUNNINGGAME_API ARGKillZone : public AActor
{
	GENERATED_BODY()

	

public:	
	// Sets default values for this actor's properties
	ARGKillZone();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> TriggerArea;

	UFUNCTION()
	void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
