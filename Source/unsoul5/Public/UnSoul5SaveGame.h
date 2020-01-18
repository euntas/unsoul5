// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonStruct.h"
#include "UObject/NoExportTypes.h"
#include "UnSoul5SaveGame.generated.h"

/**
 * 
 */
class UUnSoul5SaveGameData;
class UUnsoul5GameInstance;

UCLASS(Blueprintable)
class UNSOUL5_API UUnSoul5SaveGame : public UObject
{
	GENERATED_BODY()

public:

	UUnSoul5SaveGame();

	void InitSaveGame(UUnsoul5GameInstance* GameInstance);

public:

	UFUNCTION(BlueprintCallable)
		void CurrentSaveGame();
	
	UFUNCTION(BlueprintCallable)
		UUnSoul5SaveGameData* GetSaveGameData() const;

	UFUNCTION()
		void LoadData(UUnsoul5GameInstance* _GameInstance);

	UFUNCTION(BlueprintCallable)
		void SaveData(UUnsoul5GameInstance* _GameInstance);

protected:

	FString SaveSlotName;

	uint32 UserIndex;

private:

	UPROPERTY()
		UUnSoul5SaveGameData* SaveGameData;
};
