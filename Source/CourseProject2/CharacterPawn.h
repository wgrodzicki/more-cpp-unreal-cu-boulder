// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterPawn.generated.h"

UCLASS()
class COURSEPROJECT2_API ACharacterPawn : public APawn
{
	GENERATED_BODY()

private:
    const int HalfWidth{ 13 };
    const int HalfHeight{ 16 };
    const int VerticalOffset{ 3 };

public:
	// Sets default values for this pawn's properties
	ACharacterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void SetLocation(FVector Location);
};
