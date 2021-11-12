// Copyright 2020 Dan Kestranek.


#include "Player/GDPlayerController.h"
#include "AbilitySystemComponent.h"
#include "Characters/Heroes/GDHeroCharacter.h"
#include "Player/GDPlayerState.h"
#include "UI/GDDamageTextWidgetComponent.h"
#include "UI/GDHUDWidget.h"

void AGDPlayerController::CreateHUD()
{
	// Only create once
	if (UIHUDWidget)
	{
		return;
	}

	if (!UIHUDWidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing UIHUDWidgetClass. Please fill in on the Blueprint of the PlayerController."), *FString(__FUNCTION__));
		return;
	}

	// Only create a HUD for local player
	if (!IsLocalPlayerController())
	{
		return;
	}

	// Need a valid PlayerState to get attributes from
	AGDPlayerState* PS = GetPlayerState<AGDPlayerState>();
	if (!PS)
	{
		return;
	}

	UIHUDWidget = CreateWidget<UGDHUDWidget>(this, UIHUDWidgetClass);
	UIHUDWidget->AddToViewport();

	DamageNumberClass = StaticLoadClass(UObject::StaticClass(), nullptr, TEXT("/Game/GASDocumentation/UI/WC_DamageText.WC_DamageText_C"));
	if (!DamageNumberClass)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Failed to find DamageNumberClass. If it was moved, please update the reference location in C++."), *FString(__FUNCTION__));
	}
}

UGDHUDWidget * AGDPlayerController::GetHUD()
{
	return UIHUDWidget;
}

void AGDPlayerController::ShowDamageNumber_Implementation(float DamageAmount, AGDCharacterBase* TargetCharacter)
{
	if (TargetCharacter)
	{
		UGDDamageTextWidgetComponent* DamageText = NewObject<UGDDamageTextWidgetComponent>(TargetCharacter, DamageNumberClass);
		DamageText->RegisterComponent();
		DamageText->AttachToComponent(TargetCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		DamageText->SetDamageText(DamageAmount);
	}
}

bool AGDPlayerController::ShowDamageNumber_Validate(float DamageAmount, AGDCharacterBase* TargetCharacter)
{
	return true;
}

void AGDPlayerController::SetRespawnCountdown_Implementation(float RespawnTimeRemaining)
{
	if (UIHUDWidget)
	{
		UIHUDWidget->SetRespawnCountdown(RespawnTimeRemaining);
	}
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

	// For edge cases where the PlayerState is repped before the Hero is possessed.
	CreateHUD();
}
