// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CommonStruct.h"
#include "SkillManager.h"
#include "unsoul5Character.generated.h"


UCLASS(Blueprintable)
class Aunsoul5Character : public ACharacter
{
	GENERATED_BODY()

public:
	Aunsoul5Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;


	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	FORCEINLINE class UTargetingComponent* GetTargetingSystem() { return TargetComponent; }

	FORCEINLINE class URangeAttack* GetRangeAttack() { return RangeAttack; }


	// 플레이어 레벨
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 PlayerLevel;

	// HP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 HP;

	// MP
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 MP;

	// 최대 체력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 MaxHP;

	// 최대 마력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 MaxMP;

	// 공격력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float AttackDmg;

	// 공격 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 AttackSpeed;

	// 방어력
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float Defense;

	// 크리티컬 확률
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float CriticalRatio;

	// 크리티컬 데미지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float CriticalDmg;

	// 이동 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float MoveSpeed;

	// 달리기 속도
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		float SprintSpeed;

	// 경험치
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 Exp;

	// 최대 경험치
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 MaxExp;

	// 보유 스킬포인트
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		int32 Skillpoint;

	// 맞았는지
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "CharacterStat")
		bool bHit;

	// Current Attack Index : Atk1 = 1, Atk2 = 2, Atk3 = 3
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Attack")
		int32 CurrentAttackIndex;

	// IsCombo
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Attack")
		bool bAttackCombo;

	// IsSkill
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Attack")
		bool bSkillCombo;

	//Action State
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Attack")
		bool bActionStop;

	//Save SkillButton Index
	UPROPERTY(BlueprintReadWrite, EditAnyWhere)
		int32 skillBtnIndex;

	float DeltaTime;

	float CurrentDeltaTime;	

protected:

	virtual void BeginPlay() override;
	
public:

	//UFUNCTION(BlueprintCallable)
	//void InitCharacter(int32 Level);

	UFUNCTION()
		USceneComponent* GetRootComponent();

	UFUNCTION(BlueprintCallable)
		void SetTarget();

	UFUNCTION(BlueprintCallable)
		bool CheckAttack();
	
//	UFUNCTION(BlueprintCallable)
	//	void PlayerAttack();

	UFUNCTION(BlueprintImplementableEvent)
		void MoveStop();
		//void MoveStop(ESkillTemplateId inSkillId);

	UFUNCTION(BlueprintImplementableEvent)
		float OnAttack();

	//준혁 테스트
	UFUNCTION(BlueprintImplementableEvent)
		float OnActiveSkill1();

	UFUNCTION(BlueprintImplementableEvent)
		float OnActiveSkill2();

	UFUNCTION(BlueprintImplementableEvent)
		float OnActiveSkill3();

	UFUNCTION(BlueprintImplementableEvent)
		float OnActiveSkill4();

	UPROPERTY(BlueprintReadWrite)
		USkillManager* skillMgr;
	//준혁 테스트

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent)
		void CharacterHit(int32 damage, bool isCritical);

	// HUD 퀘스트 텍스트 갱신 위함 
	UFUNCTION(BlueprintImplementableEvent)
		void RefreshQuestTextForHud();


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* SearchToCollsion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
		class UTargetingComponent* TargetComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
		class URangeAttack* RangeAttack;

};

