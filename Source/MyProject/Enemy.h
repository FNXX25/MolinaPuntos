// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointActor.h"

#include "Enemy.generated.h"

UCLASS()
class MYPROJECT_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
    UStaticMeshComponent* EnemyMesh;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Movement")
    TArray<APointActor*> PatrolPoints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MovementSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    TMap<UMaterialInterface*, AStaticMeshActor*> diccionario;



private:
    int32 CurrentPointIndex;

    // Updated to include DeltaTime since it handles the movement math
    void GoTo(APointActor* Target, float DeltaTime);
};
