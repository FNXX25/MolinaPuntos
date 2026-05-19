// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Caja.generated.h"

UENUM()
enum class Directions : uint8
{
	Arriba,
	Abajo,
	Izquierda,
	Derecha,

	MAX UMETA(Hidden)
};

UCLASS()
class MYPROJECT_API ACaja : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACaja();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caja")
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caja")
	int velocidad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caja")
	bool ismoving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caja")
	Directions movedirection;


};
