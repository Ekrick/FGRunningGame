// Fill out your copyright notice in the Description page of Project Settings.


#include "RGPlayerHealthComponent.h"

URGPlayerHealthComponent::URGPlayerHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	m_health = 3;
}



void URGPlayerHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}



void URGPlayerHealthComponent::TakeDamage()
{
	m_health -= m_health;

	if (m_health <= 0)
	{

	}
}
