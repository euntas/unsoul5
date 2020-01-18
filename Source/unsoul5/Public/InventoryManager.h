// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonStruct.h"
#include "Engine/World.h"
#include "InventoryManager.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem(const FObjectInitializer& init = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintReadWrite)
		EItemTemplateId itemTemplateId;

	UPROPERTY(BlueprintReadWrite)
		bool bselectedItem = false;
};


UCLASS(Blueprintable)
class UEquipItem : public UItem
{
	GENERATED_BODY()

public:
	UEquipItem(const FObjectInitializer& init = FObjectInitializer::Get());

	//무기=1, 투구=2, 갑옷=3, 신발=4
	UPROPERTY(BlueprintReadWrite)
		EEquipItemType itemType;

	//아이템 추옵 등급 확인용. 0~1 사이값 배정
	UPROPERTY(BlueprintReadWrite)
		float itemRank;

	//장비는 스택카운트 무조건 0
	UPROPERTY(BlueprintReadWrite)
		int32 stackCount = 0;

	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 reqLevel;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 attackDmg;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 attackDmgExtra;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 attackSpd;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 attackSpdExtra;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 defense;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 defenseExtra;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		float criticalRatio;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		float criticalRatioExtra;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		float criticalDmg;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		float criticalDmgExtra;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 speed;
	UPROPERTY(BlueprintReadWrite, Category = "ItemStat")
		int32 speedExtra;
};


UCLASS(Blueprintable)
class  UPotionItem : public UItem
{
	GENERATED_BODY()

public:
	UPotionItem(const FObjectInitializer& init = FObjectInitializer::Get());

	UPROPERTY(BlueprintReadWrite)
		EPotionType potionType;
	UPROPERTY(BlueprintReadWrite)
		int32 stackCount;
};


UCLASS(Blueprintable)
class UNSOUL5_API UInventoryManager : public UObject
{
	GENERATED_BODY()

		UInventoryManager();

public:
	UFUNCTION()
		void Init();

	UFUNCTION()
		void FirstEquipItemSetting();

	UFUNCTION(BlueprintCallable)
		void SetGold(int32 ingold);

	UFUNCTION(BlueprintCallable)
		void IncreaseGold(int32 ingold);

	UFUNCTION(BlueprintCallable)
		int32 GetGold();

	UFUNCTION(BlueprintCallable)
		void AddInvenArray(UItem* initem);

	UFUNCTION(BlueprintCallable)
		void RemoveInvenArray(UItem* initem);

	UFUNCTION(BlueprintCallable)
		TArray<UItem*> GetInvenArray();

	UFUNCTION(BlueprintCallable)
		void SetInvenArray(TArray<UItem*> arr);


	UFUNCTION(BlueprintCallable)
		UEquipItem* MakeEquipItem(EItemTemplateId initemTemplateId, EEquipItemType intype, int32 inreqLevel, float inRank,
			int32 inAttackDmg, int32 inAttackDmgExtra, int32 inAttadkSpd, int32 inAttadkSpdExtra, int32 inDefense, int32 inDefenseExtra,
			float inCriRatio, float inCriRatioExtra, float inCriDmg, float inCriDmgExtra, int32 inSpeed, int32 inSpeedExtra,
			int32 inSellPrice);

	UFUNCTION(BlueprintCallable)
		void AddMakeitem(FItemData ItemData);

	UFUNCTION(BlueprintCallable)
		void SetEquipItem(UEquipItem* initem);

	UFUNCTION()
		void SetEquipWeapon(UEquipItem* inWeaponitem);
	UFUNCTION()
		void SetEquipHelmet(UEquipItem* inHelmetitem);
	UFUNCTION()
		void SetEquipArmor(UEquipItem* inArmoritem);
	UFUNCTION()
		void SetEquipShoes(UEquipItem* inShoesitem);

	UFUNCTION(BlueprintCallable)
		UEquipItem* GetEquipItem(EEquipItemType itemType);

	UFUNCTION(BlueprintCallable)
		bool IsEquipItem(UEquipItem* _Item);


	UFUNCTION(BlueprintCallable)
		int32 GetPotionStack(EPotionType potionType);


	UFUNCTION(BlueprintCallable)
		UPotionItem* GetPotionItem(EPotionType potionType);

	UFUNCTION(BlueprintCallable)
		void SetEquipPotionItem(EPotionType itemType);
	UFUNCTION(BlueprintCallable)
		EPotionType GetEquipPotionItemType();
	UFUNCTION(BlueprintCallable)
		UPotionItem* GetEquipPotionItem();

	UFUNCTION()
		TArray<UEquipItem*> GetEquipItemArray();

	UFUNCTION()
		void SetEquipItemArray(TArray<UEquipItem*> arr);

	UFUNCTION()
		void SetPotions(UPotionItem* low, UPotionItem* middle, UPotionItem* high);
	UFUNCTION()
		UPotionItem* GetLowPotion();
	UFUNCTION()
		UPotionItem* GetMiddlePotion();
	UFUNCTION()
		UPotionItem* GetHighPotion();


public:
	UPROPERTY(blueprintreadwrite)
		TArray<UItem*> InvenArray;

	UPROPERTY(blueprintreadwrite)
		TArray<UEquipItem*> equipItemArray;

	UPROPERTY(blueprintreadwrite)
		UEquipItem* equipHelmet = nullptr;
	UPROPERTY(blueprintreadwrite)
		UEquipItem* equipArmor = nullptr;
	UPROPERTY(blueprintreadwrite)
		UEquipItem* equipShoes = nullptr;
	UPROPERTY(blueprintreadwrite)
		UEquipItem* equipWeapon = nullptr;

	UPROPERTY(blueprintreadwrite)
		UPotionItem* equipPotion;

private:
	UPROPERTY()
		int32 gold;

	UPROPERTY()
		UPotionItem* LowPotion;
	UPROPERTY()
		UPotionItem* MiddlePotion;
	UPROPERTY()
		UPotionItem* HighPotion;
};
