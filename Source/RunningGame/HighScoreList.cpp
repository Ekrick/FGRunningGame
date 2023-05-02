// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreList.h"

float UHighScoreList::LoadScores()
{
	return 0;
}

void UHighScoreList::AddScore(float score)
{
	if (Scores.IsEmpty())
	{
		Scores.Add(score);
		return;
	}

	for (int i = 0; i < Scores.Num(); i++)
	{
		if (Scores[i] < score)
		{
			Scores.Insert(score, i);
			if (Scores.Num() > HighScoreCount)
			{
				Scores.Pop();
			}
			return;
		}
	}

}