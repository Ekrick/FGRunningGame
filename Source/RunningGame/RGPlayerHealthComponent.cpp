// Fill out your copyright notice in the Description page of Project Settings.


#include "RGPlayerHealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

URGPlayerHealthComponent::URGPlayerHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	m_health = 3;
}



void URGPlayerHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}



void URGPlayerHealthComponent::PlayerHit()
{
	m_health -= m_health;
	UKismetSystemLibrary::PrintString(this, "damage", true, true, FLinearColor::Red, 2.f);
	if (m_health <= 0)
	{

	}
}
