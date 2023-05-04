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

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString S_Minutes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString S_Seconds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float F_Time;
	
    void Serialize(FArchive& Archive);
};
