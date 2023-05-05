// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RGSaveGame.generated.h"

class UHighScoreEntry;

UCLASS()
class RUNNINGGAME_API URGSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TArray<FString> MinutesList;

	UPROPERTY()
	TArray<FString> SecondsList;

	UPROPERTY()
	TArray<float> TimeList;
};
