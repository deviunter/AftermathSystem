// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#include "Systems/AftermathSystem/Volumes/GameLocationVolume.h"
#include "Components/BrushComponent.h"
#include "Systems/AftermathSystem/Classes/AftermathSystem.h"
#include "Core/Interfaces/ActorsInterface.h"

AGameLocationVolume::AGameLocationVolume()
{
	GetBrushComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGameLocationVolume::ActorEnteredLocation);
	GetBrushComponent()->OnComponentEndOverlap.AddDynamic(this, &AGameLocationVolume::ActorLeavedLocation);
}

void AGameLocationVolume::ActorEnteredLocation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActorsInterface::StaticClass())) return;
	if (IActorsInterface::Execute_IsPlayerCharacter(OtherActor))
	{
		GetWorld()->GetSubsystem<UAftermathSystem>()->PlayerEnteredInLocation(RegionType, LocationID);
	}
}

void AGameLocationVolume::ActorLeavedLocation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActorsInterface::StaticClass())) return;
	if (IActorsInterface::Execute_IsPlayerCharacter(OtherActor))
	{
		GetWorld()->GetSubsystem<UAftermathSystem>()->PlayerLeavedLocation(RegionType, LocationID);
	}
}