// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

UItem::UItem(const FObjectInitializer& init)
	: Super(init)
{

}

UEquipItem::UEquipItem(const FObjectInitializer& init)
	: Super(init)
{

}

UPotionItem::UPotionItem(const FObjectInitializer& init)
	: Super(init)
{

}


UInventoryManager::UInventoryManager()
{
	Init();
}

void UInventoryManager::Init()
{
	LowPotion = Cast<UPotionItem>(NewObject<UPotionItem>());
	MiddlePotion = Cast<UPotionItem>(NewObject<UPotionItem>());
	HighPotion = Cast<UPotionItem>(NewObject<UPotionItem>());

	LowPotion->itemTemplateId = EItemTemplateId::eItemTemplateId_LowPotion;
	LowPotion->potionType = EPotionType::ePotionType_LowPotion;
	MiddlePotion->itemTemplateId = EItemTemplateId::eItemTemplateId_MiddlePotion;
	MiddlePotion->potionType = EPotionType::ePotionType_MiddlePotion;
	HighPotion->itemTemplateId = EItemTemplateId::eItemTemplateId_HighPotion;
	HighPotion->potionType = EPotionType::ePotionType_HighPotion;

	//세이브데이터 불러와서 지정해줄것
	LowPotion->stackCount = 10;
	MiddlePotion->stackCount = 20;
	HighPotion->stackCount = 30;
	gold = 39000;
	equipPotion = LowPotion;


	equipItemArray.Empty();
	equipItemArray.Add(equipWeapon);
	equipItemArray.Add(equipHelmet);
	equipItemArray.Add(equipArmor);
	equipItemArray.Add(equipShoes);
	FirstEquipItemSetting();
}

void UInventoryManager::FirstEquipItemSetting()
{
	AddInvenArray(MakeEquipItem(EItemTemplateId::eItemTemplateId_NormalWeapon, EEquipItemType::eEquipItemType_Weapon, 1, 0, 10, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100));
	AddInvenArray(MakeEquipItem(EItemTemplateId::eItemTemplateId_NormalHelmet, EEquipItemType::eEquipItemType_Helmet, 1, 0, 0, 0, 0, 0, 3, 0, 0.1, 0, 0.1, 0, 5, 0, 100));
	AddInvenArray(MakeEquipItem(EItemTemplateId::eItemTemplateId_NormalArmor, EEquipItemType::eEquipItemType_Armor, 1, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 20, 100));
	AddInvenArray(MakeEquipItem(EItemTemplateId::eItemTemplateId_NormalShoes, EEquipItemType::eEquipItemType_Shoes, 1, 0, 0, 0, 0, 0, 3, 10, 0, 0, 0, 0, 0, 20, 100));
	SetEquipItem(Cast<UEquipItem>(InvenArray[0]));
	SetEquipItem(Cast<UEquipItem>(InvenArray[1]));
	SetEquipItem(Cast<UEquipItem>(InvenArray[2]));
	SetEquipItem(Cast<UEquipItem>(InvenArray[3]));
}

void UInventoryManager::SetGold(int32 ingold)
{
	gold = ingold;
}

void UInventoryManager::IncreaseGold(int32 ingold)
{
	gold += ingold;
}

int32 UInventoryManager::GetGold()
{
	return gold;
}


void UInventoryManager::AddInvenArray(UItem* initem)
{
	InvenArray.Add(initem);
}

void UInventoryManager::RemoveInvenArray(UItem* initem)
{
	if (InvenArray.Contains(initem))
	{
		InvenArray.Remove(initem);
	}
}

TArray<UItem*> UInventoryManager::GetInvenArray()
{
	return InvenArray;
}

void UInventoryManager::SetInvenArray(TArray<UItem*> arr)
{
	InvenArray = arr;
}

UEquipItem* UInventoryManager::MakeEquipItem(EItemTemplateId initemTemplateId, EEquipItemType intype, int32 inreqLevel, float inRank,
	int32 inAttackDmg, int32 inAttackDmgExtra, int32 inAttadkSpd, int32 inAttadkSpdExtra, int32 inDefense, int32 inDefenseExtra,
	float inCriRatio, float inCriRatioExtra, float inCriDmg, float inCriDmgExtra, int32 inSpeed, int32 inSpeedExtra,
	int32 inSellPrice)
{
	UEquipItem* item = Cast<UEquipItem>(NewObject<UEquipItem>());
	item->itemTemplateId = initemTemplateId;
	item->itemType = intype;
	item->itemRank = inRank;
	item->reqLevel = inreqLevel;
	item->attackDmg = inAttackDmg;
	item->attackDmgExtra = inAttackDmgExtra;
	item->attackSpd = inAttadkSpd;
	item->attackSpdExtra = inAttadkSpdExtra;
	item->defense = inDefense;
	item->defenseExtra = inDefenseExtra;
	item->criticalRatio = inCriRatio;
	item->criticalRatioExtra = inCriRatioExtra;
	item->criticalDmg = inCriDmg;
	item->criticalDmgExtra = inCriDmgExtra;
	item->speed = inSpeed;
	item->speedExtra = inSpeedExtra;
	return item;
}

void UInventoryManager::AddMakeitem(FItemData ItemData)
{
	UEquipItem* item = Cast<UEquipItem>(NewObject<UEquipItem>());
	item->itemTemplateId = ItemData.itemTemplateId;
	item->itemType = ItemData.itemType;
	item->reqLevel = ItemData.reqLevel;
	item->itemRank = ItemData.itemRank;
	item->attackDmg = ItemData.attackDmg;
	item->attackSpd = ItemData.attackSpd;
	item->defense = ItemData.defense;

	item->criticalDmg = ItemData.criticalDmg;
	item->criticalRatio = ItemData.criticalRatio;
	item->speed = ItemData.speed;
	item->attackSpd = ItemData.attackSpd;

	item->attackSpdExtra = ItemData.attackSpdExtra;
	item->defenseExtra = ItemData.defenseExtra;
	item->criticalRatioExtra = ItemData.criticalRatioExtra;
	item->criticalDmgExtra = ItemData.criticalDmgExtra;
	item->speedExtra = ItemData.speedExtra;

	AddInvenArray(item);
}



void UInventoryManager::SetEquipItem(UEquipItem* initem)
{
	switch (initem->itemType)
	{
	case EEquipItemType::eEquipItemType_Weapon:
		SetEquipWeapon(initem);
		break;
	case EEquipItemType::eEquipItemType_Helmet:
		SetEquipHelmet(initem);
		break;
	case EEquipItemType::eEquipItemType_Armor:
		SetEquipArmor(initem);
		break;
	case EEquipItemType::eEquipItemType_Shoes:
		SetEquipShoes(initem);
		break;
	default:
		break;
	}
}

void UInventoryManager::SetEquipWeapon(UEquipItem* inWeaponitem)
{
	if (equipWeapon != nullptr)
	{
		equipWeapon->bselectedItem = false;
	}
	equipWeapon = inWeaponitem;
	equipItemArray[0] = inWeaponitem;
	inWeaponitem->bselectedItem = true;
}

void UInventoryManager::SetEquipHelmet(UEquipItem* inHelmetitem)
{
	if (equipHelmet != nullptr)
	{
		equipHelmet->bselectedItem = false;
	}
	equipHelmet = inHelmetitem;
	equipItemArray[1] = inHelmetitem;
	inHelmetitem->bselectedItem = true;

}

void UInventoryManager::SetEquipArmor(UEquipItem* inArmoritem)
{
	if (equipArmor != nullptr)
	{
		equipArmor->bselectedItem = false;
	}
	equipArmor = inArmoritem;
	equipItemArray[2] = inArmoritem;
	inArmoritem->bselectedItem = true;
}

void UInventoryManager::SetEquipShoes(UEquipItem* inShoesitem)
{
	if (equipShoes != nullptr)
	{
		equipShoes->bselectedItem = false;
	}
	equipShoes = inShoesitem;
	equipItemArray[3] = inShoesitem;
	inShoesitem->bselectedItem = true;
}

UEquipItem* UInventoryManager::GetEquipItem(EEquipItemType itemType)
{
	switch (itemType)
	{
	case EEquipItemType::eEquipItemType_Weapon:
		return equipWeapon;
		break;
	case EEquipItemType::eEquipItemType_Helmet:
		return equipHelmet;
		break;
	case EEquipItemType::eEquipItemType_Armor:
		return equipArmor;
		break;
	case EEquipItemType::eEquipItemType_Shoes:
		return equipShoes;
		break;
	default:
		return nullptr;
		break;
	}
}

bool UInventoryManager::IsEquipItem(UEquipItem* _Item)
{
	if (equipItemArray.Contains(_Item))
	{
		return true;
	}

	return false;
}

int32 UInventoryManager::GetPotionStack(EPotionType potionType)
{
	switch (potionType)
	{
	case EPotionType::ePotionType_LowPotion:
		return LowPotion->stackCount;
		break;
	case EPotionType::ePotionType_MiddlePotion:
		return MiddlePotion->stackCount;
		break;
	case EPotionType::ePotionType_HighPotion:
		return HighPotion->stackCount;
		break;
	default:
		return 0;
		break;
	}
}

UPotionItem* UInventoryManager::GetPotionItem(EPotionType potionType)
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
		return nullptr;
		break;
	}
}

void UInventoryManager::SetEquipPotionItem(EPotionType itemType)
{
	if (equipPotion != nullptr)
	{
		equipPotion->bselectedItem = false;
	}
	switch (itemType)
	{
	case EPotionType::ePotionType_LowPotion:
		equipPotion = LowPotion;
		break;
	case EPotionType::ePotionType_MiddlePotion:
		equipPotion = MiddlePotion;
		break;
	case EPotionType::ePotionType_HighPotion:
		equipPotion = HighPotion;
		break;
	default:
		equipPotion = nullptr;
		break;
	}
	equipPotion->bselectedItem = true;
}

EPotionType UInventoryManager::GetEquipPotionItemType()
{
	return equipPotion->potionType;
}

UPotionItem* UInventoryManager::GetEquipPotionItem()
{
	return equipPotion;
}

TArray<UEquipItem*> UInventoryManager::GetEquipItemArray()
{
	return equipItemArray;
}

void UInventoryManager::SetEquipItemArray(TArray<UEquipItem*> arr)
{
	equipItemArray = arr;
	equipWeapon = arr[0];
	equipHelmet = arr[1];
	equipArmor = arr[2];
	equipShoes = arr[3];
}

void UInventoryManager::SetPotions(UPotionItem* low, UPotionItem* middle, UPotionItem* high)
{
	LowPotion = low;
	MiddlePotion = middle;
	HighPotion = high;
}

UPotionItem* UInventoryManager::GetLowPotion()
{
	return LowPotion;
}

UPotionItem* UInventoryManager::GetMiddlePotion()
{
	return MiddlePotion;
}

UPotionItem* UInventoryManager::GetHighPotion()
{
	return HighPotion;
}
