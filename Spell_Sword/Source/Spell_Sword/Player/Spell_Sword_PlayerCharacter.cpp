// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Sword_PlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpell_Sword_PlayerCharacter::ASpell_Sword_PlayerCharacter()
{
 	//Set Size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

    // Create and Setup the FP_Camera (First Person Camera)
    FP_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FP_Camera->SetupAttachment(GetCapsuleComponent());
    FP_Camera->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
    FP_Camera->bAutoActivate = true;
    FP_Camera->bUsePawnControlRotation = true;

    // Create and Setup the TP_Camera (Third Person Camera)
    TP_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
    TP_Camera->SetupAttachment(GetCapsuleComponent());
    TP_Camera->RelativeLocation = FVector(-339.56f, 1.75f, 124.0f);
    TP_Camera->RelativeRotation = FRotator(0.0f, -30.0f, 0.0f);
    TP_Camera->FieldOfView = 120.0f;
    TP_Camera->bAutoActivate = false;
    TP_Camera->bUsePawnControlRotation = true;

    // Create and Setup the TempMesh
    FP_PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_CharacterMesh"));
    //TempMesh->SetOwnerNoSee(true);
    FP_PlayerMesh->SetupAttachment(RootComponent);
    FP_PlayerMesh->bCastDynamicShadow = false;
    FP_PlayerMesh->CastShadow = false;

    // Sets the current camera to the first person camera and the current anim state to none
    currentCamera = FP_Camera;
    currentAnimState = HumanoidAnimState::none;

    i_Health = 100;
    i_Stamina = 100;
    i_Mana = 100;

    i_Money = 0;

    i_Bounty = 0;

    i_Faction1Standing = 0;
}

// Called when the game starts or when spawned
void ASpell_Sword_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Health: ") + i_Health);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Stamina: ") + i_Stamina);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Mana: ") + i_Mana);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Money: ") + i_Money);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bounty: ") + i_Bounty);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Faction 1 Standing: ") + i_Faction1Standing);
}

// Called every frame
void ASpell_Sword_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpell_Sword_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // set up gameplay key bindings
    check(PlayerInputComponent);

    // Bind CameraChange action
    // Z
    PlayerInputComponent->BindAction("ChangeCamera", IE_Pressed, this, &ASpell_Sword_PlayerCharacter::ChangeCamera);

    // Bind movement actions
    // WASD
    PlayerInputComponent->BindAxis("MoveForward", this, &ASpell_Sword_PlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASpell_Sword_PlayerCharacter::MoveRight);
}

void ASpell_Sword_PlayerCharacter::MoveForward(float val)
{
    // Move Forward
    if (val != 0.f)
    {
        AddMovementInput(GetActorForwardVector(), val);
    }
}

void ASpell_Sword_PlayerCharacter::MoveRight(float val)
{
    // Move Right
    if (val != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), val);
    }
}

void ASpell_Sword_PlayerCharacter::Jump(float val)
{
}

void ASpell_Sword_PlayerCharacter::Crouch()
{
    
}

void ASpell_Sword_PlayerCharacter::Roll()
{
}

void ASpell_Sword_PlayerCharacter::Attack()
{
}

void ASpell_Sword_PlayerCharacter::Block()
{
}

void ASpell_Sword_PlayerCharacter::Interact()
{
}

void ASpell_Sword_PlayerCharacter::BowZoom()
{
}

void ASpell_Sword_PlayerCharacter::ChangeAnimState(E_HumanoidAnimState state)
{
}

void ASpell_Sword_PlayerCharacter::RegenHealth()
{
}

void ASpell_Sword_PlayerCharacter::RegenStamina()
{
}

void ASpell_Sword_PlayerCharacter::RegenMana()
{
}

void ASpell_Sword_PlayerCharacter::ChangeCamera()
{
    if (currentCamera == FP_Camera)
    {
        FP_Camera->Deactivate();

        TP_Camera->Activate();

        currentCamera = TP_Camera;
    }
    else
    {
        TP_Camera->Deactivate();

        FP_Camera->Activate();

        currentCamera = FP_Camera;
    }
}

