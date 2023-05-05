// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"
#include "RGCharacter.generated.h"


class UCapsuleComponent;
class UStaticMeshComponent;


UCLASS()
class RUNNINGGAME_API ARGCharacter : public AActor
{
	GENERATED_BODY()

private:

	int m_health;

public:
	ARGCharacter();

protected:
	virtual void BeginPlay() override;

public:

	int GetHealth() { return m_health; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	TObjectPtr<UStaticMeshComponent> PlayerMesh;


	void PlayerHit();

	void PlayerDeath();
	
	void CharacterGravity();

	void OutOfBounds();

	virtual void Tick(float DeltaTime) override;


};
