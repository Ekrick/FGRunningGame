
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
	FVector Spawn1 = FVector(1500, 300, 200);
	FVector Spawn2 = FVector(1500, 900, 200);

	TObjectPtr<ARGCharacter>Player1;
	TObjectPtr<ARGCharacter>Player2;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	TSubclassOf<ARGCharacter>SpawnedCharacter_1;

	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	TSubclassOf<ARGCharacter>SpawnedCharacter_2;

	UPROPERTY(EditDefaultsOnly, Category = "Player Settings")
	float MovementSpeed = 5.f;


	void Move_1(const FInputActionValue& Value);

	void Move_2(const FInputActionValue& Value);

	void SpawnPlayers();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
