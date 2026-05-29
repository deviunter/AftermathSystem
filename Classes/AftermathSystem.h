// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Core/Enumerators/AbysswhisperTypes.h"
#include "Systems/AftermathSystem/Structures/AftermathPairStructures.h"
#include "Systems/WeaponSystem/Structures/WeaponStructures.h"
#include "Systems/WeatherSystem/WeatherActor.h"
#include "AftermathSystem.generated.h"

UCLASS()
class ABYSSWHISPER_API UAftermathSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UAftermathSystem();

	// REGION & LOCATION DELEGATES

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerEnteredInRegion, ERegionType, RegionType);
	UPROPERTY(BlueprintAssignable)
	FOnPlayerEnteredInRegion OnPlayerEnteredInRegion;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerLeavedRegion, ERegionType, RegionType);
	UPROPERTY(BlueprintAssignable)
	FOnPlayerLeavedRegion OnPlayerLeavedRegion;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerEnteredInLocation, ERegionType, RegionType, FName, LocationID);
	UPROPERTY(BlueprintAssignable)
	FOnPlayerEnteredInLocation OnPlayerEnteredInLocation;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerLeavedLocation, ERegionType, RegionType, FName, LocationID);
	UPROPERTY(BlueprintAssignable)
	FOnPlayerLeavedLocation OnPlayerLeavedLocation;

	// REGION CALLABLES

	UFUNCTION(BlueprintCallable)
	void PlayerEnteredInRegion(ERegionType RegionType);

	UFUNCTION(BlueprintCallable)
	void PlayerLeavedFromRegion(ERegionType RegionType);

	UFUNCTION(BlueprintCallable)
	void PlayerEnteredInLocation(ERegionType RegionType, FName LocationID);

	UFUNCTION(BlueprintCallable)
	void PlayerLeavedLocation(ERegionType RegionType, FName LocationID);

	// REGION GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ERegionType GetCurrentRegion() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FName GetCurrentLocationID() const;

	// AFTERMATH DELEGATES

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegisterPresetActorLoaded, ERegionType, Region, FName, LocationID);
	UPROPERTY(BlueprintAssignable)
	FOnRegisterPresetActorLoaded OnRegisterPresetActorLoaded;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegisterGeneratedActorLoaded, ERegionType, Region, FName, LocationID);
	UPROPERTY(BlueprintAssignable)
	FOnRegisterGeneratedActorLoaded OnRegisterGeneratedActorLoaded;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOwnerRegionLeft, ERegionType, Region, FName, LocationID);
	UPROPERTY(BlueprintAssignable)
	FOnOwnerRegionLeft OnOwnerRegionLeft;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRegisterSimplePresetActorLoaded);
	UPROPERTY(BlueprintAssignable)
	FOnRegisterSimplePresetActorLoaded OnRegisterSimplePresetActorLoaded;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRegisterStashesLoaded);
	UPROPERTY(BlueprintAssignable)
	FOnRegisterStashesLoaded OnRegisterStashesLoaded;

	// AFTERMATH GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FAftermathPresetActorsInfo> GetRegistratedPresetActorsInfo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FAftermathGeneratedActorsInfo> GetRegistratedGeneratedActorsInfo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TMap<FName, bool> GetRegistratedSimplePresetActorsInfo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FAftermathStashInfo> GetRegistratedStashesInfo() const;

	// AFTERMATH SPECIFIC GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FAftermathPresetActorsInfo GetRegistratedPresetActorInfo(FName ActorID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetRegistratedSimplePresetActorInfo(FName ActorID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FAftermathStashInfo GetRegistratedStashInfo(FName StashID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FAftermathGeneratedActorsInfo GetRegistratedGeneratedActorInfo(FName ActorID);

	// AFTERMATH QUERRIES

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegistredPresetActorAtID(FName ActorID);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegistredSimplePresetActorAtID(FName ActorID);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegistredGeneratedActorAtID(FName ActorID);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegistredStashAtID(FName StashID);

	// AFTERMATH SETTERS

	UFUNCTION(BlueprintCallable)
	void RegisterPresetActor(FAftermathPresetActorsInfo ActorInfo);

	UFUNCTION(BlueprintCallable)
	void RegisterGeneratedActor(FAftermathGeneratedActorsInfo ActorInfo);

	UFUNCTION(BlueprintCallable)
	bool UnregisterGeneratedActor(FName ActorID);

	UFUNCTION(BlueprintCallable)
	void RegisterSimplePresetActor(FName ActorID, bool bActorState);

	UFUNCTION(BlueprintCallable)
	void RegisterStash(FAftermathStashInfo StashInfo);

	// WEAPON SETTERS

	UFUNCTION(BlueprintCallable)
	void RegisterWeapon(FWeaponSave WeaponSave);

	// WEAPON GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FWeaponSave GetRegistredWeapon(FName WeaponID);

	// WEAPON QUERRIES

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegistredWeapon(FName WeaponID);

	// COLLECTBLES SETTERS

	UFUNCTION(BlueprintCallable)
	void RegisterCollectedNote(FName NoteID);

	UFUNCTION(BlueprintCallable)
	void RegisterCollectedTutorial(FName TutorialID);

	// COLLECTBLE GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FName> GetCollectedNotes() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FName> GetCollectedTutorials() const;

	// COLLECTBLE QUERRIES

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegisteredNoteAtID(FName NoteID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasRegisteredTutorialAtID(FName TutorialID) const;

	// WEATHER SETTERS

	UFUNCTION()
	void RegisterWeatherActor(AWeatherActor* NewWeatherActor);

	UFUNCTION()
	void OnTimeChanged(ETimeState TimeState);

	// WEATHER GETTERS

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AWeatherActor* GetWeatherActor() const;

	// WEATHER DELEDATES

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeOfDayChanged, ETimeState, TimeState);
	UPROPERTY(BlueprintAssignable)
	FOnTimeOfDayChanged OnTimeOfDayChanged;

	// SAVE & LOAD

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FAftermathSave GetAftermathSystemSavedData() const;

	UFUNCTION(BlueprintCallable)
	void SetLoadedAftermathSystemData(FAftermathSave Data);

private:

	// GENERATED ACTORS LIFECYCLE

	UFUNCTION()
	void TryGenerateActors();

	UFUNCTION()
	void TryDestroyActors(ERegionType Region, FName LocationID);

	UPROPERTY()
	ERegionType CurrentRegion;

	UPROPERTY()
	FName CurrentLocationID;

	UPROPERTY()
	TArray<FAftermathPresetActorsInfo> AftermathPresetActors;
	
	UPROPERTY()
	TArray<FAftermathGeneratedActorsInfo> AftermathGeneratedActors;

	UPROPERTY()
	TMap<FName, bool> AftermathSimplePresetActors;

	UPROPERTY()
	TArray<FAftermathStashInfo> AftermathStashes;

	UPROPERTY()
	TArray<FName> CollectedNotes;

	UPROPERTY()
	TArray<FName> CollectedTutorials;

	UPROPERTY()
	TArray<FWeaponSave> RegistredWeapons;

	UPROPERTY()
	TObjectPtr<AWeatherActor> WeatherActor;

	UPROPERTY()
	ETimeState CurrentTimeState;
};
