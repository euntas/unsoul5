// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "unsoul5GameMode.h"
#include "unsoul5PlayerController.h"
#include "unsoul5Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Enemy.h"
#include "EnemySpawn.h"
#include "Unsoul5GameInstance.h"

Aunsoul5GameMode::Aunsoul5GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = Aunsoul5PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

//void Aunsoul5GameMode::InitGameState()
//{
//
//	CharacterManager->Init();
//}

void Aunsoul5GameMode::AddSpawnActor(AEnemySpawn* Spawn)
{
	SpawnList.Add(Spawn->EnemyTag, Spawn);
}

TWeakObjectPtr<AEnemySpawn> Aunsoul5GameMode::GetSpawnActor(int32 EnemyId)
{
	return *(SpawnList.Find(EnemyId));
}
