// Fill out your copyright notice in the Description page of Project Settings.


#include "RGSpawnableObstacle.h"
#include "Components/BoxComponent.h"
#include "RGCharacter.h"

ARGSpawnableObstacle::ARGSpawnableObstacle()
{
	CollisionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionArea"));
	SetRootComponent(CollisionArea);
	ObjectMesh->SetupAttachment(CollisionArea);
	CollisionArea->OnComponentBeginOverlap.AddDynamic(this, &ARGSpawnableObstacle::OnBeginOverlap);

}

void ARGSpawnableObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckPassed();
}

void ARGSpawnableObstacle::CheckPassed()
{
	if (this->GetActorLocation().X < 100)
	{
		b_pastplayer = true;
	}
}

void ARGSpawnableObstacle::Disappear()
{
	this->AddActorWorldOffset(FVector(0, 0, -1000.f));
	b_active = false;
}

void ARGSpawnableObstacle::ResetToLocation(FVector position)
{
	this->SetActorLocation(position);
	b_active = true;
	b_pastplayer = false;

}

void ARGSpawnableObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TObjectPtr<ARGCharacter> player = Cast<ARGCharacter>(OtherActor);
	if (player)
	{
		Disappear();
		player->PlayerHit();	
	}
}