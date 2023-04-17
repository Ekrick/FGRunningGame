// Fill out your copyright notice in the Description page of Project Settings.


#include "RGSpawnableObjectBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARGSpawnableObjectBase::ARGSpawnableObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectMesh->SetupAttachment(GetRootComponent());
	static FName MeshCollisionProfileName(TEXT("ObjectMesh"));
	ObjectMesh->SetCollisionProfileName(MeshCollisionProfileName);
}

// Called when the game starts or when spawned
void ARGSpawnableObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

TObjectPtr<UStaticMeshComponent> ARGSpawnableObjectBase::GetMesh()
{
	return ObjectMesh;
}

// Called every frame
void ARGSpawnableObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ARGSpawnableObjectBase::MoveObject(DeltaTime);

}

void ARGSpawnableObjectBase::MoveObject(float DeltaTime)
{
	FVector ActorPosition = this->GetActorLocation();

	ActorPosition.X -= MoveSpeed * DeltaTime;

	SetActorLocation(ActorPosition);
}

