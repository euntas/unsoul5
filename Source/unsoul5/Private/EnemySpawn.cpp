// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawn.h"
#include "Unsoul5GameInstance.h"
#include "Engine/World.h"
#include "unsoul5GameMode.h"
#include "CharacterManager.h"
#include "EnemySpawn.h"

// Sets default values
AEnemySpawn::AEnemySpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bFrist = false;

}

// Called when the game starts or when spawned
void AEnemySpawn::BeginPlay()
{
	Super::BeginPlay();

	Aunsoul5GameMode* GameMode = Cast<Aunsoul5GameMode>(GetWorld()->GetAuthGameMode());
	
	GameMode->AddSpawnActor(this);

	//CreateEnemy();
}

// Called every frame
void AEnemySpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;


	if (!bFrist)
	{
		CreateEnemy();
		bFrist = true;
	}

	if (RespawnTime != 0 && Time > CurrentTime + RespawnTime)
	{
		CurrentTime = Time;

		CreateEnemy();
	}	
}

void AEnemySpawn::CreateEnemy()
{
	while (EnemyCount < EnemyMaxCount)
	{
		//respwan enemy to gamemode
		if (UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(GetGameInstance()))
		{
			GameInstance->GetCharacterManager()->AddCharacterList(SpawnMonster());

			EnemyCount++;
		}
	}
}

void AEnemySpawn::DeleteEnemy()
{
	if (EnemyCount != 0)
	{
		EnemyCount--;
	}
}

void AEnemySpawn::SelectMonster()
{
}

