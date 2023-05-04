// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScoreEntry.h"

void UHighScoreEntry::Serialize(FArchive& Archive)
{
	Super::Serialize(Archive);
	Archive << F_Time;
	Archive << S_Minutes;
	Archive << S_Seconds;
}