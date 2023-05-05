// Copyright Epic Games, Inc. All Rights Reserved.

#include "RunningGameGameMode.h"
#include "RunningGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARunningGameGameMode::ARunningGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

