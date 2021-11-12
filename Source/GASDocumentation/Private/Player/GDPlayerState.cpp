// Copyright 2020 Dan Kestranek.


#include "Player/GDPlayerState.h"
#include "Characters/Abilities/AttributeSets/GDAttributeSetBase.h"
#include "Characters/Abilities/GDAbilitySystemComponent.h"
#include "Characters/Heroes/GDHeroCharacter.h"
#include "Player/GDPlayerController.h"
#include "UI/GDFloatingStatusBarWidget.h"
#include "UI/GDHUDWidget.h"

AGDPlayerState::AGDPlayerState()
{
}

void AGDPlayerState::BeginPlay()
{
	Super::BeginPlay();
}