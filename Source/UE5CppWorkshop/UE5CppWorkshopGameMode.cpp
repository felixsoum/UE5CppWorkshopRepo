// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5CppWorkshopGameMode.h"
#include "UE5CppWorkshopCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5CppWorkshopGameMode::AUE5CppWorkshopGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
