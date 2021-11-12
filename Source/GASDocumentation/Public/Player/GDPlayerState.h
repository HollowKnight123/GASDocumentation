// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GDPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GASDOCUMENTATION_API AGDPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AGDPlayerState();

protected:
	virtual void BeginPlay() override;
};
