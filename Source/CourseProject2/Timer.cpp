// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"

// Sets default values for this component's properties
UTimer::UTimer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTimer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (bIsRunning)
    {
        ElapsedSeconds += DeltaTime;
    }

    if (ElapsedSeconds >= Duration)
    {
        bIsRunning = false;
    }
}

bool UTimer::IsFinished()
{
    return bWasStarted && !bIsRunning;
}

bool UTimer::IsRunning()
{
    return bIsRunning;
}

void UTimer::SetDuration(float NewDuration)
{
    if (!bIsRunning && NewDuration > 0)
    {
        UTimer::Duration = NewDuration;
    }
}

void UTimer::Start()
{
    if (Duration > 0)
    {
        bWasStarted = true;
        bIsRunning = true;
        ElapsedSeconds = 0;
    }
}