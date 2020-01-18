// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "CommonStruct.h"
#include "Enemy.generated.h"

UCLASS(Blueprintable)
class UNSOUL5_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Enemy Id
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		int32 EnemyId = 0;

	// 플레이어 레벨
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		int32 EnemyLevel = 30;

	// HP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyHP = 80;

	// MP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMP = 95;

	// 최대 체력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMaxHP = 100;

	// 최대 마력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMaxMP = 100;

	// 공격력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyAttackDmg = 100;

	// 공격 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyAttackSpeed = 100;

	// 방어력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyDefense = 100;

	// 크리티컬 확률
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyCriticalRatio = 100;

	// 크리티컬 데미지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyCriticalDmg = 100;

	// 이동 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMoveSpeed = 100;

	// 달리기 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemySprintSpeed = 100;

	// 경험치
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyExp = 75;

	// Waypoint 관련
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		TArray<ATargetPoint*> WaypointArray;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		int32 WaypointIndex;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		FTimerHandle TimerHandle;

	// 공격 종류 총 갯수
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyAttack")
		int32 MaxAttackIndex;

	// 현재 공격 인덱스
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyAttack")
		int32 CurrentAttackIndex;

	// 죽었는지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bDie;

	// 맞았는지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bHit;

	// 걷고있는지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bWalking;

	// 공격중인지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bAttacking;

	// 현재 공격 스킬 정보
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemySkill")
		FEnemySkillData CurrentEnemySkillInfo;

	// 현재 스테이트 정보
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		EStateType CurrentState = EStateType::eStateType_Idle;

	// 몬스터 타입 ( 0 : 일반, 1 : 보스)
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		bool bMonsterType;

	// 드롭 아이템 id
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		int32 RewardItemId;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		TArray<EItemTemplateId> DropItemIdList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetUniqueId(uint32 Id);

	uint32 GetUniqueId();

	UFUNCTION(BlueprintCallable)
		void InitDropItemTable();

	UFUNCTION(BlueprintImplementableEvent)
		void SetVisibleTargetParticle(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent)
		void EnemyHit(int32 damage, bool isCritical);

	UFUNCTION(BlueprintImplementableEvent)
		void EnemyDie();

private:

	uint32 UniqueId;

};
