// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COURSEPROJECT2_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void PlayerTick(float DeltaTime) override;
    virtual void SetupInputComponent() override;
    void DestroyCharacterPawn();
};
