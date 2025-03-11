// Fill out your copyright notice in the Description page of Project Settings.

#include "Resizer.h"
#include "Timer.h"
#include "GameFramework/Actor.h"

float SizeChangeRatePerSec = 2.0f;
float TimerInterval = 5.0f;

/**
 * Sets default values
*/
AResizer::AResizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void AResizer::BeginPlay()
{
	Super::BeginPlay();

    Timer = NewObject<UTimer>(this);
    check(Timer != nullptr);
    Timer->RegisterComponent();

    Timer->SetDuration(TimerInterval);
    Timer->Start();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AResizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    ResizeActor(DeltaTime, SizeChangeRatePerSec);

    if (Timer->IsFinished())
    {
        SizeChangeRatePerSec *= -1;
        Timer->Start();
    }
}

void AResizer::ResizeActor(float DeltaTime, float SizeChangeRate)
{
    FVector CurrentSize = GetActorScale3D();
    CurrentSize.X += DeltaTime * SizeChangeRate;
    CurrentSize.Y += DeltaTime * SizeChangeRate;
    CurrentSize.Z += DeltaTime * SizeChangeRate;
    SetActorScale3D(CurrentSize);
}

