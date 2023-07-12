// Copyright Epic Games, Inc. All Rights Reserved.

#include "Heist_LegendGameMode.h"
#include "Heist_LegendCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHeist_LegendGameMode::AHeist_LegendGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
