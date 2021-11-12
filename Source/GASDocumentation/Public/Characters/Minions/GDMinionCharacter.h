// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GDCharacterBase.h"
#include "GameplayEffectTypes.h"
#include "GDMinionCharacter.generated.h"

/**
 * An AI controlled minion character.
 */
UCLASS()
class GASDOCUMENTATION_API AGDMinionCharacter : public AGDCharacterBase
{
	GENERATED_BODY()

public:
	AGDMinionCharacter(const class FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
};
