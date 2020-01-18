// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonStruct.h"
#include "BattleLogic.generated.h"

class Aunsoul5Character;
class AEnemy;
/**
 * 
 */
UCLASS(Blueprintable)
class UNSOUL5_API UBattleLogic : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		void EnemyBattle(AActor* _APlayer, AActor* _AEnemy);

	UFUNCTION(BlueprintCallable)
		void Battle(AActor* ATargeter, AActor* ATargeting,FSkillData SkillData);

	void SaveCharacterData(Aunsoul5Character* _APlayer);

	bool CriticalAttack(float CiritalPercentage);

	int32 GetTotalPlayerDamage(AActor* ATargeter);

	int32 GetTotalPlayerDefense(AActor* ATargeter);
	
	void Drop(AEnemy* Enemy);

	bool TargetLength(AActor* ATargeter, AActor* ATargeting, float AttackLength);
	
};
