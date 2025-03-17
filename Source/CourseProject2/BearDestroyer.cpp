// Fill out your copyright notice in the Description page of Project Settings.


#include "BearDestroyer.h"

#include "Kismet/GameplayStatics.h"

/**
 * Sets default values
*/
ABearDestroyer::ABearDestroyer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void ABearDestroyer::BeginPlay()
{
	Super::BeginPlay();
	
    // Uncomment for auto-destroying

    //StartDestroyTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ABearDestroyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABearDestroyer::DestroyDestructible()
{
    TArray<AActor*> TaggedActors;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Destructible", TaggedActors);

    if (TaggedActors.Num() > 0)
    {
        TaggedActors[0]->Destroy();
        UE_LOG(LogTemp, Warning, TEXT("Bear destroyed!"));
    }
    
    // Uncomment for auto-destroying

    //StartDestroyTimer();
}

void ABearDestroyer::StartDestroyTimer()
{
    FTimerHandle Timer;

    GetWorldTimerManager().SetTimer(Timer, this, &ABearDestroyer::DestroyDestructible, TimerDuration);
}
