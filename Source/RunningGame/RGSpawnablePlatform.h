// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RGSpawnableObjectBase.h"
#include "RGSpawnablePlatform.generated.h"

/**
 * 
 */
class UStaticMeshComponent;

UCLASS()
class RUNNINGGAME_API ARGSpawnablePlatform : public ARGSpawnableObjectBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SideMesh1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SideMesh2;

public:
	ARGSpawnablePlatform();

};
