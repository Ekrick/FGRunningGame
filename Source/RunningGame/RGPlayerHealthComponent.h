// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RGPlayerHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNNINGGAME_API URGPlayerHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URGPlayerHealthComponent();

private:
	int m_health;

protected:
	virtual void BeginPlay() override;

public:	

	void TakeDamage();

	int GetHealth() { return m_health; }

		
};
