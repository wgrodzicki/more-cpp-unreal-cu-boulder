// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"

#include "CharacterPawn.h"

void ACharacterPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    // Convert mouse movement to in-world coordinates
    FVector WorldLocation;
    FVector WorldRotation;
    DeprojectMousePositionToWorld(WorldLocation, WorldRotation);

    // Convert to YZ plane only (here we deal with the world location that corresponds to the mouse location on screen)
    WorldLocation.X = 0.0f;

    // Move the pawn
    ACharacterPawn* CharacterPawn = (ACharacterPawn*)GetPawn();

    if (CharacterPawn != nullptr)
    {   
        // Workaround for 3D position
        WorldLocation.Y *= 10;
        WorldLocation.Z *= 10;

        CharacterPawn->SetLocation(WorldLocation);
    }
}

void ACharacterPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    check(InputComponent != nullptr);
    InputComponent->BindAction("DestroyCharacter",
        EInputEvent::IE_Pressed, this,
        &ACharacterPlayerController::DestroyCharacterPawn);
}

void ACharacterPlayerController::DestroyCharacterPawn()
{
    ACharacterPawn* characterPawn = (ACharacterPawn*)GetPawn();
    check(characterPawn != nullptr);
    characterPawn->Destroy();
}