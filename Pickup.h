// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h" // build tool will look for this line the last

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** return the mesh for the pickup */
	FORCEINLINE class UStaticMeshComponent* GetMesh() const {
		return PickupMesh;
	}

	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	/** Function to call when the pickup is collected */
	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void WasCollected();
	
	virtual void WasCollected_Implementation();

protected:
	/** true when the pickup can be used, false when the pickup is deactivated */
	bool bIsActive;

private:
	/* static mesh to represent the pickup in each level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *PickupMesh;
	
};
