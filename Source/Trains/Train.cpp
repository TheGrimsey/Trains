// Fill out your copyright notice in the Description page of Project Settings.


#include "Train.h"
#include "Rail.h"

// Sets default values
ATrain::ATrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void ATrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrain::MoveToRailPosition(float RailPosition)
{
	float AdjustedRailPosition = RailPosition;

	// Handle overflowing rail.
	if(AdjustedRailPosition > Rail->GetRailLength())
	{
		if (Rail->GetNextRail().IsValid())
		{
			// Calculate our position on this new rail.
			AdjustedRailPosition = RailPosition - Rail->GetRailLength();
			// Set next rail as our current rail.
			Rail = Rail->GetNextRail().Get();
		}
	}

	// Get new position
	FVector NewLocation;
	FRotator NewRotation;
	Rail->GetLocationAtDistance(AdjustedRailPosition, NewLocation, NewRotation);
	
	// Set position.
	SetActorLocationAndRotation(NewLocation, NewRotation);

	CurrentRailPositon = AdjustedRailPosition;

	// Update networking.
	if (HasAuthority())
	{
		ServerTrainData = FTrainData(CurrentRailPositon, Rail);
	}
}
