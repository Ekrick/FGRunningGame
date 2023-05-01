// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"
#include "RGCharacter.generated.h"

//class USpringArmComponent;
//class UCameraComponent;
//class UInputMappingContext;
//class UInputAction;
class UCapsuleComponent;
class UStaticMeshComponent;


UCLASS()
class RUNNINGGAME_API ARGCharacter : public AActor
{
	GENERATED_BODY()

private:
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<USpringArmComponent> CameraBoom;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UCameraComponent> FollowCamera;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputMappingContext> MappingContext;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> MoveAction;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<UInputAction> JumpAction;


	int m_health;

public:
	ARGCharacter();


protected:
	virtual void BeginPlay() override;

public:
	//void Move(const FInputActionValue& Value);

	int GetHealth() { return m_health; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
	TObjectPtr<UStaticMeshComponent> PlayerMesh;

	void PlayerHit();
	
	void CharacterGravity();

	void OutOfBounds();

	virtual void Tick(float DeltaTime) override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
