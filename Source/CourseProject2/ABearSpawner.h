// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ATeddy.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABearSpawner.generated.h"

/**
 *
*/
UCLASS()
class COURSEPROJECT2_API AABearSpawner : public AActor
{
	GENERATED_BODY()

private:
    const float MinSpawnDelay{ 1.0f };
    const float MaxSpawnDelay{ 2.5f };

    const float MinSpawnY{ -100.0f };
    const float MaxSpawnY{ 100.0f };
    const float MinSpawnZ{ -50.0f };
    const float MaxSpawnZ{ 50.0f };

    void StartSpawnTimer();

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	AABearSpawner();

    UFUNCTION()
    void SpawnTeddyBear();

protected:
    UPROPERTY(EditAnywhere,
        meta = (MetaClass = "TeddyBear"),
        Category = TeddyBearBlueprints)
    TSubclassOf<AATeddy> UTeddyBear1;

    UPROPERTY(EditAnywhere,
        meta = (MetaClass = "TeddyBear"),
        Category = TeddyBearBlueprints)
    TSubclassOf<AATeddy> UTeddyBear2;

    UPROPERTY(EditAnywhere,
        meta = (MetaClass = "TeddyBear"),
        Category = TeddyBearBlueprints)
    TSubclassOf<AATeddy> UTeddyBear3;

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
