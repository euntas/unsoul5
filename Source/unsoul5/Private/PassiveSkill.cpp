// Fill out your copyright notice in the Description page of Project Settings.


#include "PassiveSkill.h"
#include "unsoul5Character.h"
#include "Unsoul5GameInstance.h"
#include "Engine/World.h"


void UPassiveSkill::PassiveSkill1AtkUp(Aunsoul5Character* morglay)
{
	UUnsoul5GameInstance* gameInstance = Cast<UUnsoul5GameInstance>(morglay->GetGameInstance());
	if (gameInstance != nullptr)
	{
		skillPoint += 1;
		gameInstance->GetSkillMgr()->passiveAttack = gameInstance->GetSkillTableData(ESkillTemplateId::eSkillTemplateId_Passive1, skillPoint).SkillDmg;
	}
}

void UPassiveSkill::PassiveSkill2HpUp(Aunsoul5Character* morglay)
{
	UUnsoul5GameInstance* gameInstance = Cast<UUnsoul5GameInstance>(morglay->GetGameInstance());
	if (gameInstance != nullptr)
	{
		morglay->HP -= gameInstance->GetSkillMgr()->passiveMaxHp;
		morglay->MaxHP -= gameInstance->GetSkillMgr()->passiveMaxHp;
		skillPoint += 1;
		gameInstance->GetSkillMgr()->passiveMaxHp = gameInstance->GetSkillTableData(ESkillTemplateId::eSkillTemplateId_Passive2, skillPoint).SkillDmg;
		
		morglay->HP += gameInstance->GetSkillMgr()->passiveMaxHp;
		morglay->MaxHP += gameInstance->GetSkillMgr()->passiveMaxHp;
	}
}

void UPassiveSkill::PassiveSkill3DefUp(Aunsoul5Character* morglay)
{
	UUnsoul5GameInstance* gameInstance = Cast<UUnsoul5GameInstance>(morglay->GetGameInstance());
	if (gameInstance != nullptr)
	{
		skillPoint += 1;
		gameInstance->GetSkillMgr()->passiveDefense = gameInstance->GetSkillTableData(ESkillTemplateId::eSkillTemplateId_Passive3, skillPoint).SkillDmg;
	}
}

void UPassiveSkill::PassiveSkill4CriUp(Aunsoul5Character* morglay)
{
	UUnsoul5GameInstance* gameInstance = Cast<UUnsoul5GameInstance>(morglay->GetGameInstance());
	if (gameInstance != nullptr)
	{
		skillPoint += 1;
		gameInstance->GetSkillMgr()->passiveCriRate = gameInstance->GetSkillTableData(ESkillTemplateId::eSkillTemplateId_Passive4, skillPoint).SkillDmg;
	}
}