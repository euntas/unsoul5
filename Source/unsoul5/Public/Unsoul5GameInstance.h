// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "CommonStruct.h"
#include "Unsoul5GameInstance.generated.h"


class UInventoryManager;
class UBattleLogic;
class USkillMaker;
class USkillManager;
class Aunsoul5Character;
class UUnSoul5SaveGame;
class UCharacterManager;
class UQuestManager;

/**
 * 
 */
UCLASS()
class UNSOUL5_API UUnsoul5GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UUnsoul5GameInstance();

	UFUNCTION(BlueprintCallable)
		void LevelRelease();

	UFUNCTION(BlueprintCallable)
		UInventoryManager* GetInventoryMgr();

	UFUNCTION(BlueprintCallable)
		UBattleLogic* GetBattleLogic();

	UFUNCTION(BlueprintCallable)
		USkillManager* GetSkillMgr();
	
	UFUNCTION(BlueprintCallable)
		UUnSoul5SaveGame* GetSaveGame();
	
	UFUNCTION()
		UCharacterManager* GetCharacterManager();

	UFUNCTION(BlueprintCallable)
		UQuestManager* GetQuestManager();

	virtual void Init() override;

	virtual void Shutdown() override;


	UFUNCTION(BlueprintCallable)
		const FPotionItemData& GetPotionTableData(EItemTemplateId InTemplateID);

	UFUNCTION(BlueprintCallable)
		const FSkillData& GetSkillTableData(ESkillTemplateId InSkillTemplateID, int32 inskillLevel);

	UFUNCTION(BlueprintCallable)
		UTexture2D* LoadTextureFromPath(const FString& Path);

	UFUNCTION(BlueprintCallable)
		const FEnemySkillData& GetEnemySkillData(int32 EnemyId, int32 EnemyAttackId);

	UFUNCTION(BlueprintCallable)
		const FMonsterData& GetMonsterDataByTemplateID(int32 MonsterTemplateId);

	UFUNCTION(BlueprintCallable)
		const FEquipItemData& GetEquipItemTableData(EItemTemplateId InTemplateID);

	UFUNCTION(BlueprintCallable)
		TArray<EItemTemplateId> GetLevelEquipItemTables(int32 inLevel);


	UFUNCTION(BlueprintCallable)
		const FEquipItemAbilityData& GetEquipItemAbilityTableData(EItemTemplateId InTemplateID);

	UFUNCTION(BlueprintCallable)
		TArray<FRespawnData> GetRespawnInfo(TArray<int32> MonsterTemplateIds);

	UFUNCTION(BlueprintCallable)
		const FCharacterStatData& GetCharacterStatTableData(int32 inLevel);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		TSubclassOf<Aunsoul5Character> PlayerBlueprint;

	UFUNCTION(BlueprintCallable)
		const FStringData& GetStringTableData(int32 inTemplateId);

	UFUNCTION(BlueprintCallable)
		const FQuestData& GetQuestDataByTemplateID(int32 QuestId);

	UFUNCTION(BlueprintCallable)
		UDataTable* GetQuestTable();

	UFUNCTION(BlueprintCallable)
		void SetVideoPlayOnce(bool VideoPlay);

	UFUNCTION(BlueprintCallable)
		bool GetVideoPlayOnce();

	UFUNCTION(BlueprintCallable, Category = "Game")
		void MyQuitGame(bool bForce);

private:
	UPROPERTY()
		UInventoryManager* InvenMgr;

	UPROPERTY()
		UBattleLogic* BattleLogic;

	UPROPERTY()
		USkillManager* SkillMgr;

	UPROPERTY()
		UUnSoul5SaveGame* SaveGame;

	UPROPERTY()
		UQuestManager* QuestManager;

	UPROPERTY()
		bool bVideoPlayOnce;

	//캐릭터 리스트 저장
	UPROPERTY()
		UCharacterManager* CharacterManager;

	UPROPERTY()
		TArray<TSoftObjectPtr<UDataTable>> DataTables;

	FPotionItemData EmptyPotionTable;
	FSkillData EmptySkillTable;
	FEnemySkillData ResultEnemySkillTable;
	FMonsterData ResultMonsterTable;
	FEquipItemData EmptyEquipItemTable;
	FEquipItemAbilityData EmptyEquipItemAbilityTable;
	FCharacterStatData EmptyCharacterStatTable;
	FStringData EmptyStringTable;
	FQuestData ResultQuestTable;

	UDataTable* potionTable;
	UDataTable* skillTable;
	UDataTable* enemySkillTable;
	UDataTable* monsterTable;
	UDataTable* equipItemTable;
	UDataTable* equipItemAbilityTable;
	UDataTable* characterStatTable;
	UDataTable* stringTable;
	UDataTable* questTable;
};
