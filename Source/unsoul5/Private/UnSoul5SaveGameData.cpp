// Fill out your copyright notice in the Description page of Project Settings.


#include "UnSoul5SaveGameData.h"
#include "unsoul5Character.h"
#include "InventoryManager.h"
#include "SkillManager.h"
#include "PassiveSkill.h"
#include "ActiveSkill.h"


void UUnSoul5SaveGameData::LoadGameData()
{

}

TArray<UItem*> UUnSoul5SaveGameData::GetInvenArray()
{
	return InvenArray;
}

void UUnSoul5SaveGameData::SetInvenArray(TArray<UItem*> _ItemArray)
{
	//InvenArray.Empty();

	//for (auto it : _ItemArray)
	//{
	//	InvenArray.Add(*it);
	//}
}

TArray<UEquipItem*> UUnSoul5SaveGameData::GetEquipItemArray()
{
	return equipItemArray;
}

void UUnSoul5SaveGameData::SetEquipItemArray(TArray<UEquipItem*> _EquipItemArray)
{
	//	equipItemArray.Empty();
	//
	//	for (auto it : _EquipItemArray)
	//	{
	//		equipItemArray.Add(*it);
	//	}
	//}
}

void UUnSoul5SaveGameData::SetGold(int32 Value)
{
	Gold = Value;
}

int32 UUnSoul5SaveGameData::GetGold()
{
	return Gold;
}

int32 UUnSoul5SaveGameData::GetPotionItem(EPotionType potionType)
{
	switch (potionType)
	{
	case EPotionType::ePotionType_LowPotion:
		return LowPotion;
		break;
	case EPotionType::ePotionType_MiddlePotion:
		return MiddlePotion;
		break;
	case EPotionType::ePotionType_HighPotion:
		return HighPotion;
		break;
	default:
		return 0;
		break;
	}
}

void UUnSoul5SaveGameData::SetPotions(int32 low, int32 middle, int32 high)
{
	LowPotion = low;
	MiddlePotion = middle;
	HighPotion = high;
}

EPotionType UUnSoul5SaveGameData::GetEquipPotionItem()
{
	return equipPotion;
}

void UUnSoul5SaveGameData::SetEquipPotionItem(EPotionType _EquipPotion)
{
	equipPotion = _EquipPotion;
}

TArray<int32> UUnSoul5SaveGameData::GetActiveSkillArray()
{
	return ActiveSkillArray;
}

void UUnSoul5SaveGameData::SetActiveSkillArray(TArray<UActiveSkill*> _ActiveSkill)
{
	ActiveSkillArray.Empty();

	for (auto it : _ActiveSkill)
	{
		ActiveSkillArray.Add(it->skillPoint);
	}

}

TArray<int32> UUnSoul5SaveGameData::GetPassiveSkillArray()
{
	return PassiveSkillArray;
}

void UUnSoul5SaveGameData::SetPassiveSkillArray(TArray<UPassiveSkill*> _PassvieSkill)
{
	PassiveSkillArray.Empty();

	for (auto it : _PassvieSkill)
	{
		PassiveSkillArray.Add(it->skillPoint);
	}
}

FPlayerInfo UUnSoul5SaveGameData::GetCharacterStatData()
{
	return PlayerInfo;
}

void UUnSoul5SaveGameData::SetCharacterStatData(FPlayerInfo _PlayerInfo)
{
	PlayerInfo = _PlayerInfo;
}

int32 UUnSoul5SaveGameData::GetCurrentDisplayQuestId()
{
	return CurrentDisplayQuestId;
}

void UUnSoul5SaveGameData::SetCurrentDisplayQuestId(int32 _CurrentQuestId)
{
	CurrentDisplayQuestId = _CurrentQuestId;
}

int32 UUnSoul5SaveGameData::GetCurrentAcceptedQuestId()
{
	return CurrentAcceptedQuestId;
}

void UUnSoul5SaveGameData::SetCurrentAcceptedQuestId(int32 _CurrentAccpetedQuestId)
{
	CurrentAcceptedQuestId = _CurrentAccpetedQuestId;
}

TArray<FQuestInfo> UUnSoul5SaveGameData::GetAcceptedQuestInfoList()
{
	return AcceptedQuestInfoList;
}

void UUnSoul5SaveGameData::SetAcceptedQuestInfoList(TArray<FQuestInfo> _QuestList)
{
	AcceptedQuestInfoList = _QuestList;
}
