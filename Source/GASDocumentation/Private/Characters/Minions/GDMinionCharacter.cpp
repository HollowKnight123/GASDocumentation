// Copyright 2020 Dan Kestranek.


#include "Characters/Minions/GDMinionCharacter.h"
#include "Components/CapsuleComponent.h"

AGDMinionCharacter::AGDMinionCharacter(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

void AGDMinionCharacter::BeginPlay()
{
	Super::BeginPlay();
}