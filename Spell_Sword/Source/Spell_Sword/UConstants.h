// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell_Sword.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UConstants.generated.h"

/**
 * 
 */
UCLASS()
class SPELL_SWORD_API UUConstants : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};

#pragma region ENUMS

UENUM(BlueprintType)
namespace HumanoidAnimState
{
    enum E_HumanoidAnimState
    {
        none = 0,
        Idle = 1,
        Walk = 2,
        Jog = 3,
        Run = 4,
        Attack = 5,
        Converse = 6
    };
}

#pragma endregion ENUMS