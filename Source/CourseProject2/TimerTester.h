// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Timer.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerTester.generated.h"

/**
 *
*/
UCLASS()
class COURSEPROJECT2_API ATimerTester : public AActor
{
	GENERATED_BODY()

private:
    UTimer* Timer;
    FDateTime StartTime;

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ATimerTester();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

};
