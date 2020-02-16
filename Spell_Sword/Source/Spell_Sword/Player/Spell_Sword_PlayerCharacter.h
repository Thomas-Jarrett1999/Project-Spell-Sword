// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UConstants.h"
#include "GameFramework/Character.h"
#include "Spell_Sword_PlayerCharacter.generated.h"

using namespace HumanoidAnimState;

UCLASS()
class SPELL_SWORD_API ASpell_Sword_PlayerCharacter : public ACharacter
{
    GENERATED_BODY()

        // First Person Mesh
        UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
        class USkeletalMeshComponent* FP_PlayerMesh;

        // Third Person Mesh
        //UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
        //class USkeletalMeshComponent* TP_PlayerMesh;

    // First Person Camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        class UCameraComponent* FP_Camera;

    // Third Person Camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        class UCameraComponent* TP_Camera;

    //// Main hand weapon
    //UPROPERTY(BlueprintReadWrite, Category = Weapons)
    //class AWeapon* mainHand;

    //// Off hand weapon
    //UPROPERTY(BlueprintReadWrite, Category = Weapons)
    //class AWeapon* offHand;

    // Third Person Camera
    //UPROPERTY(VisibleDefaultsOnly, Category = Inventory)
    //class UInventoryComponent* Inventory;

private:

    UCameraComponent* currentCamera;

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
         E_HumanoidAnimState currentAnimState;

    //UPROPERTY(BlueprintReadWrite, Category = Stats)
        int i_Health;

    //UPROPERTY(BlueprintReadWrite, Category = Stats)
        int i_Stamina;

    //UPROPERTY(BlueprintReadWrite, Category = Stats)
        int i_Mana;

    //UPROPERTY(BlueprintReadWrite, Category = Money)
        int i_Money;

    //UPROPERTY(BlueprintReadWrite, Category = Crime)
        int i_Bounty;

    //UPROPERTY(BlueprintReadWrite, Category = Faction)
        int i_Faction1Standing;

    //UI Element

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
        bool b_IsCrouched;

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
        bool b_IsJumping;

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
        bool b_IsAttacking;

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
        bool b_IsBlocking;

    //UPROPERTY(BlueprintReadWrite, Category = Anim)
        bool b_IsRolling;

    //UPROPERTY(BlueprintReadWrite, Category = Inventory)
        bool b_IsInventoryOpen;

public:
    // Sets default values for this character's properties
    ASpell_Sword_PlayerCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float val);

    void MoveRight(float val);

    void Jump(float val);

    //void LookUp(float val);

    //void LookRight(float val);

    void Crouch();

    void Roll();

    void Attack();

    void Block();

    void Interact();

    void BowZoom();

    void ChangeAnimState(E_HumanoidAnimState state);

    //void InventoryAddItem(Item* item);

    //void InventoryDropItem(Item* item;

    void RegenHealth();

    void RegenStamina();

    void RegenMana();

    void ChangeCamera();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    E_HumanoidAnimState GetCurrentAnimState() { return currentAnimState; }

    UCameraComponent* GetCurrentCamera() { return currentCamera; }

    int GetHealth() { return i_Health; }

    int GetStamina() { return i_Stamina; }

    int GetMana() { return i_Mana; }

    int GetMoney() { return i_Money; }

    int GetBounty() { return i_Bounty; }

    int GetFaction1Standing() { return i_Faction1Standing; }

    bool GetIsCrouched() { return b_IsCrouched; }

    bool GetIsJumping() { return b_IsJumping; }

    bool GetIsAttacking() { return b_IsAttacking; }

    bool GetIsBlocking() { return b_IsBlocking; }

    bool GetIsRolling() { return b_IsRolling; }

    bool GetIsInventoryOpen() { return b_IsInventoryOpen; }

    FORCEINLINE class USkeletalMeshComponent* GetFP_Mesh() const { return FP_PlayerMesh; }
    //FORCEINLINE class USkeletalMeshComponent* GetTP_Mesh() const { return TP_PlayerMesh; }
    FORCEINLINE class UCameraComponent* GetFP_Camera() const { return FP_Camera; }
    FORCEINLINE class UCameraComponent* GetTP_Camera() const { return TP_Camera; }

};
