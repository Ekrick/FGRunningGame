// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HighScoreEntry.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAME_API UHighScoreEntry : public UObject
{
	GENERATED_BODY()

private:
    FString S_Minutes = "";
    FString S_Seconds = "";
    float F_Time = 0.f;
	
public:
	UFUNCTION(BlueprintCallable)
	FString GetMin() { return S_Minutes; }
	UFUNCTION(BlueprintCallable)
	FString GetSec() { return S_Seconds; }
	UFUNCTION(BlueprintCallable)
	float GetTime() { return F_Time; }

	void SetMin(FString in_string) { S_Minutes = in_string; }
	void SetSec(FString in_string) { S_Seconds = in_string; }
	void SetTime(float in_float) { F_Time = in_float; }

    void Serialize(FArchive& Archive);
};
