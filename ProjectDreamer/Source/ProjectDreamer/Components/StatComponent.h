// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enums.h"
#include "DataComponent.h"

#include "StatComponent.generated.h"

/***************************************************************************************
Title:       StatComponent
Author:      Joshua Griffis
Date:        2022/03/18
Description: The Stat component stores a table of data to add and remove stats from 
other tables, and is used to detemine Stats
*****************************************************************************************/

USTRUCT(BlueprintType)
struct FStat
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "999"))
		int value = 0;

};


UCLASS(BlueprintType, Blueprintable)
class PROJECTDREAMER_API UStatComponent : public UDataComponent
{
	GENERATED_BODY()
	
	UStatComponent();

public:

	static const FString GetStaticType() { return "UStatComponent"; }
	virtual const FString GetType() override { return GetStaticType(); }

protected:

	//UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		//UStatTable* Stats;

	UPROPERTY(EditAnywhere, BlueprintType, Blueprintable)
		TArray<FStat> table;

public:
	void AddTable(UStatComponent& ActorTable);
	void RemoveTable(UStatComponent& ActorTable);
	TArray<FStat>& GetStatTable() { return table; }
	int GetStat(FString statName);
	void SetStat(FString statName, int amount);
};
