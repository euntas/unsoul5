// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleLogic.h"
#include "Public/Enemy.h"
#include "unsoul5Character.h"
#include "CharacterManager.h"
#include "Unsoul5GameInstance.h"
#include "Engine/World.h"
#include "unsoul5GameMode.h"
#include "EnemySpawn.h"
#include "TargetingComponent.h"
#include "RangeAttack.h"
#include "UnSoul5SaveGame.h"
#include "UnSoul5SaveGameData.h"
#include "Math/UnrealMathUtility.h"
#include "InventoryManager.h"
#include "SkillManager.h"
#include "PassiveSkill.h"
#include "QuestManager.h"

void UBattleLogic::EnemyBattle(AActor* _APlayer, AActor* _AEnemy)
{
	Aunsoul5Character* Player = Cast<Aunsoul5Character>(_APlayer);
	AEnemy* Enemy = Cast<AEnemy>(_AEnemy);

	//---- Enemy table 을 위한 테스트 start
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());
	bool bCritical = CriticalAttack(Enemy->EnemyCriticalRatio);
	int32 CriticalAttack = 1;

	if (bCritical)
	{
		CriticalAttack = 2;
	}

	float TotalDamage = (Enemy->EnemyAttackDmg * Enemy->CurrentEnemySkillInfo.SkillDmg) * Enemy->EnemyCriticalDmg - (Player->Defense + GetTotalPlayerDefense(_APlayer));

	if (TotalDamage <= 0)
	{
		TotalDamage = 1;
	}

	if (TargetLength(_AEnemy, _APlayer, Enemy->CurrentEnemySkillInfo.SkillATKRange))
	{
		TotalDamage = FMath::RoundFromZero(TotalDamage);

		Player->HP -= TotalDamage;	
		Player->CharacterHit(TotalDamage, bCritical);
	}
	if (Player->HP <= 0)
	{
		Player->HP = 0;
	}
}

void UBattleLogic::Battle(AActor* ATargeter, AActor* ATargeting, FSkillData SkillData)
{
	Aunsoul5Character* Player = Cast<Aunsoul5Character>(ATargeter);
	AEnemy* Enemy = Cast<AEnemy>(ATargeting);

	if (Enemy != nullptr)
	{
		if (SkillData.TargetType == ETargetType::eTargetType_AOE)
		{
			URangeAttack* RangeAttack = Player->GetRangeAttack();
			RangeAttack->Attack(ATargeter, &SkillData);

			for (auto& it : RangeAttack->GetRangeTargets())
			{
				AEnemy* RangeEnemy = Cast<AEnemy>(it.Get());
				if (RangeEnemy == nullptr)
				{
					continue;
				}

				bool bCritical = CriticalAttack(Player->CriticalRatio);
				float CriticalAttack = 1;
				int32 PlayerAttack = Player->AttackDmg + GetTotalPlayerDamage(ATargeter);

				if (bCritical)
				{
					CriticalAttack = 2;
				}

				float TotalDamage = (PlayerAttack * SkillData.SkillDmg) * CriticalAttack - RangeEnemy->EnemyDefense;

				if (TotalDamage <= 0)
				{
					TotalDamage = 1;
				}			

				RangeEnemy->EnemyHP -= FMath::RoundFromZero(TotalDamage);

				if (RangeEnemy->EnemyHP <= 0 && RangeEnemy->CurrentState != EStateType::eStateType_Die)
				{
					UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());
					Aunsoul5GameMode* GameMode = Cast<Aunsoul5GameMode>(GameInstance->GetWorld()->GetAuthGameMode());

					//Enemy->
					Player->Exp += RangeEnemy->EnemyExp;
					GameInstance->GetInventoryMgr()->IncreaseGold(RangeEnemy->EnemyLevel * 20);
					Drop(RangeEnemy);
					//Die

					GameInstance->GetCharacterManager()->RemoveCharacterList(ATargeting);
					GameMode->GetSpawnActor(RangeEnemy->EnemyId)->DeleteEnemy();

					if (Player->GetTargetingSystem()->Target == it.Get())
					{
						Player->GetTargetingSystem()->CancelTargeting();
					}

					RangeEnemy->EnemyHit(FMath::RoundFromZero(TotalDamage), bCritical);
					RangeEnemy->EnemyDie();
					// 퀘스트를 위해
					GameInstance->GetQuestManager()->AddMonsterCnt(Player, RangeEnemy->EnemyId);

				}
				else
				{
					RangeEnemy->EnemyHit(FMath::RoundFromZero(TotalDamage), bCritical);
				}
			}

			SaveCharacterData(Player);
			RangeAttack->Reset(SkillData.AreaType);
		}
		else
		{
			if (TargetLength(ATargeter, ATargeting, 100.0f))
			{
				bool bCritical = CriticalAttack(Player->CriticalRatio);
				float CriticalAttack = 1;
				int32 PlayerAttack = Player->AttackDmg + GetTotalPlayerDamage(ATargeter);

				if (bCritical)
				{
					CriticalAttack = 2;
				}

				if (SkillData.SkillDmg == 0)
				{
					SkillData.SkillDmg = 1;
				}

				float TotalDamage = (PlayerAttack * SkillData.SkillDmg) * CriticalAttack - Enemy->EnemyDefense;

				if (TotalDamage <= 0)
				{
					TotalDamage = 1;
				}

				Enemy->EnemyHP -= FMath::RoundFromZero(TotalDamage);

				if (Enemy->EnemyHP <= 0 && Enemy->CurrentState != EStateType::eStateType_Die)
				{
					//Die
					UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());
					Aunsoul5GameMode* GameMode = Cast<Aunsoul5GameMode>(GameInstance->GetWorld()->GetAuthGameMode());

					//Enemy->
					Player->Exp += Enemy->EnemyExp;
					GameInstance->GetInventoryMgr()->IncreaseGold(Enemy->EnemyLevel * 20);
					Drop(Enemy);

					GameInstance->GetCharacterManager()->RemoveCharacterList(ATargeting);
					GameMode->GetSpawnActor(Enemy->EnemyId)->DeleteEnemy();
					Player->GetTargetingSystem()->CancelTargeting();
					Enemy->EnemyHit(FMath::RoundFromZero(TotalDamage), bCritical);
					Enemy->EnemyDie();
					// 퀘스트를 위해
					GameInstance->GetQuestManager()->AddMonsterCnt(Player, Enemy->EnemyId);
				}
				else
				{
					Enemy->EnemyHit(FMath::RoundFromZero(TotalDamage), bCritical);
				}

				SaveCharacterData(Player);
			}
		}
	}
}

void UBattleLogic::SaveCharacterData(Aunsoul5Character* _APlayer)
{
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(_APlayer->GetGameInstance());
	FPlayerInfo PlayerInfo = GameInstance->GetSaveGame()->GetSaveGameData()->GetCharacterStatData();
	PlayerInfo.HP = _APlayer->HP;
	PlayerInfo.MP = _APlayer->MP;
	PlayerInfo.Exp = _APlayer->Exp;
	PlayerInfo.SkillPoint = _APlayer->Skillpoint;
	GameInstance->GetSaveGame()->GetSaveGameData()->SetCharacterStatData(PlayerInfo);
}

bool UBattleLogic::CriticalAttack(float CiritalPercentage)
{
	int32 Cirital = CiritalPercentage * 100;

	if (FMath::RandRange(1, 100) <= Cirital)
	{
		return true;
	}

	return false;
}

int32 UBattleLogic::GetTotalPlayerDamage(AActor* ATargeter)
{
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(ATargeter->GetGameInstance());
	UInventoryManager* Inven = GameInstance->GetInventoryMgr();
	USkillManager* SkillMgr = GameInstance->GetSkillMgr();
	int32 TotalDamage = SkillMgr->passiveAttack;

	for (auto it : Inven->GetEquipItemArray())
	{
		TotalDamage += it->attackDmg + it->attackDmgExtra;
	}

	return TotalDamage;
}

int32 UBattleLogic::GetTotalPlayerDefense(AActor* ATargeter)
{
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(ATargeter->GetGameInstance());
	UInventoryManager* Inven = GameInstance->GetInventoryMgr();
	USkillManager* SkillMgr = GameInstance->GetSkillMgr();
	int32 TotalDefense = SkillMgr->passiveDefense;

	for (auto it : Inven->GetEquipItemArray())
	{
		TotalDefense += it->defense + it->defenseExtra;
	}

	return TotalDefense;
}

void UBattleLogic::Drop(AEnemy* Enemy)
{
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Enemy->GetGameInstance());
	UInventoryManager* Inven = GameInstance->GetInventoryMgr();

	if (FMath::RandRange(1, 100) % FMath::RandRange(1, 10) == 0)
	{
		int ItemType = FMath::RandRange(0, Enemy->DropItemIdList.Num() - 1);
		if (Enemy->DropItemIdList.IsValidIndex(ItemType))
		{

			FEquipItemData item = GameInstance->GetEquipItemTableData(Enemy->DropItemIdList[ItemType]);
			FEquipItemAbilityData itemAbility = GameInstance->GetEquipItemAbilityTableData(Enemy->DropItemIdList[ItemType]);

			FItemData ItemData;

			ItemData.itemTemplateId = item.ItemTemplateId;
			ItemData.itemType = item.EquipItemType;

			ItemData.reqLevel = item.ReqLevel;
			ItemData.attackDmg = itemAbility.AttackDmg;
			ItemData.attackSpd = itemAbility.AttackSpeed;
			ItemData.defense = itemAbility.Defense;
			ItemData.criticalRatio = itemAbility.CriticalRatio;
			ItemData.criticalDmg = itemAbility.CriticalDmg;
			ItemData.speed = itemAbility.Speed;


			ItemData.attackDmgExtra = FMath::RandRange(itemAbility.AtkDmgMinExtra, itemAbility.AtkDmgMaxExtra);
			ItemData.attackSpdExtra = FMath::RandRange(itemAbility.AtkSpdMinExtra, itemAbility.AtkSpdMaxExtra);
			ItemData.defenseExtra = FMath::RandRange(itemAbility.DefMinExtra, itemAbility.DefMaxExtra);
			ItemData.criticalRatioExtra = FMath::RandRange(itemAbility.CriRatMinExtra, itemAbility.CriRatMaxExtra);
			ItemData.criticalDmgExtra = FMath::RandRange(itemAbility.CriDmgMinExtra, itemAbility.CriDmgMaxExtra);
			ItemData.speedExtra = FMath::RandRange(itemAbility.SpdMinExtra, itemAbility.SpdMaxExtra);


			ItemData.itemRank =
				(ItemData.attackDmgExtra + ItemData.attackSpdExtra + ItemData.defenseExtra + ItemData.criticalRatioExtra * 30 + ItemData.criticalDmgExtra * 30 + ItemData.speedExtra)
				/ (itemAbility.AtkDmgMaxExtra + itemAbility.AtkSpdMaxExtra + itemAbility.DefMaxExtra + itemAbility.CriRatMaxExtra * 30 + itemAbility.CriDmgMaxExtra * 30 + itemAbility.SpdMaxExtra);


			Inven->AddMakeitem(ItemData);
		}
	}
}

bool UBattleLogic::TargetLength(AActor* ATargeter, AActor* ATargeting, float AttackLength)
{
	FVector DestLocation = ATargeting->GetActorLocation();
	float const Distance = FVector::Dist2D(DestLocation, ATargeter->GetActorLocation());

	float ActorLength = ATargeting->GetSimpleCollisionHalfHeight();

	if (Distance > ActorLength + AttackLength)
	{
		return false;
	}

	return true;
}
