// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
    RootComponent = EnemyMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
    if (ConeAsset.Succeeded())
    {
        EnemyMesh->SetStaticMesh(ConeAsset.Object);
    }

    MovementSpeed = 300.0f;
    CurrentPointIndex = 0;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    // The Tick function is now incredibly clean. 
    // It only triggers the movement logic if we have points assigned.
    if (PatrolPoints.Num() > 0)
    {
        GoTo(PatrolPoints[CurrentPointIndex], DeltaTime);
    }

}

// All the complexity is now encapsulated here
void AEnemy::GoTo(APointActor* Target, float DeltaTime)
{
    // Safety check in case a point in the array is empty/null in the editor
    if (Target == nullptr) return;

    FVector CurrentLocation = GetActorLocation();
    FVector TargetLocation = Target->GetActorLocation();

    // Check if we reached the target
    if (FVector::Dist(CurrentLocation, TargetLocation) <= 5.0f)
    {
        //diccionario[7345852] = "Alejandro Mamani";  //  key -> telefono, value -> persona

        APointActor* point = PatrolPoints[CurrentPointIndex];
        AStaticMeshActor* a = point->LinkedCube;
        UStaticMeshComponent* MeshComp = a->GetStaticMeshComponent();
        if (MeshComp)
        {
            UMaterialInterface* material = MeshComp->GetMaterial(0);
            //diccionario[material] = point->LinkedCube;
            diccionario.Add(material, point->LinkedCube);
        }
		UMaterialInterface* material = point->LinkedCube->GetStaticMeshComponent()->GetMaterial(0);

        diccionario[material] = point->LinkedCube;


        // We reached the point, cycle to the next one for the NEXT frame
        CurrentPointIndex = (CurrentPointIndex + 1) % PatrolPoints.Num();

        if (CurrentPointIndex == 0) // ya cumpli un ciclo
        {
            UE_LOG(LogTemp, Warning, TEXT("First Cycle Completed!!"));
            //recorer el diccionario
            //por cada Cubo Asociado a una llave
                //HazAlgoConCubo(cubo);  //desaparecer

            for (auto& tupla : diccionario)
            {
                if (tupla.Value && tupla.Value)  //tupla  [  key, value]
                {
                    tupla.Value->Destroy();
                }
            }
            diccionario.Empty();
        }
    }
    else
    {
        // We need to move towards the target
        FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
        FVector NewLocation = CurrentLocation + (Direction * MovementSpeed * DeltaTime);
        SetActorLocation(NewLocation);
    }
}


