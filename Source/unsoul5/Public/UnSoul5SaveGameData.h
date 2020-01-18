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

	//�κ��丮
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

	//����	

	UFUNCTION(BlueprintCallable)
		int32 GetPotionItem(EPotionType potionType);

	UFUNCTION(BlueprintCallable)
		void SetPotions(int32 low, int32 middle, int32 high);

	UFUNCTION(BlueprintCallable)
		EPotionType GetEquipPotionItem();

	UFUNCTION(BlueprintCallable)
		void SetEquipPotionItem(EPotionType _EquipPotion);

	//��ų
	UFUNCTION(BlueprintCallable)
		TArray<int32> GetActiveSkillArray();

	UFUNCTION(BlueprintCallable)
		void SetActiveSkillArray(TArray<UActiveSkill*> _ActiveSkill);
	
	UFUNCTION(BlueprintCallable)
		TArray<int32> GetPassiveSkillArray();
	
	UFUNCTION(BlueprintCallable)
		void SetPassiveSkillArray(TArray<UPassiveSkill*> _PassvieSkill);
	
	//ĳ����
	UFUNCTION(BlueprintCallable)
		FPlayerInfo GetCharacterStatData();

	UFUNCTION(BlueprintCallable)
		void SetCharacterStatData(FPlayerInfo _PlayerInfo);
	
	//����Ʈ
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
	//ĳ����
	UPROPERTY()
		FPlayerInfo PlayerInfo;
	//��ų
	UPROPERTY()
		TArray<int32> ActiveSkillArray;

	UPROPERTY()
		TArray<int32> PassiveSkillArray;

	//�κ�
	UPROPERTY()
		TArray<UItem*> InvenArray;

	UPROPERTY()
		TArray<UEquipItem*> equipItemArray;

	UPROPERTY()
		int32 Gold;

	//����
	UPROPERTY()
		EPotionType equipPotion;

	UPROPERTY()
		int32 LowPotion;
	UPROPERTY()
		int32 MiddlePotion;
	UPROPERTY()
		int32 HighPotion;

	//����Ʈ
	// ���� NPC �� ǥ���� ����Ʈ Id
	UPROPERTY()
		int32 CurrentDisplayQuestId;

	// ���� �������� ����Ʈ Id (-1 �̸� �������� ���� ����)
	UPROPERTY()
		int32 CurrentAcceptedQuestId = -1;

	// ���� ����Ʈ ����Ʈ
	UPROPERTY()
		TArray<FQuestInfo> AcceptedQuestInfoList;

};
