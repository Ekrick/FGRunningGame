// Fill out your copyright notice in the Description page of Project Settings.


#include "RGSpawnableObstacle.h"
#include "Components/BoxComponent.h"
#include "RGCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

ARGSpawnableObstacle::ARGSpawnableObstacle()
{
	CollisionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionArea"));
	SetRootComponent(CollisionArea);
	ObjectMesh->SetupAttachment(CollisionArea);
	CollisionArea->OnComponentBeginOverlap.AddDynamic(this, &ARGSpawnableObstacle::OnBeginOverlap);

}

void ARGSpawnableObstacle::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UKismetSystemLibrary::PrintString(this, "hit", true, true, FLinearColor::Red, 2.f);
	TObjectPtr<ARGCharacter> player = Cast<ARGCharacter>(OtherActor);
	if (player)
	{

		UKismetSystemLibrary::PrintString(this, "player hit", true, true, FLinearColor::Red, 2.f);
		player->PlayerHit();
		
	}
}