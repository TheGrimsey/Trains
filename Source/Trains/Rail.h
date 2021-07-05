// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rail.generated.h"

UCLASS()
class TRAINS_API ARail : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARail();

	TSoftObjectPtr<ARail> NextRail;

	TSoftObjectPtr<ARail> GetNextRail() { return NextRail; }
	float GetRailLength() { return 100.f; }

	void GetLocationAtDistance(float Distance, FVector& Location, FRotator& Roation);
};
