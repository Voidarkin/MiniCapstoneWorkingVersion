// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterData.generated.h"

/***************************************************************************************
Title:       CharacterData
Author:      Joshua Griffis
Date:        2022/03/18
Description: Used to store the data on the different player characters in the game.
*****************************************************************************************/

//TODO: Move to Data folder

class UStatComponent;
class UConditionTableComponent;
class UDamageTableComponent;
class UImage;
class UStaticMesh;
class UItem;


UCLASS(Blueprintable)
class PROJECTDREAMER_API UCharacterData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UCharacterData();
	//UEnemy(FString n); //add more later

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1", ClampMax = "99"))
		int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
		int EXP;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UStatComponent* Stats;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UConditionTableComponent* ConditionResistances;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UDamageTableComponent* DamageResistances;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//	TArray<Skill*> Skills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* FaceImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* BodyImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Weapon = "Empty";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Accessory_1 = "Empty";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Accessory_2 = "Empty";

public:

	UFUNCTION()
		FString GetCharacterName() { return Name; }

	UFUNCTION()
		FString GetCharacterDescription() { return Description; }

	UFUNCTION()
		int GetLevel() { return Level; }

	UFUNCTION()
		int GetExperience() { return EXP; }

	UFUNCTION()
		UStatComponent* GetCharacterStats() { return Stats; }

	UFUNCTION()
		UConditionTableComponent* GetCharacterConditionResistances() { return ConditionResistances; }

	UFUNCTION()
		UDamageTableComponent* GetCharacterDamageResistances() { return DamageResistances; }

	//UFUNCTION()
	//	TArray<Skill*> GetEnemySkills() { return Skills; }

	UFUNCTION()
		UTexture2D* GetCharacterFaceImage() { return FaceImage; }

	UFUNCTION()
		UTexture2D* GetCharacterBodyImage() { return BodyImage; }

	UFUNCTION()
		UStaticMesh* GetCharacterMesh() { return Mesh; }

	UFUNCTION()
		void SetWeapon(FString item) { Weapon = item; }
	UFUNCTION()				  				   
		void SetFirstAccessory(FString item) { Accessory_1 = item; }
	UFUNCTION()				  				   
		void SetSecondAccessory(FString item) { Accessory_2 = item; }

	UFUNCTION()
		FString GetWeapon() { return Weapon; }
	UFUNCTION()
		FString GetFirstAccessory() { return Accessory_1; }
	UFUNCTION()
		FString GetSecondAccessory() { return Accessory_2; }

};
