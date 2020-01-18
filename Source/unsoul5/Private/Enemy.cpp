// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Enemy.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Unsoul5GameInstance.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::InitDropItemTable()
{
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(GetGameInstance());
	DropItemIdList = GameInstance->GetLevelEquipItemTables(EnemyLevel);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::SetUniqueId(uint32 Id)
{
	UniqueId = Id;
}

uint32 AEnemy::GetUniqueId()
{
	return UniqueId;
}


