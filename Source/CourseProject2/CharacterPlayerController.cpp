// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"

#include "CharacterPawn.h"

#include "ABearSpawner.h"

#include "BearDestroyer.h"

#include "Kismet/GameplayStatics.h"

bool bIsJumping = false;
bool bIsFalling = false;
float StartingJumpHeight = 0.0f;
float CurrentJumpHeight = 0.0f;

void ACharacterPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    
    ACharacterPawn* CharacterPawn = (ACharacterPawn*)GetPawn();
    FVector CharacterLocation = CharacterPawn->GetActorLocation();

    // Falling logic
    if (bIsFalling)
    {
        if (CurrentJumpHeight <= StartingJumpHeight)
        {
            CharacterLocation.Z = StartingJumpHeight;
            CharacterPawn->SetLocation(CharacterLocation);
            bIsFalling = false;
        }
        else
        {
            CurrentJumpHeight -= JumpSpeed;
            CharacterLocation.Z = CurrentJumpHeight;
            CharacterPawn->SetLocation(CharacterLocation);
        }
    }
    // Jumping logic
    else if (bIsJumping)
    {
        if (CurrentJumpHeight > JumpHeight)
        {
            bIsFalling = true;
            bIsJumping = false;
        }
        else
        {
            CurrentJumpHeight += JumpSpeed;
            CharacterLocation.Z = CurrentJumpHeight;
            CharacterPawn->SetLocation(CharacterLocation);
        }
    }

    // Moving logic

    // Convert mouse movement to in-world coordinates
    FVector WorldLocation;
    FVector WorldRotation;
    DeprojectMousePositionToWorld(WorldLocation, WorldRotation);

    // Convert to YZ plane only (here we deal with the world location that corresponds to the mouse location on screen)
    WorldLocation.X = 0.0f;

    // Move the pawn

    if (CharacterPawn != nullptr)
    {   
        // Workaround for 3D position
        WorldLocation.Y *= 10;

        // Disable mouse up/down movement when jumping or falling
        if (bIsJumping || bIsFalling)
        {
            WorldLocation.Z = CharacterLocation.Z;
        }
        else
        {
            WorldLocation.Z *= 10;
        }

        CharacterPawn->SetLocation(WorldLocation);
    }
}

void ACharacterPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    check(InputComponent != nullptr);
    
    // Uncomment to enable specific input actions

    //InputComponent->BindAction("DestroyCharacter",
    //    EInputEvent::IE_Pressed, this,
    //    &ACharacterPlayerController::DestroyCharacterPawn);

    //InputComponent->BindAction("Jump",
    //    EInputEvent::IE_Pressed, this,
    //    &ACharacterPlayerController::Jump);

    InputComponent->BindAction("SpawnTeddyBear",
        EInputEvent::IE_Pressed, this,
        &ACharacterPlayerController::SpawnTeddyBear);

    InputComponent->BindAction("DestroyTeddyBear",
        EInputEvent::IE_Pressed, this,
        &ACharacterPlayerController::DestroyTeddyBear);
}

void ACharacterPlayerController::DestroyCharacterPawn()
{
    ACharacterPawn* characterPawn = (ACharacterPawn*)GetPawn();
    check(characterPawn != nullptr);
    characterPawn->Destroy();
}

void ACharacterPlayerController::Jump()
{
    ACharacterPawn* characterPawn = (ACharacterPawn*)GetPawn();
    FVector characterLocation = characterPawn->GetActorLocation();
    StartingJumpHeight = characterLocation.Z;
    CurrentJumpHeight = StartingJumpHeight;
    bIsJumping = true;
}

void ACharacterPlayerController::SpawnTeddyBear()
{
    TArray<AActor*> ActorsToFind;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AABearSpawner::StaticClass(), ActorsToFind);

    check(ActorsToFind[0] != nullptr);

    AABearSpawner* bearSpawner = (AABearSpawner*)ActorsToFind[0];

    check(bearSpawner != nullptr);

    bearSpawner->SpawnTeddyBear();
}

void ACharacterPlayerController::DestroyTeddyBear()
{
    TArray<AActor*> ActorsToFind;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearDestroyer::StaticClass(), ActorsToFind);

    check(ActorsToFind[0] != nullptr);

    ABearDestroyer* bearDestroyer = (ABearDestroyer*)ActorsToFind[0];

    check(bearDestroyer != nullptr);

    bearDestroyer->DestroyDestructible();
}