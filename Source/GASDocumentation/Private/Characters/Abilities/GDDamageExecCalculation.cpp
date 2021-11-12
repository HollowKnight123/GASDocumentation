// Copyright 2020 Dan Kestranek.


#include "Characters/Abilities/GDDamageExecCalculation.h"

// Declare the attributes to capture and define how we want to capture them from the Source and Target.
struct GDDamageStatics
{
	GDDamageStatics()
	{
	}
};

static const GDDamageStatics& DamageStatics()
{
	static GDDamageStatics DStatics;
	return DStatics;
}

UGDDamageExecCalculation::UGDDamageExecCalculation()
{
}

void UGDDamageExecCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters & ExecutionParams, OUT FGameplayEffectCustomExecutionOutput & OutExecutionOutput) const
{
}
