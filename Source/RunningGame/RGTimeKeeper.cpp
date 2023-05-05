

#include "RGTimeKeeper.h"

ARGTimeKeeper::ARGTimeKeeper()
{
	PrimaryActorTick.bCanEverTick = true;

}


void ARGTimeKeeper::BeginPlay()
{
	Super::BeginPlay();

	f_time = 0;
	
}

void ARGTimeKeeper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer(DeltaTime);
}



void ARGTimeKeeper::GameTimer(float DeltaTime)
{
	f_time += DeltaTime;

	seconds += (int)DeltaTime;
	if (seconds >= 60)
	{
		minutes++;
		seconds = 0;
	}
}



