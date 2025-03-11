// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATeddy.generated.h"

/**
 *
*/
UCLASS()
class COURSEPROJECT2_API AATeddy : public AActor
{
	GENERATED_BODY()

private:
    const float MinJumpDelay{ 2.0f };
    const float MaxJumpDelay{ 4.5f };

    const float MinJumpY{ -150.0f };
    const float MaxJumpY{ 150.0f };
    const float MinJumpZ{ -100.0f };
    const float MaxJumpZ{ 100.0f };

    const float ScaleMod{ 1.5f };

    void StartJumpTimer();

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	AATeddy();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

    UFUNCTION()
    void Jump();

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

};
