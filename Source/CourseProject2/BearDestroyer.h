// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BearDestroyer.generated.h"

/**
 *
*/
UCLASS()
class COURSEPROJECT2_API ABearDestroyer : public AActor
{
	GENERATED_BODY()

private:
    const float TimerDuration = 5.0f;

    void StartDestroyTimer();

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ABearDestroyer();

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

public:
    void DestroyDestructible();
};
