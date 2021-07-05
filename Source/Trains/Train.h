// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Train.generated.h"

struct FTrainData
{
	float Position = 0.f;
	class ARail* Rail;

	FTrainData(float InPosition, class ARail* InRail)
	{
		Position = InPosition;
		Rail = InRail;
	}
};

UCLASS()
class TRAINS_API ATrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrain();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveToRailPosition(float RailPosition);

	class ARail* Rail;
	float CurrentRailPositon = 0.f;
	FTrainData ServerTrainData;
};
