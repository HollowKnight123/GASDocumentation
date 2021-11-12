// Copyright 2020 Dan Kestranek.


#include "Player/GDPlayerController.h"
#include "AbilitySystemComponent.h"
#include "Characters/Heroes/GDHeroCharacter.h"
#include "Player/GDPlayerState.h"
#include "UI/GDDamageTextWidgetComponent.h"
#include "UI/GDHUDWidget.h"

// Server only
void AGDPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AGDPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}
