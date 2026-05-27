// Fill out your copyright notice in the Description page of Project Settings.


#include "Caja.h"

// Sets default values
ACaja::ACaja()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);

	velocidad = 0;

}

// Called when the game starts or when spawned
void ACaja::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ismoving) {
		FVector newLocation = GetActorLocation();
		if(movedirection == Directions::Derecha) {
			newLocation.Y += velocidad * DeltaTime;
		}
		else if (movedirection == Directions::Izquierda){
			newLocation.Y -= velocidad * DeltaTime;
		}
		else if (movedirection == Directions::Arriba) {
			newLocation.X += velocidad * DeltaTime;
		}
		else if (movedirection == Directions::Abajo) {
			newLocation.X -= velocidad * DeltaTime;
		}
		SetActorLocation(newLocation);
	}

}

