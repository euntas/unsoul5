// Fill out your copyright notice in the Description page of Project Settings.


#include "Unsoul5GameInstance.h"
#include "InventoryManager.h"
#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "BattleLogic.h"
#include "SkillManager.h"
#include "unsoul5Character.h"
#include "UnSoul5SaveGame.h"
#include "UnSoul5SaveGameData.h"
#include "CharacterManager.h"
#include "QuestManager.h"
//#include "..\Public\Unsoul5GameInstance.h"

void UUnsoul5GameInstance::LevelRelease()
{
	if (CharacterManager != nullptr)
	{
		CharacterManager->Release();
	}
}

UInventoryManager* UUnsoul5GameInstance::GetInventoryMgr()
{
	return InvenMgr;
}

UBattleLogic* UUnsoul5GameInstance::GetBattleLogic()
{
	return BattleLogic;
}

USkillManager* UUnsoul5GameInstance::GetSkillMgr()
{
	return SkillMgr;
}

UUnsoul5GameInstance::UUnsoul5GameInstance()
{
	FString PotionDataPath1 = TEXT("/Game/Tables/PotionItemTable.PotionItemTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_POTIONDATA(*PotionDataPath1);

	FString SkillDataPath2 = TEXT("/Game/Tables/SkillTable.SkillTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_SKILLDATA(*SkillDataPath2);

	FString EnemySkillDataPath3 = TEXT("/Game/Tables/EnemySkillTable.EnemySkillTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ENEMYSKILLDATA(*EnemySkillDataPath3);

	FString MosterDataPath = TEXT("/Game/Tables/MonsterTable.MonsterTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_MONSTERDATA(*MosterDataPath);

	FString EquipItemDataPath = TEXT("/Game/Tables/EquipItemTable.EquipItemTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_EQUIPITEMDATA(*EquipItemDataPath);

	FString EquipItemAbilityDataPath = TEXT("/Game/Tables/EquipItemAbilityTable.EquipItemAbilityTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_POEQUIPITEMABILITYDATA(*EquipItemAbilityDataPath);

	FString CharacterStatData = TEXT("/Game/Tables/CharacterStatTable.CharacterStatTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_CHARACTERDATA(*CharacterStatData);

	FString StringData = TEXT("/Game/Tables/StringTable.StringTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_STRINGDATA(*StringData);

	FString QuestDataPath = TEXT("/Game/Tables/QuestTable.QuestTable");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_QUESTDATA(*QuestDataPath);


	potionTable = DT_POTIONDATA.Object;
	skillTable = DT_SKILLDATA.Object;
	enemySkillTable = DT_ENEMYSKILLDATA.Object;
	monsterTable = DT_MONSTERDATA.Object;
	equipItemTable = DT_EQUIPITEMDATA.Object;
	equipItemAbilityTable = DT_POEQUIPITEMABILITYDATA.Object;
	characterStatTable = DT_CHARACTERDATA.Object;
	stringTable = DT_STRINGDATA.Object;
	questTable = DT_QUESTDATA.Object;

	bVideoPlayOnce = true;
}

UUnSoul5SaveGame* UUnsoul5GameInstance::GetSaveGame()
{
	return SaveGame;
}

UCharacterManager* UUnsoul5GameInstance::GetCharacterManager()
{
	return CharacterManager;
}

UQuestManager* UUnsoul5GameInstance::GetQuestManager()
{
	return QuestManager;
}

void UUnsoul5GameInstance::Init()
{
	InvenMgr = NewObject<UInventoryManager>(UInventoryManager::StaticClass());
	BattleLogic = NewObject<UBattleLogic>(UBattleLogic::StaticClass());
	SkillMgr = NewObject<USkillManager>(USkillManager::StaticClass());
	SaveGame = NewObject<UUnSoul5SaveGame>(UUnSoul5SaveGame::StaticClass());
	CharacterManager = NewObject<UCharacterManager>(UCharacterManager::StaticClass());
	QuestManager = NewObject<UQuestManager>(UQuestManager::StaticClass());
	//SkillMgr->get

	SaveGame->InitSaveGame(this);

}

void UUnsoul5GameInstance::Shutdown()
{
	SaveGame->SaveData(this);

	Super::Shutdown();
}

const FPotionItemData& UUnsoul5GameInstance::GetPotionTableData(EItemTemplateId InItemTemplateID)
{
	TArray<FPotionItemData*> datas;
	auto Names = potionTable->GetRowNames();
	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = potionTable->FindRow<FPotionItemData>(Names[i], FString());

		if (record->ItemTemplataId == InItemTemplateID)
		{
			FPotionItemData asset;

			asset.ItemTemplataId = record->ItemTemplataId;
			asset.PotionTemplateId = record->PotionTemplateId;
			asset.ItemStringId = record->ItemStringId;
			asset.ItemDescriptionId = record->ItemDescriptionId;
			asset.RecoveryRate = record->RecoveryRate;
			asset.SellPrice = record->SellPrice;
			asset.ResourcePath = record->ResourcePath;

			EmptyPotionTable = asset;
		}
	}
	return EmptyPotionTable;
}

const FSkillData& UUnsoul5GameInstance::GetSkillTableData(ESkillTemplateId InSkillTemplateID, int32 inskillLevel)
{
	TArray<FSkillData*> datas;
	auto Names = skillTable->GetRowNames();
	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = skillTable->FindRow<FSkillData>(Names[i], FString());

		if (record->StringId == InSkillTemplateID && record->SkillLevel == inskillLevel)
		{
			FSkillData asset;

			asset.SkillTemplateId = record->SkillTemplateId;
			asset.StringId = record->StringId;
			asset.StringDescriptionId = record->StringDescriptionId;
			asset.SkillType = record->SkillType;
			asset.SkillLevel = record->SkillLevel;
			asset.SkillNextLevel = record->SkillNextLevel;
			asset.SkillDmg = record->SkillDmg;
			asset.CoolTime = record->CoolTime;
			asset.MPCost = record->MPCost;
			asset.SkillATKRange = record->SkillATKRange;
			asset.ReqLevel = record->ReqLevel;
			asset.ReqSkillPoint = record->ReqSkillPoint;
			asset.TargetType = record->TargetType;
			asset.AreaType = record->AreaType;
			asset.AreaX = record->AreaX;
			asset.AreaY = record->AreaY;
			asset.LocationX = record->LocationX;
			asset.LocationY = record->LocationY;
			asset.EffectId = record->EffectId;
			asset.ConnectSkill = record->ConnectSkill;
			asset.ValidTime = record->ValidTime;
			asset.SkillResPath = record->SkillResPath;

			EmptySkillTable = asset;
		}
	}
	return EmptySkillTable;
}

const FEnemySkillData& UUnsoul5GameInstance::GetEnemySkillData(int32 EnemyId, int32 EnemyAttackId)
{
	TArray<FEnemySkillData*> datas;

	auto Names = enemySkillTable->GetRowNames();

	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = enemySkillTable->FindRow<FEnemySkillData>(Names[i], FString());

		if (record->EnemyId == EnemyId && record->AttackIndex == EnemyAttackId && record->SkillLevel == 1)
		{
			FEnemySkillData asset;

			asset.SkillTemplateId = record->SkillTemplateId;
			asset.EnemyId = record->EnemyId;
			asset.StringId = record->StringId;
			asset.StringDescriptionId = record->StringDescriptionId;
			asset.AttackIndex = record->AttackIndex;
			asset.SkillType = record->SkillType;
			asset.SkillLevel = record->SkillLevel;
			asset.SkillDmg = record->SkillDmg;
			asset.CoolTime = record->CoolTime;
			asset.MPCost = record->MPCost;
			asset.SkillATKRange = record->SkillATKRange;
			asset.TargetType = record->TargetType;
			asset.AreaType = record->AreaType;
			asset.AreaX = record->AreaX;
			asset.AreaY = record->AreaY;
			asset.EffectId = record->EffectId;
			asset.ValidTime = record->ValidTime;

			ResultEnemySkillTable = asset;
		}
	}

	return ResultEnemySkillTable;
}

const FMonsterData& UUnsoul5GameInstance::GetMonsterDataByTemplateID(int32 MonsterTemplateId)
{
	TArray<FMonsterData*> datas;

	auto Names = monsterTable->GetRowNames();

	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = monsterTable->FindRow<FMonsterData>(Names[i], FString());

		if (record->MonsterTemplateID == MonsterTemplateId)
		{
			FMonsterData asset;

			asset.MonsterTemplateID = record->MonsterTemplateID;
			asset.EnemyID = record->EnemyID;
			asset.StringID = record->StringID;
			asset.MonsterLevel = record->MonsterLevel;
			asset.MonsterType = record->MonsterType;
			asset.MaxHP = record->MaxHP;
			asset.AtkDmg = record->AtkDmg;
			asset.AtkSpd = record->AtkSpd;
			asset.Deffense = record->Deffense;
			asset.CriticalRatio = record->CriticalRatio;
			asset.CriticalDmg = record->CriticalDmg;
			asset.MoveSpeed = record->MoveSpeed;
			asset.RewardExp = record->RewardExp;
			asset.RewardItem = record->RewardItem;
			asset.RespawnTime = record->RespawnTime;
			asset.MonsterRimitCount = record->MonsterRimitCount;
			asset.TargetPointTagName = record->TargetPointTagName;
			asset.MaxAttackIndex = record->MaxAttackIndex;

			ResultMonsterTable = asset;
		}
	}

	return ResultMonsterTable;
}

const FEquipItemData& UUnsoul5GameInstance::GetEquipItemTableData(EItemTemplateId InTemplateID)
{
	TArray<FEquipItemData*> datas;
	auto Names = equipItemTable->GetRowNames();
	if (InTemplateID != EItemTemplateId::eItemTemplateId_None)
	{
		for (int i = 0; i < Names.Num(); i++)
		{
			auto record = equipItemTable->FindRow<FEquipItemData>(Names[i], FString());

			if (record->ItemTemplateId == InTemplateID)
			{
				FEquipItemData asset;

				asset.ItemTemplateId = record->ItemTemplateId;
				asset.ItemStringId = record->ItemStringId;
				asset.ItemDescriptionId = record->ItemDescriptionId;
				asset.EquipItemType = record->EquipItemType;
				asset.ReqLevel = record->ReqLevel;
				asset.SellPrice = record->SellPrice;
				asset.ResourcePath = record->ResourcePath;

				EmptyEquipItemTable = asset;
			}
		}
	}
	return EmptyEquipItemTable;
}

TArray<EItemTemplateId> UUnsoul5GameInstance::GetLevelEquipItemTables(int32 inLevel)
{
	TArray<EItemTemplateId> LevelItem;

	auto Names = equipItemTable->GetRowNames();

	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = equipItemTable->FindRow<FEquipItemData>(Names[i], FString());

		if (record->ReqLevel == inLevel)
		{
			LevelItem.Add(record->ItemTemplateId);
		}
	}

	return LevelItem;
}

const FEquipItemAbilityData& UUnsoul5GameInstance::GetEquipItemAbilityTableData(EItemTemplateId InTemplateID)
{
	TArray<FEquipItemAbilityData*> datas;
	auto Names = equipItemAbilityTable->GetRowNames();
	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = equipItemAbilityTable->FindRow<FEquipItemAbilityData>(Names[i], FString());

		if (record->ItemAbilityTemplateID == InTemplateID)
		{
			FEquipItemAbilityData asset;

			asset.ItemAbilityTemplateID = record->ItemAbilityTemplateID;
			asset.AttackDmg = record->AttackDmg;
			asset.AttackSpeed = record->AttackSpeed;
			asset.Defense = record->Defense;
			asset.CriticalRatio = record->CriticalRatio;
			asset.CriticalDmg = record->CriticalDmg;
			asset.Speed = record->Speed;
			asset.AtkDmgMinExtra = record->AtkDmgMinExtra;
			asset.AtkDmgMaxExtra = record->AtkDmgMaxExtra;
			asset.AtkSpdMinExtra = record->AtkSpdMinExtra;
			asset.AtkSpdMaxExtra = record->AtkSpdMaxExtra;
			asset.DefMinExtra = record->DefMinExtra;
			asset.DefMaxExtra = record->DefMaxExtra;
			asset.CriRatMinExtra = record->CriRatMinExtra;
			asset.CriRatMaxExtra = record->CriRatMaxExtra;
			asset.CriDmgMinExtra = record->CriDmgMinExtra;
			asset.CriDmgMaxExtra = record->CriDmgMaxExtra;
			asset.SpdMinExtra = record->SpdMinExtra;
			asset.SpdMaxExtra = record->SpdMaxExtra;

			EmptyEquipItemAbilityTable = asset;
		}
	}
	return EmptyEquipItemAbilityTable;
}

const FCharacterStatData& UUnsoul5GameInstance::GetCharacterStatTableData(int32 inLevel)
{
	TArray<FCharacterStatData*> datas;
	auto Names = characterStatTable->GetRowNames();
	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = characterStatTable->FindRow<FCharacterStatData>(Names[i], FString());

		if (record->Level == inLevel)
		{
			FCharacterStatData asset;

			asset.Level = record->Level;
			asset.MaxHP = record->MaxHP;
			asset.MaxMP = record->MaxMP;
			asset.AttackDmg = record->AttackDmg;
			asset.AttackSpeed = record->AttackSpeed;
			asset.Deffense = record->Deffense;
			asset.CriticalRatio = record->CriticalRatio;
			asset.CriticalDmg = record->CriticalDmg;
			asset.MoveSpeed = record->MoveSpeed;
			asset.SprintSpeed = record->SprintSpeed;
			asset.MaxExp = record->MaxExp;

			EmptyCharacterStatTable = asset;
		}
	}
	return EmptyCharacterStatTable;
}

const FStringData& UUnsoul5GameInstance::GetStringTableData(int32 inTemplateId)
{
	TArray<FStringData*> datas;
	auto Names = stringTable->GetRowNames();
	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = stringTable->FindRow<FStringData>(Names[i], FString());

		if (record->StringTemplateId == inTemplateId)
		{
			FStringData asset;

			asset.StringTemplateId = record->StringTemplateId;
			asset.StringDescriptionId = record->StringDescriptionId;

			EmptyStringTable = asset;
		}
	}
	return EmptyStringTable;
}

TArray<FRespawnData> UUnsoul5GameInstance::GetRespawnInfo(TArray<int32> MonsterTemplateIds)
{
	TArray<FRespawnData> ResultRespawnData;

	auto Names = monsterTable->GetRowNames();

	for (auto EnemyTemplateId : MonsterTemplateIds)
	{
		for (int i = 0; i < Names.Num(); i++)
		{
			auto record = monsterTable->FindRow<FMonsterData>(Names[i], FString());

			if (record->MonsterTemplateID == EnemyTemplateId)
			{
				FRespawnData respawnData;

				respawnData.EnemyID = record->EnemyID;
				respawnData.RespawnTime = record->RespawnTime;
				respawnData.MonsterRimitCount = record->MonsterRimitCount;

				ResultRespawnData.Add(respawnData);
			}
		}
	}

	return ResultRespawnData;
}

const FQuestData& UUnsoul5GameInstance::GetQuestDataByTemplateID(int32 QuestId)
{
	TArray<FQuestData*> datas;

	auto Names = questTable->GetRowNames();

	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = questTable->FindRow<FQuestData>(Names[i], FString());

		if (record->TemplateId == QuestId)
		{
			FQuestData asset;

			asset.TemplateId = record->TemplateId;
			asset.QuestType = record->QuestType;
			asset.TitleStringId = record->TitleStringId;
			asset.DescStringId = record->DescStringId;
			asset.ReqLevel = record->ReqLevel;
			asset.ResultExp = record->ResultExp;
			asset.ResultGold = record->ResultGold;
			asset.DestVectorX = record->DestVectorX;
			asset.DestVectorY = record->DestVectorY;
			asset.DestVectorZ = record->DestVectorZ;
			asset.ReqMonsterCnt1 = record->ReqMonsterCnt1;
			asset.ReqMonsterCnt2 = record->ReqMonsterCnt2;
			asset.ReqMonsterCnt3 = record->ReqMonsterCnt3;
			asset.ReqMonsterId1 = record->ReqMonsterId1;
			asset.ReqMonsterId2 = record->ReqMonsterId2;
			asset.ReqMonsterId3 = record->ReqMonsterId3;
			asset.ReqItemCnt1 = record->ReqItemCnt1;
			asset.ReqItemCnt2 = record->ReqItemCnt2;
			asset.ReqItemCnt3 = record->ReqItemCnt3;
			asset.ReqItemStringId1 = record->ReqItemStringId1;
			asset.ReqItemStringId2 = record->ReqItemStringId2;
			asset.ReqItemStringId3 = record->ReqItemStringId3;

			ResultQuestTable = asset;
		}
	}

	return ResultQuestTable;
}

UDataTable* UUnsoul5GameInstance::GetQuestTable()
{
	return questTable;
}

UTexture2D* UUnsoul5GameInstance::LoadTextureFromPath(const FString& Path)
{
	UTexture2D* sprite = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *Path));
	return sprite;
}

void UUnsoul5GameInstance::SetVideoPlayOnce(bool VideoPlay)
{
	bVideoPlayOnce = VideoPlay;
}

bool UUnsoul5GameInstance::GetVideoPlayOnce()
{
	return bVideoPlayOnce;
}

void UUnsoul5GameInstance::MyQuitGame(bool bForce)
{
	FPlatformMisc::RequestExit(bForce);
};