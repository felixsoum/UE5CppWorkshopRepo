// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5CppWorkshopPickUpComponent.h"

UUE5CppWorkshopPickUpComponent::UUE5CppWorkshopPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UUE5CppWorkshopPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UUE5CppWorkshopPickUpComponent::OnSphereBeginOverlap);
}

void UUE5CppWorkshopPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AUE5CppWorkshopCharacter* Character = Cast<AUE5CppWorkshopCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
