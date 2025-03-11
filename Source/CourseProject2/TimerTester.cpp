// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerTester.h"

#include "Timer.h"

float TimerDuration = 3.0f;

/**
 * Sets default values
*/
ATimerTester::ATimerTester()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void ATimerTester::BeginPlay()
{
	Super::BeginPlay();
	
    Timer = NewObject<UTimer>(this);
    check(Timer != nullptr);
    Timer->RegisterComponent();

    Timer->SetDuration(TimerDuration);
    Timer->Start();
    StartTime = FDateTime::Now();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ATimerTester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (Timer->IsFinished())
    {
        UE_LOG(LogTemp, Warning, TEXT("Timer has finished."));

        float ElapsedTime = (float)(FDateTime::Now() - StartTime).GetTotalSeconds();

        UE_LOG(LogTemp, Warning, TEXT("Timer has run for %f seconds."), ElapsedTime);

        StartTime = FDateTime::Now();
        Timer->Start();
    }
}

