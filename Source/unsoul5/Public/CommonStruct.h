//Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonStruct.generated.h"

/**
 *
 */
UENUM(Blueprintable)
enum class ESkillTemplateId : uint8
{
	eSkillTemplateId_None = 0,
	eSkillTemplateId_Passive1 = 101,
	eSkillTemplateId_Passive2 = 102,
	eSkillTemplateId_Passive3 = 103,
	eSkillTemplateId_Passive4 = 104,
	eSkillTemplateId_Active1 = 201,
	eSkillTemplateId_Active12 = 202,
	eSkillTemplateId_Active2 = 203,
	eSkillTemplateId_Active22 = 204,
	eSkillTemplateId_Active3 = 205,
	eSkillTemplateId_Active32 = 206,
	eSkillTemplateId_Active4 = 207,
	eSkillTemplateId_Active42 = 208,
	eSkillTemplateId_Cnt
};

UENUM(Blueprintable)
enum class ETargetType : uint8
{
	eTargetType_None,
	eTargetType_Target,
	eTargetType_AOE,
	eTargetType_Cnt
};

UENUM(Blueprintable)
enum class EAreaType : uint8
{
	eAreaType_None,
	//원형
	eAreaType_Circle,
	//사각형
	eAreaType_Rectangle,
	eAreaType_Cnt
};

UENUM(Blueprintable)
enum class EEffectId : uint8
{
	eEffectId_None,
	//기절
	eEffectId_PassOut,
	//빙결
	eEffectId_Freeze,
	//화상
	eEffectId_Burn,
	//드레인
	eEffectId_Drain,
	eEffectId_Cnt
};


UENUM(Blueprintable)
enum class EEquipItemType : uint8
{
	eEquipItemType_None,
	eEquipItemType_Weapon,
	eEquipItemType_Helmet,
	eEquipItemType_Armor,
	eEquipItemType_Shoes,
	eEquipItemType_Cnt
};

UENUM(Blueprintable)
enum class EPotionType : uint8
{
	ePotionType_None,
	ePotionType_LowPotion,
	ePotionType_MiddlePotion,
	ePotionType_HighPotion,
	ePotionType_Cnt
};

UENUM(Blueprintable)
enum class EItemTemplateId : uint8
{
	eItemTemplateId_None = 0,
	eItemTemplateId_LowPotion = 1,
	eItemTemplateId_MiddlePotion = 2,
	eItemTemplateId_HighPotion = 3,
	eItemTemplateId_NormalWeapon = 10,
	eItemTemplateId_SuperWeapon = 11,
	eItemTemplateId_HyperWeapon = 12,
	eItemTemplateId_LegendWeapon = 13,
	eItemTemplateId_BossWeapon = 14,
	eItemTemplateId_NormalHelmet = 20,
	eItemTemplateId_SuperHelmet = 21,
	eItemTemplateId_HyperHelmet = 22,
	eItemTemplateId_LegendHelmet = 23,
	eItemTemplateId_NormalArmor = 30,
	eItemTemplateId_SuperArmor = 31,
	eItemTemplateId_HyperArmor = 32,
	eItemTemplateId_LegendArmor = 33,
	eItemTemplateId_NormalShoes = 40,
	eItemTemplateId_SuperShoes = 41,
	eItemTemplateId_HyperShoes = 42,
	eItemTemplateId_LegendShoes = 43
};

UENUM(Blueprintable)
enum class ETableType : uint8
{
	eTableType_Potion,
	eTableType_Skill,
	eTableType_EnemySkill,
	eTableType_Cnt
};

UENUM(Blueprintable)
enum class EStateType : uint8
{
	eStateType_Spawn,
	eStateType_Idle,
	eStateType_Walk,
	eStateType_Attack,
	eStateType_Hit,
	eStateType_Die,
	eStateType_Dead,
	eStateType_Cnt
};

UENUM(Blueprintable)
enum class EMonsterId : uint8
{
	eMonsterId_CreatureSpider = 0,
	eMonsterId_Troll = 1,
	eMonsterId_ClotWorm = 2,
	eMonsterId_MasterGrunt = 3,
	eMonsterId_Bear = 4,
	eMonsterId_Cnt
};

UENUM(Blueprintable)
enum class EQuestType : uint8
{
	eQuestType_Monster = 0,
	eQuestType_NPC = 1,
	eQuestType_Item = 2,
	eQuestType_MonsterNPC = 3,
	eQuestType_MonsterItem = 4,
	eQuestType_NPCItem = 5,
	eQuestType_MonsterNPCItem = 6,
	eQuestType_Cnt
};

USTRUCT(BlueprintType)
struct FSkillData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		ESkillTemplateId StringId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringDescriptionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		bool SkillType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float SkillDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CoolTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MPCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillATKRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqSkillPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		ETargetType TargetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EAreaType AreaType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float LocationX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float LocationY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EEffectId EffectId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		ESkillTemplateId ConnectSkill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ValidTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText SkillResPath;
};


USTRUCT(BlueprintType)
struct FPotionItemData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EItemTemplateId ItemTemplataId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EPotionType PotionTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ItemStringId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ItemDescriptionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float RecoveryRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SellPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText ResourcePath;
};

USTRUCT(BlueprintType)
struct FEquipItemData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EItemTemplateId ItemTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ItemStringId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ItemDescriptionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EEquipItemType EquipItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SellPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText ResourcePath;
};

USTRUCT(BlueprintType)
struct FEquipItemAbilityData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EItemTemplateId ItemAbilityTemplateID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AttackDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AtkDmgMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AtkDmgMaxExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AtkSpdMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AtkSpdMaxExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DefMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DefMaxExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriRatMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriRatMaxExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriDmgMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriDmgMaxExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SpdMinExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SpdMaxExtra;
};


// Enemy 공격 테이블
USTRUCT(BlueprintType)
struct FEnemySkillData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 템플릿 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillTemplateId;

	// Enemy ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyId;

	// 스트링 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringId;

	// 스트링 설명 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringDescriptionId;

	// 공격 인덱스 : 공격의 종류는 이 인덱스로 식별
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AttackIndex;

	// 공격 타입, 0 : 패시브, 1 : 액티브
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		bool SkillType;

	// 공격 레벨 ( 추후 페이즈가 추가 될 시 사용 예정)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillLevel;

	// 공격 데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float SkillDmg;

	// 쿨타임
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CoolTime;

	// 소모 마나
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MPCost;

	// 공격 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillATKRange;

	// 타겟타입, 0 : none (패시브), 1 : Target (타겟으로 잡고 있는 대상에게 효과 적용), 2 : AOE (광역으로 효과 적용)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		ETargetType TargetType;

	// 영역타입, 0 : 원형, 1 : 사각형, 2 : 부채꼴
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EAreaType AreaType;

	// Angle (원형), Width (사각형)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaX;

	// Radius (원형), Length (사각형)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaY;

	// 이펙트 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EffectId;

	// ValidTime
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ValidTime;
};

// Enemy 몬스터 기본 테이블
USTRUCT(BlueprintType)
struct FMonsterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 템플릿 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterTemplateID;

	// 몬스터 ID (적 식별 ID)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyID;

	// 스트링 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringID;

	// 레벨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterLevel;

	// 몬스터 타입, 0 : 일반, 1 : 보스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		bool MonsterType;

	// 최대 HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHP;

	// 공격 데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AtkDmg;

	// 공격 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AtkSpd;

	// 방어력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Deffense;

	// 크리티컬 확률
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalRatio;

	// 크리티컬 데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalDmg;

	// 영역타입, 0 : 원형, 1 : 사각형, 2 : 부채꼴
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MoveSpeed;

	// 보상 경험치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RewardExp;

	// 드롭 아이템
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RewardItem;

	// 리스폰 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RespawnTime;

	// 필드의 최대 개체수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterRimitCount;

	// 타겟포인트 tag
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText TargetPointTagName;

	// 최대 공격 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MaxAttackIndex;
};


USTRUCT(BlueprintType)
struct FBattleData
{
	GENERATED_BODY()

public:
	//출력 데미지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 Damage;

	//공격 횟수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 AttackCount;

	//크리티컬 유무
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		bool bCritical;

	//상태이상 ID?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 StatusEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		bool SkillType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 SkillLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 SkillNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 SkillDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		float CoolTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 MPCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 SkillATKRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 ReqLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 ReqSkillPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		ETargetType TargetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		EAreaType AreaType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		float AreaX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		float AreaY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EEffectId EffectId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ConnectSkill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ValidTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText SkillResPath;
};

// Enemy 리스폰 테이블
USTRUCT(BlueprintType)
struct FRespawnData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 몬스터 ID (적 식별 ID)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyID;

	// 리스폰 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RespawnTime;

	// 필드의 최대 개체수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterRimitCount;
};

// 캐릭터 스탯 테이블
USTRUCT(BlueprintType)
struct FCharacterStatData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MaxMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AttackDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Deffense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MaxExp;
};

USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FCharacterStatData StatData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Exp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillPoint;
};

USTRUCT(BlueprintType)
struct FStringData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText StringDescriptionId;
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
	EItemTemplateId itemTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		EEquipItemType itemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 reqLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		float itemRank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 attackDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 attackDmgExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 attackSpd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 attackSpdExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 defenseExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		float criticalRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		float criticalRatioExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		float criticalDmg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		float criticalDmgExtra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStat")
		int32 speedExtra;
};

// Quest 테이블
USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 템플릿 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 TemplateId;

	// 퀘스트타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EQuestType QuestType;

	// 퀘스트 제목 (StringTable 참조)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 TitleStringId;

	// 퀘스트 설명 (StringTable 참조, 개행은 # 로 구분)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DescStringId;

	// 최소 요구 레벨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqLevel;

	// 보상 경험치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ResultExp;

	// 보상 골드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ResultGold;

	// 목적지 x 좌표
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorX;

	// 목적지 y 좌표
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorY;

	// 목적지 z 좌표
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorZ;

	// 요구 몬스터1 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt1;

	// 요구 몬스터2 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt2;

	// 요구 몬스터3 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt3;

	// 요구 몬스터1 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId1;

	// 요구 몬스터2 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId2;

	// 요구 몬스터3 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId3;

	// 요구 아이템1 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt1;

	// 요구 아이템2 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt2;

	// 요구 아이템3 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt3;

	// 요구 아이템1 StringId (StringTable 참조)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId1;

	// 요구 아이템2 StringId (StringTable 참조)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId2;

	// 요구 아이템3 StringId (StringTable 참조)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId3;
};

USTRUCT(BlueprintType)
struct FQuestInfo
{
	GENERATED_BODY()

public:
	// 퀘스트 id
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 QuestId;

	// 클리어 상태
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsClear;

	// 퀘스트 테이블에서 읽어온 기본 정보
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FQuestData DefaultQuestDetail;

	// NPC 정보 갖고 있는가
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasNPCLocation;

	// Monster id 리스트 (-1 : 없음, 그외 : 몬스터Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> MonsterIds;

	// item id 리스트 (-1 : 없음, 그외 : 아이템Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> ItemIds;

	// Monster 잡은 숫자 리스트 (-1 : 없음, 그외 : 몬스터Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> MonsterCnts;

	// item 구한 숫자 리스트 (-1 : 없음, 그외 : 아이템Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> ItemCnts;
};