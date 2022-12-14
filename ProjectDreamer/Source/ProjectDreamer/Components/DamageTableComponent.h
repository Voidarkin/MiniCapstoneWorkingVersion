// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"

#include "DamageTableComponent.generated.h"

/***************************************************************************************
Title:       DamageTableComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: Stores the data to determine damage resistances or damage from damage types
*****************************************************************************************/

USTRUCT(BlueprintType)
struct FType
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "-100", ClampMax = "100"))
		int32 value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAbsorb = false;
};


UCLASS(BlueprintType, Blueprintable)
class PROJECTDREAMER_API UDamageTableComponent : public UDataComponent
{
	GENERATED_BODY()

public:

	static const FString GetStaticType() { return "UDamageTableComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

public:
	// Sets default values for this component's properties
	UDamageTableComponent();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsResistance;

	UPROPERTY(EditAnywhere, BlueprintType, Blueprintable)
		TArray<FType> table;

public:
	void AddTable(UDamageTableComponent& ActorTable);
	void RemoveTable(UDamageTableComponent& ActorTable);
	TArray<FType>& GetDamageTable() { return table; }

};

