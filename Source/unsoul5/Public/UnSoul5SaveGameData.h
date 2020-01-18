// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CommonStruct.h"
#include "UnSoul5SaveGameData.generated.h"
/**
 * 
 */
class UActiveSkill;
class UPassiveSkill;
class UItem;
class UEquipItem;
class UPotionItem;

UCLASS(Blueprintable)
class UNSOUL5_API UUnSoul5SaveGameData : public USaveGame
{
	GENERATED_BODY()

public:

	//UFUNCTION()
		//void SaveGameData();

	UFUNCTION()
		void LoadGameData();

	//인벤토리
	UFUNCTION(BlueprintCallable)
		TArray<UItem*> GetInvenArray();

	UFUNCTION(BlueprintCallable)
		void SetInvenArray(TArray<UItem*> _ItemArray);
	
	UFUNCTION(BlueprintCallable)
		TArray<UEquipItem*> GetEquipItemArray();

	UFUNCTION(BlueprintCallable)
		void SetEquipItemArray(TArray<UEquipItem*> _EquipItemArray);

	UFUNCTION(BlueprintCallable)
		void SetGold(int32 Value);

	UFUNCTION(BlueprintCallable)
		int32 GetGold();

	//포션	

	UFUNCTION(BlueprintCallable)
		int32 GetPotionItem(EPotionType potionType);

	UFUNCTION(BlueprintCallable)
		void SetPotions(int32 low, int32 middle, int32 high);

	UFUNCTION(BlueprintCallable)
		EPotionType GetEquipPotionItem();

	UFUNCTION(BlueprintCallable)
		void SetEquipPotionItem(EPotionType _EquipPotion);

	//스킬
	UFUNCTION(BlueprintCallable)
		TArray<int32> GetActiveSkillArray();

	UFUNCTION(BlueprintCallable)
		void SetActiveSkillArray(TArray<UActiveSkill*> _ActiveSkill);
	
	UFUNCTION(BlueprintCallable)
		TArray<int32> GetPassiveSkillArray();
	
	UFUNCTION(BlueprintCallable)
		void SetPassiveSkillArray(TArray<UPassiveSkill*> _PassvieSkill);
	
	//캐릭터
	UFUNCTION(BlueprintCallable)
		FPlayerInfo GetCharacterStatData();

	UFUNCTION(BlueprintCallable)
		void SetCharacterStatData(FPlayerInfo _PlayerInfo);
	
	//퀘스트
	UFUNCTION(BlueprintCallable)
		int32 GetCurrentDisplayQuestId();

	UFUNCTION(BlueprintCallable)
		void SetCurrentDisplayQuestId(int32 _CurrentQuestId);

	UFUNCTION(BlueprintCallable)
		int32 GetCurrentAcceptedQuestId();

	UFUNCTION(BlueprintCallable)
		void SetCurrentAcceptedQuestId(int32 _CurrentAccpetedQuestId);

	UFUNCTION(BlueprintCallable)
		TArray<FQuestInfo> GetAcceptedQuestInfoList();

	UFUNCTION(BlueprintCallable)
		void SetAcceptedQuestInfoList(TArray<FQuestInfo> _QuestList);

private:
	//캐릭터
	UPROPERTY()
		FPlayerInfo PlayerInfo;
	//스킬
	UPROPERTY()
		TArray<int32> ActiveSkillArray;

	UPROPERTY()
		TArray<int32> PassiveSkillArray;

	//인벤
	UPROPERTY()
		TArray<UItem*> InvenArray;

	UPROPERTY()
		TArray<UEquipItem*> equipItemArray;

	UPROPERTY()
		int32 Gold;

	//포션
	UPROPERTY()
		EPotionType equipPotion;

	UPROPERTY()
		int32 LowPotion;
	UPROPERTY()
		int32 MiddlePotion;
	UPROPERTY()
		int32 HighPotion;

	//퀘스트
	// 현재 NPC 가 표시할 퀘스트 Id
	UPROPERTY()
		int32 CurrentDisplayQuestId;

	// 현재 수락중인 퀘스트 Id (-1 이면 수락중인 퀘가 없음)
	UPROPERTY()
		int32 CurrentAcceptedQuestId = -1;

	// 수락 퀘스트 리스트
	UPROPERTY()
		TArray<FQuestInfo> AcceptedQuestInfoList;

};
