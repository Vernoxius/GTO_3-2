// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

UCLASS()
class VERTICAL_FLIGHT_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Handler for when a touch starts
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	// Handler for when a touch stops
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// Handles Accelerometer data
	void Acceleration(FVector Acceleration);
	
	
};
