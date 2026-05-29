// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#include "Systems/AftermathSystem/Classes/AftermathSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Core/GameInstance/INS.h"

UAftermathSystem::UAftermathSystem()
{
}

TArray<FAftermathPresetActorsInfo> UAftermathSystem::GetRegistratedPresetActorsInfo() const
{
	return AftermathPresetActors;
}

TArray<FAftermathGeneratedActorsInfo> UAftermathSystem::GetRegistratedGeneratedActorsInfo() const
{
	return AftermathGeneratedActors;
}

TMap<FName, bool> UAftermathSystem::GetRegistratedSimplePresetActorsInfo() const
{
	return AftermathSimplePresetActors;
}

TArray<FAftermathStashInfo> UAftermathSystem::GetRegistratedStashesInfo() const
{
	return AftermathStashes;
}

FAftermathPresetActorsInfo UAftermathSystem::GetRegistratedPresetActorInfo(FName ActorID) const
{
	for (int32 i = 0; i < AftermathPresetActors.Num(); i++)
	{
		if (AftermathPresetActors[i].ActorID == ActorID) return AftermathPresetActors[i];
	}
	return FAftermathPresetActorsInfo();
}

bool UAftermathSystem::GetRegistratedSimplePresetActorInfo(FName ActorID) const
{
	const bool* Found = AftermathSimplePresetActors.Find(ActorID);
	return Found ? *Found : false;
}

FAftermathStashInfo UAftermathSystem::GetRegistratedStashInfo(FName StashID) const
{
	for (int32 i = 0; i < AftermathStashes.Num(); i++)
	{
		if (AftermathStashes[i].StashID == StashID) return AftermathStashes[i];
	}
	return FAftermathStashInfo();
}

FAftermathGeneratedActorsInfo UAftermathSystem::GetRegistratedGeneratedActorInfo(FName ActorID)
{
	for (int32 i = 0; i < AftermathGeneratedActors.Num(); i++)
	{
		if (AftermathGeneratedActors[i].ActorID == ActorID) return AftermathGeneratedActors[i];
	}
	return FAftermathGeneratedActorsInfo();
}

bool UAftermathSystem::HasRegistredPresetActorAtID(FName ActorID)
{
	for (int32 i = 0; i < AftermathPresetActors.Num(); i++)
	{
		if (AftermathPresetActors[i].ActorID == ActorID) return true;
	}
	return false;
}

bool UAftermathSystem::HasRegistredSimplePresetActorAtID(FName ActorID)
{
	return AftermathSimplePresetActors.Contains(ActorID);
}

bool UAftermathSystem::HasRegistredGeneratedActorAtID(FName ActorID)
{
	for (int32 i = 0; i < AftermathGeneratedActors.Num(); i++)
	{
		if (AftermathGeneratedActors[i].ActorID == ActorID) return true;
	}
	return false;
}

bool UAftermathSystem::HasRegistredStashAtID(FName StashID)
{
	for (int32 i = 0; i < AftermathStashes.Num(); i++)
	{
		if (AftermathStashes[i].StashID == StashID) return true;
	}
	return false;
}

void UAftermathSystem::RegisterPresetActor(FAftermathPresetActorsInfo ActorInfo)
{
	for (int32 i = 0; i < AftermathPresetActors.Num(); i++)
	{
		if (AftermathPresetActors[i].ActorID == ActorInfo.ActorID) AftermathPresetActors.RemoveAt(i);
	}
	AftermathPresetActors.Add(ActorInfo);
}

void UAftermathSystem::RegisterGeneratedActor(FAftermathGeneratedActorsInfo ActorInfo)
{
	for (int32 i = 0; i < AftermathGeneratedActors.Num(); i++)
	{
		if (AftermathGeneratedActors[i].ActorID == ActorInfo.ActorID) AftermathGeneratedActors.RemoveAt(i);
	}
	AftermathGeneratedActors.Add(ActorInfo);
}

bool UAftermathSystem::UnregisterGeneratedActor(FName ActorID)
{
	for (int32 i = 0; i < AftermathGeneratedActors.Num(); i++)
	{
		if (AftermathGeneratedActors[i].ActorID == ActorID)
		{
			AftermathGeneratedActors.RemoveAt(i);
			return true;
		}
	}
	return false;
}

void UAftermathSystem::RegisterSimplePresetActor(FName ActorID, bool bActorState)
{
	if (AftermathSimplePresetActors.Contains(ActorID)) AftermathSimplePresetActors.Remove(ActorID);
	AftermathSimplePresetActors.Add(ActorID, bActorState);
}

void UAftermathSystem::RegisterStash(FAftermathStashInfo StashInfo)
{
	for (int32 i = 0; i < AftermathStashes.Num(); i++)
	{
		if (AftermathStashes[i].StashID == StashInfo.StashID) AftermathStashes.RemoveAt(i);
	}
	AftermathStashes.Add(StashInfo);
}

void UAftermathSystem::RegisterWeapon(FWeaponSave WeaponSave)
{
	if (HasRegistredWeapon(WeaponSave.WeaponID))
	{
		for (int32 i = 0; i < RegistredWeapons.Num(); i++)
		{
			if (RegistredWeapons[i].WeaponID == WeaponSave.WeaponID)
			{
				RegistredWeapons.RemoveAt(i);
				break;
			}
		}
	}
	RegistredWeapons.Add(WeaponSave);
}

FWeaponSave UAftermathSystem::GetRegistredWeapon(FName WeaponID)
{
	for (int32 i = 0; i < RegistredWeapons.Num(); i++)
	{
		if (RegistredWeapons[i].WeaponID == WeaponID) return RegistredWeapons[i];
	}
	return FWeaponSave();
}

bool UAftermathSystem::HasRegistredWeapon(FName WeaponID)
{
	for (int32 i = 0; i < RegistredWeapons.Num(); i++)
	{
		if (RegistredWeapons[i].WeaponID == WeaponID) return true;
	}
	return false;
}

void UAftermathSystem::RegisterCollectedNote(FName NoteID)
{
	if (HasRegisteredNoteAtID(NoteID)) return;
	CollectedNotes.Add(NoteID);
}

void UAftermathSystem::RegisterCollectedTutorial(FName TutorialID)
{
	if (HasRegisteredTutorialAtID(TutorialID)) return;
	Cast<UINS>(UGameplayStatics::GetGameInstance(GetWorld()))->CallTutorial(TutorialID);
	CollectedTutorials.Add(TutorialID);
}

TArray<FName> UAftermathSystem::GetCollectedNotes() const
{
	return CollectedNotes;
}

TArray<FName> UAftermathSystem::GetCollectedTutorials() const
{
	return CollectedTutorials;
}

bool UAftermathSystem::HasRegisteredNoteAtID(FName NoteID) const
{
	return CollectedNotes.Contains(NoteID);
}

bool UAftermathSystem::HasRegisteredTutorialAtID(FName TutorialID) const
{
	return CollectedTutorials.Contains(TutorialID);
}

void UAftermathSystem::RegisterWeatherActor(AWeatherActor* NewWeatherActor)
{
	WeatherActor = NewWeatherActor;
}

void UAftermathSystem::OnTimeChanged(ETimeState TimeState)
{
	if (TimeState != CurrentTimeState)
	{
		CurrentTimeState = TimeState;
		if (OnTimeOfDayChanged.IsBound()) OnTimeOfDayChanged.Broadcast(TimeState);
	}
}

AWeatherActor* UAftermathSystem::GetWeatherActor() const
{
	return WeatherActor;
}

FAftermathSave UAftermathSystem::GetAftermathSystemSavedData() const
{
	FAftermathSave LocalSavedData;
	LocalSavedData.CurrentRegion = CurrentRegion;
	LocalSavedData.CurrentLocationID = CurrentLocationID;
	LocalSavedData.PresetActorsInfo = AftermathPresetActors;
	LocalSavedData.GeneratedActorsInfo = AftermathGeneratedActors;
	LocalSavedData.SimplePresetActorsInfo = AftermathSimplePresetActors;
	LocalSavedData.StashesInfo = AftermathStashes;
	LocalSavedData.CollectedNotes = CollectedNotes;
	LocalSavedData.CollectedTutorials = CollectedTutorials;
	LocalSavedData.RegistredWeapons = RegistredWeapons;
	if(IsValid(WeatherActor)) LocalSavedData.WeatherParameters = WeatherActor->SaveWeather();
	return LocalSavedData;
}

void UAftermathSystem::SetLoadedAftermathSystemData(FAftermathSave Data)
{
	CurrentRegion = Data.CurrentRegion;
	CurrentLocationID = Data.CurrentLocationID;
	AftermathPresetActors.Empty();
	AftermathPresetActors = Data.PresetActorsInfo;
	if (OnRegisterPresetActorLoaded.IsBound()) OnRegisterPresetActorLoaded.Broadcast(CurrentRegion, CurrentLocationID);
	AftermathGeneratedActors.Empty();
	AftermathGeneratedActors = Data.GeneratedActorsInfo;
	AftermathSimplePresetActors.Empty();
	AftermathSimplePresetActors = Data.SimplePresetActorsInfo;
	if (OnRegisterSimplePresetActorLoaded.IsBound()) OnRegisterSimplePresetActorLoaded.Broadcast();
	AftermathStashes.Empty();
	AftermathStashes = Data.StashesInfo;
	if (OnRegisterStashesLoaded.IsBound()) OnRegisterStashesLoaded.Broadcast();
	CollectedNotes = Data.CollectedNotes;
	CollectedTutorials = Data.CollectedTutorials;
	if (IsValid(WeatherActor)) WeatherActor->LoadWeather(Data.WeatherParameters);
	RegistredWeapons = Data.RegistredWeapons;
}

void UAftermathSystem::TryGenerateActors()
{
	EActorSpawningRules SpawnRules = EActorSpawningRules::SpawnAtLocation;
	if (CurrentLocationID.IsNone()) SpawnRules = EActorSpawningRules::SpawnAtRegion;
	TArray<FAftermathGeneratedActorsInfo> SpawningActors;
	for (FAftermathGeneratedActorsInfo LocalInfo : AftermathGeneratedActors)
	{
		if (LocalInfo.SpawnRules != SpawnRules) continue;
		if (LocalInfo.SpawnRegion == CurrentRegion && LocalInfo.SpawnLocationID == CurrentLocationID) SpawningActors.Add(LocalInfo);
	}
	for (FAftermathGeneratedActorsInfo LocalGenerateInfo : SpawningActors)
	{
		TObjectPtr<AActor> GeneratedActor = GetWorld()->SpawnActor<AActor>(LocalGenerateInfo.ActorClass, LocalGenerateInfo.DefaultActorTransform);
		IActorsInterface::Execute_SetActorPresenceType(GeneratedActor, EActorPresenceType::Spawned);
		IActorsInterface::Execute_AttachActorToTerritory(GeneratedActor, CurrentRegion, CurrentLocationID);
		UnregisterGeneratedActor(LocalGenerateInfo.ActorID);
		FAftermathGeneratedActorsInfo NewInfo = LocalGenerateInfo;
		NewInfo.ActorID = FName(*GetPathNameSafe(GeneratedActor));
		RegisterGeneratedActor(NewInfo);
	}
	if (OnRegisterGeneratedActorLoaded.IsBound()) OnRegisterGeneratedActorLoaded.Broadcast(CurrentRegion, CurrentLocationID);
}

void UAftermathSystem::TryDestroyActors(ERegionType Region, FName LocationID)
{
	if (OnOwnerRegionLeft.IsBound()) OnOwnerRegionLeft.Broadcast(Region, LocationID);
}

void UAftermathSystem::PlayerEnteredInRegion(ERegionType RegionType)
{
	CurrentRegion = RegionType;
	TryGenerateActors();
	if (OnRegisterPresetActorLoaded.IsBound()) OnRegisterPresetActorLoaded.Broadcast(CurrentRegion, NAME_None);
	if (OnPlayerEnteredInRegion.IsBound()) OnPlayerEnteredInRegion.Broadcast(RegionType);
}

void UAftermathSystem::PlayerLeavedFromRegion(ERegionType RegionType)
{
	CurrentRegion = ERegionType::Default;
	TryDestroyActors(RegionType, NAME_None);
	if (OnPlayerLeavedRegion.IsBound()) OnPlayerLeavedRegion.Broadcast(RegionType);
}

void UAftermathSystem::PlayerEnteredInLocation(ERegionType RegionType, FName LocationID)
{
	CurrentLocationID = LocationID;
	TryGenerateActors();
	if (OnRegisterPresetActorLoaded.IsBound()) OnRegisterPresetActorLoaded.Broadcast(CurrentRegion, CurrentLocationID);
	if (OnPlayerEnteredInLocation.IsBound()) OnPlayerEnteredInLocation.Broadcast(RegionType, LocationID);
}

void UAftermathSystem::PlayerLeavedLocation(ERegionType RegionType, FName LocationID)
{
	CurrentLocationID = NAME_None;
	TryDestroyActors(RegionType, LocationID);
	if (OnPlayerLeavedLocation.IsBound()) OnPlayerLeavedLocation.Broadcast(RegionType, LocationID);
}

ERegionType UAftermathSystem::GetCurrentRegion() const
{
	return CurrentRegion;
}

FName UAftermathSystem::GetCurrentLocationID() const
{
	return CurrentLocationID;
}
