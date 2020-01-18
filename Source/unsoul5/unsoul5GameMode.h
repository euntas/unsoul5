// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemy.h"
#include "unsoul5GameMode.generated.h"

class UCharacterManager;
class AEnemySpawn;


UCLASS(minimalapi)
class Aunsoul5GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Aunsoul5GameMode();

	//virtual void InitGameState() override;

	UFUNCTION()
		void AddSpawnActor(AEnemySpawn* Spawn);

	UFUNCTION()
		TWeakObjectPtr<AEnemySpawn> GetSpawnActor(int32 EnemyId);

	   
public:

	
	//스폰 리스트 저장

	UPROPERTY()
	TMap<int32, TWeakObjectPtr<AEnemySpawn>> SpawnList;
};



