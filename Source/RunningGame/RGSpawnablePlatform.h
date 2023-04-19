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

public:
	ARGSpawnablePlatform();
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SideMesh1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SideMesh2;

	void Recycle();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float Boundary = -100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float RecycleDistance = 10000.0f;

	virtual void Tick(float DeltaTime) override;

};
