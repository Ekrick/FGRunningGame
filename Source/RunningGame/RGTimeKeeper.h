
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGTimeKeeper.generated.h"

UCLASS()
class RUNNINGGAME_API ARGTimeKeeper : public AActor
{
	GENERATED_BODY()
	
public:	
	ARGTimeKeeper();

private:
	float f_time;

	void GameTimer(float DeltaTime);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	float GetGameTime() { return f_time; }

};
