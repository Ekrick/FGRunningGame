// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreList.h"
#include "HighScoreEntry.h"
#include "RGSaveGame.h"
#include "Kismet/GameplayStatics.h"
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

	SaveInstance->ObjectList = Scores;

	UGameplayStatics::SaveGameToSlot(SaveInstance, "Save1", 0);
}

void UHighScoreList::LoadScores()
{
	TObjectPtr<URGSaveGame> LoadedSaveGame = Cast<URGSaveGame>(UGameplayStatics::LoadGameFromSlot("Save1", 0));
	Scores.Empty();
	if (LoadedSaveGame)
	{
		Scores = LoadedSaveGame->ObjectList;
	}
}






//void UHighScoreList::SaveScores()
//{
//	TArray<uint8> Data;
//	FMemoryWriter Writer(Data);
//
//	TArray<TObjectPtr<UHighScoreEntry>> SaveData = Scores;
//	FObjectAndNameAsStringProxyArchive Ar(Writer, true);
//	Ar << SaveData;
//
//	// Write the serialized data to a file
//	FFileHelper::SaveArrayToFile(Data, *F_FilePath);
//
//}
//
//void UHighScoreList::LoadScores()
//{
//	TArray<uint8> Data;
//	if (!FFileHelper::LoadFileToArray(Data, *F_FilePath))
//	{
//		// File could not be loaded
//		return;
//	}
//
//	// Deserialize the binary data
//	FMemoryReader Reader(Data, true);
//	TArray<TObjectPtr<UHighScoreEntry>> LoadedData;
//	FObjectAndNameAsStringProxyArchive Ar(Reader, true);
//	Ar << LoadedData;
//
//	Scores = LoadedData;
//}