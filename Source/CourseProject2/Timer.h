// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Timer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COURSEPROJECT2_API UTimer : public UActorComponent
{
    GENERATED_BODY()

private:
    bool bIsRunning{ false };
    bool bWasStarted{ false };
    float ElapsedSeconds{ false };
    float Duration{ false };

public:	
	// Sets default values for this component's properties
	UTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    bool IsFinished();

    bool IsRunning();

    void SetDuration(float Duration);

    void Start();
		
};
