// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RGGameMode.generated.h"


UCLASS()
class RUNNINGGAME_API ARGGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:

protected:
	virtual void BeginPlay() override;

public:

};
