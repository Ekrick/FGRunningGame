// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HighScoreList.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAME_API UHighScoreList : public UObject
{
	GENERATED_BODY()

private:
	TArray<float> Scores;

public:
	UPROPERTY(EditAnywhere, Category = "HighScores")
		int HighScoreCount = 5;

	UFUNCTION(BlueprintCallable, Category = "HighScores")
		static float LoadScores();

	UFUNCTION(BlueprintCallable, Category = "HighScores")
		void AddScore(float score);
};
