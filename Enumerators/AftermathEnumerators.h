// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EStashType : uint8
{
	Default,
	EmptyStash,
	FilledStash,
	VirginStash
};

UENUM(BlueprintType)
enum class ETimeState : uint8
{
	Dawn,
	Day,
	Dusk,
	Night
};