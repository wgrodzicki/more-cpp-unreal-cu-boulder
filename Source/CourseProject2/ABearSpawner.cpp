// Fill out your copyright notice in the Description page of Project Settings.


#include "ABearSpawner.h"

/**
 * Sets default values
*/
AABearSpawner::AABearSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void AABearSpawner::BeginPlay()
{
	Super::BeginPlay();
	
    // Uncomment for auto-spawning

    //StartSpawnTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AABearSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABearSpawner::SpawnTeddyBear()
{
    UE_LOG(LogTemp, Warning, TEXT("Bear spawned!"));

    TSubclassOf<AATeddy> BearToSpawn;

    int BearIndex = FMath::RandRange(0, 2);

    switch (BearIndex)
    {
        case 0:
            BearToSpawn = UTeddyBear1;
            break;
        case 1:
            BearToSpawn = UTeddyBear2;
            break;
        case 2:
            BearToSpawn = UTeddyBear3;
            break;
        default:
            break;
    }

    FVector SpawnLocation{ 0.0f }; // This is actually ~Vector3
    float LocationY = FMath::FRandRange(MinSpawnY, MaxSpawnY);
    float LocationZ = FMath::RandRange(MinSpawnZ, MaxSpawnZ);
    SpawnLocation.SetComponentForAxis(EAxis::Y, LocationY); // Components can be accessed directly
    SpawnLocation.SetComponentForAxis(EAxis::Z, LocationZ);

    GetWorld()->SpawnActor<AATeddy>(BearToSpawn, SpawnLocation, FRotator::ZeroRotator);

    // Uncomment for auto-spawning

    //StartSpawnTimer();
}

void AABearSpawner::StartSpawnTimer()
{
    float TimerDuration = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
    FTimerHandle Timer;

    GetWorldTimerManager().SetTimer(Timer, this, &AABearSpawner::SpawnTeddyBear, TimerDuration);
}