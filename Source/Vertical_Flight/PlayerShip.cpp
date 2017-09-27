// Fill out your copyright notice in the Description page of Project Settings.

#include "Vertical_Flight.h"
#include "PlayerShip.h"


// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;

}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
		
	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerShip::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerShip::TouchStopped);
	PlayerInputComponent->BindVectorAxis("Acceleration", this, &APlayerShip::Acceleration);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerShip::Fire);
	PlayerInputComponent->BindAction("Tilt_Left", IE_Pressed, this, &APlayerShip::MoveLeft);
	PlayerInputComponent->BindAction("Tilt_Right", IE_Pressed, this, &APlayerShip::MoveRight);
}

void APlayerShip::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	//if right side of screen : fire
	//if left side of the screen : save coordinate to check for swipe
	UE_LOG(LogTemp, Warning, TEXT("Touched"));
}

void APlayerShip::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	// if right side of the screen : stop firing
	//if left side of the screen : check for swipe
}

void APlayerShip::Acceleration(FVector Acceleration)
{
	UE_LOG(LogTemp, Warning, TEXT("Acceleration input: %s"), *Acceleration.ToString());
}

void APlayerShip::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire!"));
}

void APlayerShip::MoveLeft() 
{
	UE_LOG(LogTemp, Warning, TEXT("Left"));
}

void APlayerShip::MoveRight()
{
	UE_LOG(LogTemp, Warning, TEXT("Right"));
}

