// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

class ABullet;

UCLASS()
class VERTICAL_FLIGHT_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

private:
	// CameraBoom for controlling the player camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *CameraBoom;

	// CameraComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// name of the gun muzzle for spawning bullets
	static const FName GunMuzzle;

	bool Test;
	FVector Tilt;
	FVector RotationRate;
	FVector Gravity;
	FVector Aceleration;

protected:
	// Handler for when a touch input begins
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	// Handler for when a touch input stops
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// Handles Accelerometer data
	void Acceleration(FVector Acceleration);

	// function start firing
	void FirePressed();

	// function stop firing
	void FireReleased();

	// function to start moving to the left
	void LeftPressed();

	// function to stop moving to the left
	void LeftReleased();

	// function to start moving to the right
	void RightPressed();

	// function to stop moving to the right
	void RightReleased();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
		uint32 bCanFire : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
		uint32 bMoveLeft : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
		uint32 bMoveRight : 1;

	// Bullet to spawn when firing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
		TSubclassOf<AActor> Bullet;

private:
	// Sprite for the ship
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* SpriteComponent;

	// Cooldown timer for firing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
		float FireCooldown;

	// Timer to keep track of fire cooldown
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
		float FireReadyTime;
};
