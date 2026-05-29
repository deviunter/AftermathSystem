// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

// Trigger volume that defines a specific location within a region.
// When the player enters or leaves this volume, notifies the AftermathSystem
// to update the current location ID and broadcast the corresponding delegates.
// Place this volume on the level and set the RegionType and LocationID in instance properties.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Core/Enumerators/AbysswhisperTypes.h"
#include "GameLocationVolume.generated.h"

UCLASS()
class ABYSSWHISPER_API AGameLocationVolume : public AVolume
{
	GENERATED_BODY()

public:

	AGameLocationVolume();

	UPROPERTY(EditInstanceOnly)
	FName LocationID;

	UPROPERTY(EditInstanceOnly)
	ERegionType RegionType;

private:

	UFUNCTION()
	void ActorEnteredLocation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void ActorLeavedLocation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
