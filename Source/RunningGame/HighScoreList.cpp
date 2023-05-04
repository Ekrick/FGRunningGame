// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreList.h"
#include "HighScoreEntry.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "Serialization/MemoryReader.h"
#include "Misc/FileHelper.h"


UHighScoreList::UHighScoreList()
{
	F_FilePath = FPaths::Combine(FPaths::ProjectContentDir(), "Scores.txt");
}


TObjectPtr<UHighScoreEntry> UHighScoreList::NewEntry(float time, FString minutes, FString seconds)
{
	TObjectPtr<UHighScoreEntry> Entry = NewObject<UHighScoreEntry>();
	Entry->S_Minutes = minutes;
	Entry->S_Seconds = seconds;
	Entry->F_Time = time;

	return Entry;
}

void UHighScoreList::AddScore(TObjectPtr<UHighScoreEntry> entry)
{
	if (Scores.IsEmpty())
	{
		Scores.Add(entry);
		return;
	}

	for (int i = 0; i < Scores.Num(); i++)
	{
		if (Scores[i]->F_Time < entry->F_Time)
		{
			Scores.Insert(entry, i);
			if (Scores.Num() > HighScoreCount)
			{
				Scores.Pop();
			}
			return;
		}
	}
}

void UHighScoreList::SaveScores()
{
	TArray<uint8> Data;
	FMemoryWriter Writer(Data);

	TArray<TObjectPtr<UHighScoreEntry>> SaveData = Scores;
	FObjectAndNameAsStringProxyArchive Ar(Writer, true);
	Ar << SaveData;

	// Write the serialized data to a file
	FFileHelper::SaveArrayToFile(Data, *F_FilePath);

}

void UHighScoreList::LoadScores()
{
	TArray<uint8> Data;
	if (!FFileHelper::LoadFileToArray(Data, *F_FilePath))
	{
		// File could not be loaded
		return;
	}

	// Deserialize the binary data
	FMemoryReader Reader(Data, true);
	TArray<TObjectPtr<UHighScoreEntry>> LoadedData;
	FObjectAndNameAsStringProxyArchive Ar(Reader, true);
	Ar << LoadedData;

	Scores = LoadedData;
}