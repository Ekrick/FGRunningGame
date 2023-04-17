// Fill out your copyright notice in the Description page of Project Settings.


#include "RGKillZone.h"
#include "Components/BoxComponent.h"

// Sets default values
ARGKillZone::ARGKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerArea = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerArea"));
	SetRootComponent(TriggerArea);
	TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &ARGKillZone::OnBeginOverlap);

}

// Called when the game starts or when spawned
void ARGKillZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARGKillZone::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}


// Called every frame
void ARGKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


