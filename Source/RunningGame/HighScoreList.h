// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HighScoreList.generated.h"

class UHighScoreEntry;

UCLASS()
class RUNNINGGAME_API UHighScoreList : public UObject
{
	GENERATED_BODY()

public:
	UHighScoreList();

private:
	FString F_FilePath;

	TArray<TObjectPtr<UHighScoreEntry>> Scores;
	

public:
	UPROPERTY(EditAnywhere, Category = "HighScores")
		int HighScoreCount = 5;

	TObjectPtr<UHighScoreEntry> NewEntry(float time, FString minutes, FString seconds);

	void AddScore(TObjectPtr<UHighScoreEntry> entry);

	TArray<TObjectPtr<UHighScoreEntry>> GetScoreList() { return Scores; }
	
	void SaveScores();

	void LoadScores();
};
