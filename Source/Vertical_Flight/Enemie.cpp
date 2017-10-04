// Fill out your copyright notice in the Description page of Project Settings.

#include "Vertical_Flight.h"
#include "Enemie.h"


// Sets default values
AEnemie::AEnemie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

