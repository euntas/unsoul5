// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterManager.h"
#include "Enemy.h"
#include "EnemySpawn.h"

UCharacterManager::UCharacterManager()
{
	CharacterList.Empty();
}

void UCharacterManager::BeginDestroy()
{
	Release();


	Super::BeginDestroy();
}

void UCharacterManager::Init()
{
}

void UCharacterManager::Release()
{
	if (CharacterList.Num() != 0)
	{
		CharacterList.Empty();
	}
}

void UCharacterManager::AddCharacterList(AActor* ACharacter)
{
	if (ACharacter == nullptr)
	{
		return;
	}
	
	if (!CharacterList.Contains(ACharacter))
	{
		CharacterList.Add(ACharacter);
	}
}

void UCharacterManager::RemoveCharacterList(AActor* ACharacter)
{
	if (ACharacter == nullptr)
	{
		return;
	}

	if (CharacterList.Contains(ACharacter))
	{				
		CharacterList.Remove(ACharacter);
	}
}
