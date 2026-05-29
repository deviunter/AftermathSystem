// Copyright SPYTHOONA INTERACTIVE. All rights reserved. ABYSSWHISPER is a trademark of SPYTHOONA INTERACTIVE.
// Unreal Engine and its logo are trademarks or registered trademarks of Epic Games, Inc.
// in the United States and elsewhere.All other trademarks are the property of their respective owners.

#include "Systems/AftermathSystem/Volumes/GameRegionVolume.h"
#include "Components/BrushComponent.h"
#include "Systems/AftermathSystem/Classes/AftermathSystem.h"
#include "Core/Interfaces/ActorsInterface.h"

AGameRegionVolume::AGameRegionVolume()
{
	GetBrushComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGameRegionVolume::ActorEnteredRegion);
	GetBrushComponent()->OnComponentEndOverlap.AddDynamic(this, &AGameRegionVolume::ActorLeavedRegion);
}

void AGameRegionVolume::ActorEnteredRegion(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActorsInterface::StaticClass())) return;
	if (IActorsInterface::Execute_IsPlayerCharacter(OtherActor))
	{
		GetWorld()->GetSubsystem<UAftermathSystem>()->PlayerEnteredInRegion(RegionType);
	}
}

void AGameRegionVolume::ActorLeavedRegion(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActorsInterface::StaticClass())) return;
	if (IActorsInterface::Execute_IsPlayerCharacter(OtherActor))
	{
		GetWorld()->GetSubsystem<UAftermathSystem>()->PlayerLeavedFromRegion(RegionType);
	}
}
