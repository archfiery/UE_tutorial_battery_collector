// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	ABatteryPickup();

	/** Override the WasCollected function - use Implementation because 
	it is a Blueprint Native Event
	*/
	void WasCollected_Implementation() override;

};
