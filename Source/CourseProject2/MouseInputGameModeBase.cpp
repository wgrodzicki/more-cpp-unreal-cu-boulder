// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseInputGameModeBase.h"

AMouseInputGameModeBase::AMouseInputGameModeBase()
{
    ConstructorHelpers::FObjectFinder<UClass>
        PawnClass(TEXT("Class'/Game/MeshesAndActors/Blueprints/BP_MyCharacterPawn.BP_MyCharacterPawn_C'"));
    
    if (PawnClass.Object != nullptr)
    {
        DefaultPawnClass = PawnClass.Object;
    }

    ConstructorHelpers::FObjectFinder<UClass>
        ControllerClass(TEXT("Class'/Game/MeshesAndActors/Blueprints/BP_CharacterPlayerController.BP_CharacterPlayerController_C'"));
    
    if (ControllerClass.Object != nullptr)
    {
        PlayerControllerClass = ControllerClass.Object;
    }
};