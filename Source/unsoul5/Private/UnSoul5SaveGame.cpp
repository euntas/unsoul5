// Fill out your copyright notice in the Description page of Project Settings.


#include "UnSoul5SaveGame.h"
#include "UnSoul5SaveGameData.h"
#include "Unsoul5GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "SkillManager.h"
#include "InventoryManager.h"
#include "unsoul5Character.h"
#include "CharacterManager.h"
#include "QuestManager.h"

UUnSoul5SaveGame::UUnSoul5SaveGame()
{
	SaveSlotName = TEXT("DefaultSaveSlot");
	UserIndex = 0;
}

void UUnSoul5SaveGame::InitSaveGame(UUnsoul5GameInstance* GameInstance)
{
	if (!UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
	{
		if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
		{
			UGameplayStatics::DeleteGameInSlot(SaveSlotName, UserIndex);
		}

		if (SaveGameData == nullptr)
		{
			FPlayerInfo Info;
			Info.StatData = GameInstance->GetCharacterStatTableData(1);
			Info.Exp = 0;
			Info.HP = Info.StatData.MaxHP;
			Info.MP = Info.StatData.MaxMP;
			Info.SkillPoint = 0;
			SaveGameData = Cast<UUnSoul5SaveGameData>(UGameplayStatics::CreateSaveGameObject(UUnSoul5SaveGameData::StaticClass()));
			SaveGameData->SetCharacterStatData(Info);

			//SaveGameData->Init();
		}

		UGameplayStatics::SaveGameToSlot(SaveGameData, SaveSlotName, UserIndex);
	}
	else
	{
		SaveGameData = Cast<UUnSoul5SaveGameData>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	
		////스킬
		//GameInstance->GetSkillMgr()->SetActiveSkillArray(SaveGameData->GetActiveSkillArray());
		//GameInstance->GetSkillMgr()->SetPassiveSkillArray(SaveGameData->GetPassiveSkillArray());
	
		////인벤
		//GameInstance->GetInventoryMgr()->SetInvenArray(SaveGameData->GetInvenArray());
		//GameInstance->GetInventoryMgr()->SetEquipItemArray(SaveGameData->GetEquipItemArray());
		//GameInstance->GetInventoryMgr()->SetGold(SaveGameData->GetGold());

		////퀘스트
		//GameInstance->GetQuestManager()->AcceptedQuestInfoList = SaveGameData->GetAcceptedQuestInfoList();
		//GameInstance->GetQuestManager()->CurrentAcceptedQuestId = SaveGameData->GetCurrentAcceptedQuestId();
		//GameInstance->GetQuestManager()->CurrentDisplayQuestId = SaveGameData->GetCurrentDisplayQuestId();
		//
		////포션
		//GameInstance->GetInventoryMgr()->SetPotions(SaveGameData->GetPotionItem(EPotionType::ePotionType_LowPotion),
		//	SaveGameData->GetPotionItem(EPotionType::ePotionType_MiddlePotion),
		//	SaveGameData->GetPotionItem(EPotionType::ePotionType_MiddlePotion));
		//GameInstance->GetInventoryMgr()->SetEquipPotionItem(SaveGameData->GetEquipPotionItem());
	}

	check(SaveGameData);
}

void UUnSoul5SaveGame::CurrentSaveGame()
{
	UGameplayStatics::SaveGameToSlot(SaveGameData, SaveSlotName, UserIndex);

	//UE_LOG(LogTemp, Log, TEXT("Auto Save"));
}

UUnSoul5SaveGameData* UUnSoul5SaveGame::GetSaveGameData() const
{
	return SaveGameData;
}

void UUnSoul5SaveGame::LoadData(UUnsoul5GameInstance* _GameInstance)
{

}

void UUnSoul5SaveGame::SaveData(UUnsoul5GameInstance* _GameInstance)
{
	//SaveGameData->SetAcceptedQuestInfoList(_GameInstance->GetQuestManager()->AcceptedQuestInfoList);
	//SaveGameData->SetCurrentAcceptedQuestId(_GameInstance->GetQuestManager()->CurrentAcceptedQuestId);
	//SaveGameData->SetCurrentDisplayQuestId(_GameInstance->GetQuestManager()->CurrentDisplayQuestId);
	//
	//SaveGameData->SetActiveSkillArray(_GameInstance->GetSkillMgr()->GetActiveSkillArray());
	//SaveGameData->SetPassiveSkillArray(_GameInstance->GetSkillMgr()->GetPassiveSkillArray());

	//SaveGameData->SetEquipItemArray(_GameInstance->GetInventoryMgr()->GetEquipItemArray());
	//SaveGameData->SetInvenArray(_GameInstance->GetInventoryMgr()->GetInvenArray());
	//SaveGameData->SetGold(_GameInstance->GetInventoryMgr()->GetGold());
	//
	//SaveGameData->SetEquipPotionItem(_GameInstance->GetInventoryMgr()->GetEquipPotionItemType());
	//SaveGameData->SetPotions(_GameInstance->GetInventoryMgr()->GetPotionStack(EPotionType::ePotionType_LowPotion),
	//	_GameInstance->GetInventoryMgr()->GetPotionStack(EPotionType::ePotionType_MiddlePotion),
	//	_GameInstance->GetInventoryMgr()->GetPotionStack(EPotionType::ePotionType_MiddlePotion));

	//UGameplayStatics::SaveGameToSlot(SaveGameData, SaveSlotName, UserIndex);
}
