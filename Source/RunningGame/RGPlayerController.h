
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "RGPlayerController.generated.h"



class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class ARGCharacter;
class ARGTimeKeeper;
class UHighScoreList;

UCLASS()
class RUNNINGGAME_API ARGPlayerController : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction_1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction_2;
	

public:
	ARGPlayerController();

private:
	float f_time;
	float f_seconds;

	FVector Spawn1 = FVector(1500, 300, 200);
	FVector Spawn2 = FVector(1500, 900, 200);

	TObjectPtr<ARGCharacter>Player1;
	TObjectPtr<ARGCharacter>Player2;

	TObjectPtr<UHighScoreList>ScoreList;

	void Move_1(const FInputActionValue& Value);

	void Move_2(const FInputActionValue& Value);

	void SpawnPlayers();

	void GameTimer(float DeltaTime);


protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(BlueprintReadOnly)
	int TimerSeconds;
	UPROPERTY(BlueprintReadOnly)
	int TimerMinutes;

	UPROPERTY(BlueprintReadOnly)
	FString StringSeconds;
	UPROPERTY(BlueprintReadOnly)
	FString StringMinutes;


	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	TSubclassOf<ARGCharacter>SpawnedCharacter_1;

	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	TSubclassOf<ARGCharacter>SpawnedCharacter_2;

	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	float MovementSpeed = 5.f;

	void SaveScore();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
