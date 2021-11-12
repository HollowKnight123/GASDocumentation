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
class GASDOCUMENTATION_API AGDPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AGDPlayerState();

	// Implement IAbilitySystemInterface
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UGDAttributeSetBase* GetAttributeSetBase() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState")
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumenation|GDPlayerState|UI")
	void ShowAbilityConfirmCancelText(bool ShowText);


	/**
	* Getters for attributes from GDAttributeSetBase. Returns Current Value unless otherwise specified.
	*/

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState|Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState|Attributes")
	float GetHealthRegenRate() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState|Attributes")
	float GetMoveSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "GASDocumentation|GDPlayerState|Attributes")
	int32 GetCharacterLevel() const;

protected:
	UPROPERTY()
	class UGDAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UGDAttributeSetBase* AttributeSetBase;

	FGameplayTag DeadTag;

	FDelegateHandle HealthChangedDelegateHandle;
	FDelegateHandle MaxHealthChangedDelegateHandle;
	FDelegateHandle HealthRegenRateChangedDelegateHandle;
	FDelegateHandle CharacterLevelChangedDelegateHandle;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Attribute changed callbacks
	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	virtual void MaxHealthChanged(const FOnAttributeChangeData& Data);
	virtual void HealthRegenRateChanged(const FOnAttributeChangeData& Data);
	virtual void CharacterLevelChanged(const FOnAttributeChangeData& Data);

	// Tag change callbacks
	virtual void StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
};
