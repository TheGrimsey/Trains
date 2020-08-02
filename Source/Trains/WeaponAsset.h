// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponAsset.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EAmmoType : uint8
{
	LIGHT,
	HEAVY
};

UENUM(Blueprintable, BlueprintType)
enum class EWeaponType : uint8
{
	STANDARD,
	PROJECTILE
};

/**
 * 
 */
UCLASS(BlueprintType)
class TRAINS_API UWeaponAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float Range = 0.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float Damage = 0.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	EAmmoType AmmoType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	EWeaponType WeaponType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float Cooldown = 0.f;
};
