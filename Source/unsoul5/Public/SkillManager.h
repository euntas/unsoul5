// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonStruct.h"
#include "SkillManager.generated.h"

/**
 * 
 */
UCLASS()
class UNSOUL5_API USkillManager : public UObject
{
	GENERATED_BODY()

		USkillManager();

public:
	UFUNCTION()
		void Init();

	UFUNCTION(BlueprintCallable)
		class UPassiveSkill* MakePassiveSkill(ESkillTemplateId inTemplateId);

	UFUNCTION(BlueprintCallable)
		class UActiveSkill* MakeActiveSkill(ESkillTemplateId inTemplateId);

	UFUNCTION(BlueprintCallable)
		void AddActiveSkillArray(UActiveSkill* ASkill);

	UFUNCTION(BlueprintCallable)
		void AddPassiveSkillArray(UPassiveSkill* PSkill);

	UFUNCTION(BlueprintCallable)
		TArray<UActiveSkill*> GetActiveSkillArray();

	UFUNCTION(BlueprintCallable)
		void SetActiveSkillArray(TArray<UActiveSkill*> ActiveSkill);

	UFUNCTION(BlueprintCallable)
		TArray<UPassiveSkill*> GetPassiveSkillArray();

	UFUNCTION(BlueprintCallable)
		void SetPassiveSkillArray(TArray<UPassiveSkill*> PassiveSkill);

	UFUNCTION(BlueprintCallable)
		UActiveSkill* GetActiveSkillArrayWithId(ESkillTemplateId inTemplateId);

	UFUNCTION(BlueprintCallable)
		UPassiveSkill* GetPassiveSkillArrayWithId(ESkillTemplateId inTemplateId);

public:
	UPROPERTY()
		TArray<UActiveSkill*> ActiveSkillArray;

	UPROPERTY()
		TArray<UPassiveSkill*> PassiveSkillArray;

	UPROPERTY(BlueprintReadWrite)
		int32 passiveAttack;

	UPROPERTY(BlueprintReadWrite)
		int32 passiveMaxHp;

	UPROPERTY(BlueprintReadWrite)
		int32 passiveDefense;

	UPROPERTY(BlueprintReadWrite)
		int32 passiveCriRate;
};
