// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGSpawnableObjectBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class RUNNINGGAME_API ARGSpawnableObjectBase : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ARGSpawnableObjectBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> ObjectMesh;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float MoveSpeed;

	void MoveObject(float DeltaTime);

public:	

	TObjectPtr<UStaticMeshComponent> GetMesh();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
