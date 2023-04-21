// Fill out your copyright notice in the Description page of Project Settings.


#include "RGSpawnableObstacle.h"
#include "RGCharacter.h"
#include "RGPlayerHealthComponent.h"

void ARGSpawnableObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ARGCharacter::StaticClass()))
	{

	}
}