// Copyright 2020 Dan Kestranek.


#include "Player/GDPlayerController.h"
#include "AbilitySystemComponent.h"
#include "Characters/Heroes/GDHeroCharacter.h"
#include "Player/GDPlayerState.h"
#include "UI/GDDamageTextWidgetComponent.h"
#include "UI/GDHUDWidget.h"

void AGDPlayerController::CreateHUD()
{
}

UGDHUDWidget * AGDPlayerController::GetHUD()
{
	return UIHUDWidget;
}

void AGDPlayerController::ShowDamageNumber_Implementation(float DamageAmount, AGDCharacterBase* TargetCharacter)
{
}

bool AGDPlayerController::ShowDamageNumber_Validate(float DamageAmount, AGDCharacterBase* TargetCharacter)
{
	return true;
}

void AGDPlayerController::SetRespawnCountdown_Implementation(float RespawnTimeRemaining)
{
}

bool AGDPlayerController::SetRespawnCountdown_Validate(float RespawnTimeRemaining)
{
	return true;
}

// Server only
void AGDPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGDPlayerState* PS = GetPlayerState<AGDPlayerState>();
	if (PS)
	{
		// Init ASC with PS (Owner) and our new Pawn (AvatarActor)
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, InPawn);
	}
}

void AGDPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}
