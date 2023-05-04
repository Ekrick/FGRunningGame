

#include "RGMainMenu.h"
#include "HighScoreList.h"

ARGMainMenu::ARGMainMenu()
{

}

void ARGMainMenu::BeginPlay()
{
	Super::BeginPlay();
	ScoreList = NewObject<UHighScoreList>();
	ScoreList->LoadScores();
	Scores = ScoreList->GetScoreList();
}


