// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"




ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation()
{
	// Use the base pickup behavious
	Super::WasCollected_Implementation();
	// Destroy the battery
	Destroy();
}
