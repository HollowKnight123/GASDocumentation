// Copyright 2020 Dan Kestranek.


#include "Player/GDPlayerController.h"

// Server only
void AGDPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}

void AGDPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}
