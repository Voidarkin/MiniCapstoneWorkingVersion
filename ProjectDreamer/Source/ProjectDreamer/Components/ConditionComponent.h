// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"

#include "ConditionComponent.generated.h"

/***************************************************************************************
Title:       ConditionComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: Data to determine healing or inflicting a condition and its success chance.
*****************************************************************************************/

UCLASS()
class PROJECTDREAMER_API UConditionComponent : public UDataComponent
{
	GENERATED_BODY()

public:

	static const FString GetStaticType() { return "UConditionComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEffect Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EConditions Conditions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SuccessChance;
};

