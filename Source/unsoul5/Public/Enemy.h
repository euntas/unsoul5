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

	// �÷��̾� ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		int32 EnemyLevel = 30;

	// HP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyHP = 80;

	// MP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMP = 95;

	// �ִ� ü��
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMaxHP = 100;

	// �ִ� ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMaxMP = 100;

	// ���ݷ�
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyAttackDmg = 100;

	// ���� �ӵ�
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyAttackSpeed = 100;

	// ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyDefense = 100;

	// ũ��Ƽ�� Ȯ��
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyCriticalRatio = 100;

	// ũ��Ƽ�� ������
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyCriticalDmg = 100;

	// �̵� �ӵ�
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyMoveSpeed = 100;

	// �޸��� �ӵ�
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemySprintSpeed = 100;

	// ����ġ
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		float EnemyExp = 75;

	// Waypoint ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		TArray<ATargetPoint*> WaypointArray;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		int32 WaypointIndex;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Waypoint")
		FTimerHandle TimerHandle;

	// ���� ���� �� ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyAttack")
		int32 MaxAttackIndex;

	// ���� ���� �ε���
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyAttack")
		int32 CurrentAttackIndex;

	// �׾�����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bDie;

	// �¾Ҵ���
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bHit;

	// �Ȱ��ִ���
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bWalking;

	// ����������
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		bool bAttacking;

	// ���� ���� ��ų ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemySkill")
		FEnemySkillData CurrentEnemySkillInfo;

	// ���� ������Ʈ ����
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyState")
		EStateType CurrentState = EStateType::eStateType_Idle;

	// ���� Ÿ�� ( 0 : �Ϲ�, 1 : ����)
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "EnemyStat")
		bool bMonsterType;

	// ��� ������ id
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
