// Copyright 2020 Dan Kestranek.


#include "Characters/GDCharacterBase.h"
#include "Characters/GDCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGDCharacterBase::AGDCharacterBase(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UGDCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
}


// Called when the game starts or when spawned
void AGDCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}