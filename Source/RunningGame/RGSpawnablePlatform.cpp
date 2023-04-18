// Fill out your copyright notice in the Description page of Project Settings.


#include "RGSpawnablePlatform.h"

ARGSpawnablePlatform::ARGSpawnablePlatform()
{
	SideMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SideMesh1"));
	SideMesh1->SetupAttachment(ARGSpawnableObjectBase::GetMesh());

	SideMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SideMesh2"));
	SideMesh2->SetupAttachment(ARGSpawnableObjectBase::GetMesh());

	static FName MeshCollisionProfileName(TEXT("Platform"));
	ARGSpawnableObjectBase::ObjectMesh->SetCollisionProfileName(MeshCollisionProfileName);
	SideMesh1->SetCollisionProfileName(MeshCollisionProfileName);
	SideMesh2->SetCollisionProfileName(MeshCollisionProfileName);
}