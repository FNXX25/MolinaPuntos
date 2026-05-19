// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/ArrowComponent.h>
#include <Engine/StaticMeshActor.h>

#include "PointActor.generated.h"


UCLASS()
class MYPROJECT_API APointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// The visual handle that makes it clickable in the Editor
	UPROPERTY(VisibleAnywhere, Category = "Reference")
	UArrowComponent* PointHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point Logic")
	AStaticMeshActor* LinkedCube;

};
