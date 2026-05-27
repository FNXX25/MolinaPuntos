// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Caja.h"
#include "MoverGameObject.generated.h"

UENUM(BlueprintType)
enum class EMoveDirection : uint8
{
	Up      UMETA(DisplayName = "Arriba"),
	Down    UMETA(DisplayName = "Abajo"),
	Left    UMETA(DisplayName = "Izquierda"),
	Right   UMETA(DisplayName = "Derecha"),
	UpRights UMETA(DisplayName = "Diagonal Derecha Arriba")
};

UCLASS()
class MYPROJECT_API AMoverGameObject : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMoverGameObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// A visual mesh so we can actually see the object in the editor
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* MeshComponent;


	// 2. Variables exposed to the Visual Editor
	UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
	float Velocity;

	UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
	EMoveDirection MoveDirection;
	UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
	bool bIsMoving;

private:

	// Function to listen to the Spacebar
	void ToggleMovement();
	void Arriba();
	void Abajo();
	void Izquierda();
	void Derecha();


};
