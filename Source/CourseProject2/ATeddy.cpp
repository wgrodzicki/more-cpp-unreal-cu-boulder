// Fill out your copyright notice in the Description page of Project Settings.


#include "ATeddy.h"

bool bHasLifespan = false;

/**
 * Sets default values
*/
AATeddy::AATeddy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void AATeddy::BeginPlay()
{
	Super::BeginPlay();
	
    if (bHasLifespan)
    {
        SetLifeSpan(10);
    }
    StartJumpTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AATeddy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AATeddy::Jump()
{
    FVector JumpLocation{ 0.0f };
    JumpLocation.Y = FMath::RandRange(MinJumpY, MaxJumpY);
    JumpLocation.Z = FMath::RandRange(MinJumpZ, MaxJumpZ);
    SetActorLocation(JumpLocation);
    SetActorScale3D(FVector(GetActorScale().X * ScaleMod, GetActorScale().Y * ScaleMod, GetActorScale().Z * ScaleMod));
    StartJumpTimer();
}

void AATeddy::StartJumpTimer()
{
    float TimerDuration = FMath::RandRange(MinJumpDelay, MaxJumpDelay);
    FTimerHandle Timer;

    GetWorldTimerManager().SetTimer(Timer, this, &AATeddy::Jump, TimerDuration);
}