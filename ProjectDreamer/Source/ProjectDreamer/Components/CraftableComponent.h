// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"
#include "../Inventory.h"
#include "../Item.h"

#include "CraftableComponent.generated.h"

/***************************************************************************************
Title:       CraftableComponent
Author:      Joshua Griffis
Date:        2022/03/22
Description: Tells the game that the item with this component can be crafted using the materials listed.
*****************************************************************************************/

USTRUCT(BlueprintType)
struct FCraftingMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "99"))
		int32 amount = 0;

};

UCLASS(BlueprintType, Blueprintable)
class PROJECTDREAMER_API UCraftableComponent : public UDataComponent
{
	GENERATED_BODY()

public:

	static const FString GetStaticType() { return "UCraftableComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

public:

	UCraftableComponent();


protected:

	UPROPERTY(EditAnywhere, BlueprintType, Blueprintable)
		TArray<FCraftingMaterial> Ingredients;

public:

	TArray<FCraftingMaterial> GetMaterials() { return Ingredients; }

};


