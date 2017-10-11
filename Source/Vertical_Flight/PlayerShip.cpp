// Fill out your copyright notice in the Description page of Project Settings.

#include "Vertical_Flight.h"
#include "PaperSpriteComponent.h"
#include "PlayerShip.h"
#include "Bullet.h"

const FName APlayerShip::GunMuzzle(TEXT("Muzzle"));

// Sets default values
APlayerShip::APlayerShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ShipSprite"));
	RootComponent = SpriteComponent;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->bAbsoluteLocation = true;

	FireCooldown = 0.1f;

	bCanFire = false;
	bMoveLeft = false;
	bMoveRight = false;
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

	if (bCanFire)
	{
		if (UWorld* World = GetWorld())
		{
			float CurrentTime = World->GetTimeSeconds();
			if (FireReadyTime <= CurrentTime)
			{
				FVector Loc = SpriteComponent->GetSocketLocation(GunMuzzle);
				if (AActor* NewBullet = World->SpawnActor(Bullet))
				{
					NewBullet->SetActorLocation(Loc);
				}
				FireReadyTime = CurrentTime + FireCooldown;
			}
		}
	}

	if (bMoveLeft)
	{
		FVector Loc = GetActorLocation();
		if (Loc.Y > -490.0f)
		{
			Loc += FVector(0.0f, -5.0f, 0.0f);
			SetActorLocation(Loc);
		}
	}

	if (bMoveRight)
	{
		FVector Loc = GetActorLocation();
		if (Loc.Y < 490)
		{
			Loc += FVector(0.0f, 5.0f, 0.0f);
			SetActorLocation(Loc);
		}
	}
}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Setup for thouch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerShip::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &APlayerShip::TouchStopped);

	//Setup for pc
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerShip::FirePressed);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerShip::FireReleased);

	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &APlayerShip::LeftPressed);
	PlayerInputComponent->BindAction("Left", IE_Released, this, &APlayerShip::LeftReleased);

	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &APlayerShip::RightPressed);
	PlayerInputComponent->BindAction("Right", IE_Released, this, &APlayerShip::RightReleased);

}

void APlayerShip::FirePressed()
{
	bCanFire = true;
}

void APlayerShip::FireReleased()
{
	bCanFire = false;
}

void APlayerShip::LeftPressed()
{
	bMoveLeft = true;
}

void APlayerShip::LeftReleased()
{
	bMoveLeft = false;
}


void APlayerShip::RightPressed()
{
	bMoveRight = true;
}

void APlayerShip::RightReleased()
{
	bMoveRight = false;
}

void APlayerShip::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (Location.X >= 600.0f)
	{
		bCanFire = true;
	}
}

void APlayerShip::TouchStopped(ETouchIndex::Type FiongerIndex, FVector Location)
{
	if (Location.X >= 600.0f)
	{
		bCanFire = false;
	}
}