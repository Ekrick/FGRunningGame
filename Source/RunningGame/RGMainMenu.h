
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGMainMenu.generated.h"

class UHighScoreList;
class UHighScoreEntry;
UCLASS()
class RUNNINGGAME_API ARGMainMenu : public AActor
{
	GENERATED_BODY()
	
public:		
	ARGMainMenu();

private:
	TObjectPtr<UHighScoreList> ScoreList;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	FString PrintScores();

};
