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
	//����
	eAreaType_Circle,
	//�簢��
	eAreaType_Rectangle,
	eAreaType_Cnt
};

UENUM(Blueprintable)
enum class EEffectId : uint8
{
	eEffectId_None,
	//����
	eEffectId_PassOut,
	//����
	eEffectId_Freeze,
	//ȭ��
	eEffectId_Burn,
	//�巹��
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


// Enemy ���� ���̺�
USTRUCT(BlueprintType)
struct FEnemySkillData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// ���ø� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillTemplateId;

	// Enemy ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyId;

	// ��Ʈ�� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringId;

	// ��Ʈ�� ���� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringDescriptionId;

	// ���� �ε��� : ������ ������ �� �ε����� �ĺ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 AttackIndex;

	// ���� Ÿ��, 0 : �нú�, 1 : ��Ƽ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		bool SkillType;

	// ���� ���� ( ���� ����� �߰� �� �� ��� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillLevel;

	// ���� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float SkillDmg;

	// ��Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CoolTime;

	// �Ҹ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MPCost;

	// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 SkillATKRange;

	// Ÿ��Ÿ��, 0 : none (�нú�), 1 : Target (Ÿ������ ��� �ִ� ��󿡰� ȿ�� ����), 2 : AOE (�������� ȿ�� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		ETargetType TargetType;

	// ����Ÿ��, 0 : ����, 1 : �簢��, 2 : ��ä��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EAreaType AreaType;

	// Angle (����), Width (�簢��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaX;

	// Radius (����), Length (�簢��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AreaY;

	// ����Ʈ ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EffectId;

	// ValidTime
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float ValidTime;
};

// Enemy ���� �⺻ ���̺�
USTRUCT(BlueprintType)
struct FMonsterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// ���ø� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterTemplateID;

	// ���� ID (�� �ĺ� ID)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyID;

	// ��Ʈ�� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 StringID;

	// ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterLevel;

	// ���� Ÿ��, 0 : �Ϲ�, 1 : ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		bool MonsterType;

	// �ִ� HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHP;

	// ���� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AtkDmg;

	// ���� �ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float AtkSpd;

	// ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Deffense;

	// ũ��Ƽ�� Ȯ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalRatio;

	// ũ��Ƽ�� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float CriticalDmg;

	// ����Ÿ��, 0 : ����, 1 : �簢��, 2 : ��ä��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MoveSpeed;

	// ���� ����ġ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RewardExp;

	// ��� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RewardItem;

	// ������ �ð�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RespawnTime;

	// �ʵ��� �ִ� ��ü��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterRimitCount;

	// Ÿ������Ʈ tag
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FText TargetPointTagName;

	// �ִ� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MaxAttackIndex;
};


USTRUCT(BlueprintType)
struct FBattleData
{
	GENERATED_BODY()

public:
	//��� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 Damage;

	//���� Ƚ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		int32 AttackCount;

	//ũ��Ƽ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BattleData")
		bool bCritical;

	//�����̻� ID?
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

// Enemy ������ ���̺�
USTRUCT(BlueprintType)
struct FRespawnData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// ���� ID (�� �ĺ� ID)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 EnemyID;

	// ������ �ð�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 RespawnTime;

	// �ʵ��� �ִ� ��ü��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 MonsterRimitCount;
};

// ĳ���� ���� ���̺�
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

// Quest ���̺�
USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// ���ø� ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 TemplateId;

	// ����ƮŸ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EQuestType QuestType;

	// ����Ʈ ���� (StringTable ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 TitleStringId;

	// ����Ʈ ���� (StringTable ����, ������ # �� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DescStringId;

	// �ּ� �䱸 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqLevel;

	// ���� ����ġ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ResultExp;

	// ���� ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ResultGold;

	// ������ x ��ǥ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorX;

	// ������ y ��ǥ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorY;

	// ������ z ��ǥ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float DestVectorZ;

	// �䱸 ����1 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt1;

	// �䱸 ����2 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt2;

	// �䱸 ����3 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterCnt3;

	// �䱸 ����1 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId1;

	// �䱸 ����2 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId2;

	// �䱸 ����3 Id
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqMonsterId3;

	// �䱸 ������1 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt1;

	// �䱸 ������2 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt2;

	// �䱸 ������3 ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemCnt3;

	// �䱸 ������1 StringId (StringTable ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId1;

	// �䱸 ������2 StringId (StringTable ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId2;

	// �䱸 ������3 StringId (StringTable ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 ReqItemStringId3;
};

USTRUCT(BlueprintType)
struct FQuestInfo
{
	GENERATED_BODY()

public:
	// ����Ʈ id
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 QuestId;

	// Ŭ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsClear;

	// ����Ʈ ���̺��� �о�� �⺻ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FQuestData DefaultQuestDetail;

	// NPC ���� ���� �ִ°�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasNPCLocation;

	// Monster id ����Ʈ (-1 : ����, �׿� : ����Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> MonsterIds;

	// item id ����Ʈ (-1 : ����, �׿� : ������Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> ItemIds;

	// Monster ���� ���� ����Ʈ (-1 : ����, �׿� : ����Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> MonsterCnts;

	// item ���� ���� ����Ʈ (-1 : ����, �׿� : ������Id)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> ItemCnts;
};