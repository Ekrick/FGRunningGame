// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreList.h"
#include "HighScoreEntry.h"
#include "RGSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
//#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
//#include "Serialization/MemoryReader.h"
//#include "Misc/FileHelper.h"


UHighScoreList::UHighScoreList()
{
	F_FilePath = FPaths::Combine(FPaths::ProjectContentDir(), "Scores.txt");
}


TObjectPtr<UHighScoreEntry> UHighScoreList::NewEntry(float time, FString minutes, FString seconds)
{
	TObjectPtr<UHighScoreEntry> Entry = NewObject<UHighScoreEntry>();
	Entry->SetMin(minutes);
	Entry->SetSec(seconds);
	Entry->SetTime(time);

	return Entry;
}

void UHighScoreList::AddScore(TObjectPtr<UHighScoreEntry> entry)
{
	if (Scores.IsEmpty())
	{
		Scores.Add(entry);
		return;
	}

	if (Scores.Num() < HighScoreCount)
	{
		Scores.Add(entry);
		return;
	}

	for (TObjectPtr<UHighScoreEntry>& score : Scores)
	{
		if (score->GetTime() < entry->GetTime())
		{
			Scores.Insert(entry, Scores.Find(score));
			if (Scores.Num() > HighScoreCount)
			{
				Scores.Pop();
			}
			break;
		}
	}
}

void UHighScoreList::SaveScores()
{
	TObjectPtr<URGSaveGame> SaveInstance = Cast<URGSaveGame>(UGameplayStatics::CreateSaveGameObject(URGSaveGame::StaticClass()));

	SaveInstance->MinutesList.Empty();
	SaveInstance->SecondsList.Empty();
	SaveInstance->TimeList.Empty();

	for (int16 i = 0; i < Scores.Num(); i++)
	{
		TObjectPtr<UHighScoreEntry> score = Scores[i];

		SaveInstance->MinutesList.Add(score->GetMin());
		SaveInstance->SecondsList.Add(score->GetSec());
		SaveInstance->TimeList.Add(score->GetTime());
	}


	UGameplayStatics::SaveGameToSlot(SaveInstance, "Save1", 0);
}

void UHighScoreList::LoadScores()
{
	TObjectPtr<URGSaveGame> LoadedSaveGame = Cast<URGSaveGame>(UGameplayStatics::LoadGameFromSlot("Save1", 0));
	Scores.Empty();
	if (LoadedSaveGame)
	{
		for (int16 i = 0; i < LoadedSaveGame->MinutesList.Num(); i++)
		{
			TObjectPtr<UHighScoreEntry> score = NewEntry(LoadedSaveGame->TimeList[i], LoadedSaveGame->MinutesList[i], LoadedSaveGame->SecondsList[i]);
			Scores.Add(score);
		}

	}
}