

#include "RGMainMenu.h"
#include "HighScoreList.h"
#include "HighScoreEntry.h"

ARGMainMenu::ARGMainMenu()
{

}

void ARGMainMenu::BeginPlay()
{
	Super::BeginPlay();
	ScoreList = NewObject<UHighScoreList>();
	ScoreList->LoadScores();

	TObjectPtr<APlayerController> controller = GetWorld()->GetFirstPlayerController();
	controller->SetInputMode(FInputModeUIOnly());
	controller->bShowMouseCursor = true;
}

FString ARGMainMenu::PrintScores()
{
	FString outString = "";
	TArray<TObjectPtr<UHighScoreEntry>> Scores = ScoreList->GetScoreList();

	for (int16 i = 0; i < Scores.Num(); i++)
	{
		TObjectPtr<UHighScoreEntry> score = Scores[i];
		outString += score->GetMin();
		outString += ":";
		outString += score->GetSec();
		outString += "\n";
	}
	return outString;
}

