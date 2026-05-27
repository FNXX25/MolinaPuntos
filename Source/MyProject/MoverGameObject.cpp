// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverGameObject.h"

// Sets default values
AMoverGameObject::AMoverGameObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



    FVector centerLocation(0, 0, 0);
    SetActorLocation(centerLocation);


    // Possess the player automatically to receive input properly through SetupPlayerInputComponent
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // We don't need AutoReceiveInput if we are already possessing the pawn
    AutoReceiveInput = EAutoReceiveInput::Player0;
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));

    if (CubeMeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(CubeMeshAsset.Object);
    }
    // ------------------------------------------

    // Set default values for our editor variables
    Velocity = 400.0f;
    MoveDirection = EMoveDirection::Right;
    bIsMoving = false;
}

// Called when the game starts or when spawned
void AMoverGameObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoverGameObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    // 4. Movement Logic
    if (bIsMoving)
    {
        FVector CurrentLocation = GetActorLocation();
        FVector MovementStep = FVector::ZeroVector;

        // Map the Enum to Unreal's top-down coordinate system
        // Looking straight down: +X is Up, -X is Down, +Y is Right, -Y is Left
        //static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
        switch (MoveDirection)
        {
        case EMoveDirection::Up:
            MovementStep.X = 1.0f;
            break;
        case EMoveDirection::Down:
            MovementStep.X = -1.0f;
            break;
        case EMoveDirection::Right:
            //cilindro
            MovementStep.Y = 1.0f;
            break;
        case EMoveDirection::Left:
            //piramide
            MovementStep.Y = -1.0f;
            break;

        case EMoveDirection::UpRights:
            MovementStep.X = 1;
            MovementStep.Y = 1;
            break;

            /* case EMoveDirection::UpLeft:
                 MovementStep.X = -1;
                 MovementStep.Y = 1;
                 break;
             }*/
        }
        // Calculate the new position ensuring frame-rate independence using DeltaTime
        CurrentLocation += MovementStep * Velocity * DeltaTime;

        SetActorLocation(CurrentLocation);
    }
}

// Called to bind functionality to input
void AMoverGameObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("ToggleMove2", IE_Pressed, this, &AMoverGameObject::ToggleMovement).bConsumeInput = false;
	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &AMoverGameObject::Arriba).bConsumeInput = false;
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &AMoverGameObject::Abajo).bConsumeInput = false;
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &AMoverGameObject::Izquierda).bConsumeInput = false;
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &AMoverGameObject::Derecha).bConsumeInput = false;

}

void AMoverGameObject::ToggleMovement()
{
    bIsMoving = !bIsMoving;

}

void AMoverGameObject::Arriba()
{
	MoveDirection = EMoveDirection::Up;
}

void AMoverGameObject::Abajo()
{
	MoveDirection = EMoveDirection::Down;
}

void AMoverGameObject::Izquierda()
{
	MoveDirection = EMoveDirection::Left;
}

void AMoverGameObject::Derecha()
{
	MoveDirection = EMoveDirection::Right;
}

