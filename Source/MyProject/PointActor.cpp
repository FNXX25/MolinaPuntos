// Fill out your copyright notice in the Description page of Project Settings.


#include "PointActor.h"

// Sets default values
APointActor::APointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Create the Arrow Component
    PointHandle = CreateDefaultSubobject<UArrowComponent>(TEXT("PointHandle"));

    // Set the Arrow as the Root Component
    // Now, clicking the arrow in the viewport lets you move the entire Actor!
    RootComponent = PointHandle;
}

// Called when the game starts or when spawned
void APointActor::BeginPlay()
{
	Super::BeginPlay();
    if (LinkedCube) {
        SetActorLocation(LinkedCube->GetActorLocation());
    }

}

// Called every frame
void APointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

