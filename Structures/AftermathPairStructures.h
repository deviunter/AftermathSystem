// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/InstancedStruct.h"
#include "Core/Enumerators/AbysswhisperTypes.h"
#include "Systems/AftermathSystem/Enumerators/AftermathEnumerators.h"
#include "Systems/WeaponSystem/Structures/WeaponStructures.h"
#include "Systems/WeatherSystem/WeatherActor.h"
#include "AftermathPairStructures.generated.h"

USTRUCT(BlueprintType)
struct FAftermathPresetActorsInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActorID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInstancedStruct ActorParameters;
};

USTRUCT(BlueprintType)
struct FAftermathGeneratedActorsInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActorID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform DefaultActorTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EActorSpawningRules SpawnRules;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERegionType SpawnRegion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SpawnLocationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInstancedStruct ActorsParameters;
};

USTRUCT(BlueprintType)
struct FAftermathStashInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StashID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStashType StashType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInstancedStruct StashParameters;
};

USTRUCT(BlueprintType)
struct FAftermathSave
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERegionType CurrentRegion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CurrentLocationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAftermathPresetActorsInfo> PresetActorsInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAftermathGeneratedActorsInfo> GeneratedActorsInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAftermathStashInfo> StashesInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, bool> SimplePresetActorsInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> CollectedNotes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> CollectedTutorials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWeaponSave> RegistredWeapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWeatherSave WeatherParameters;
};
