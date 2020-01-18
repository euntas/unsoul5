// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManager.h"
#include "PassiveSkill.h"
#include "ActiveSkill.h"

USkillManager::USkillManager()
{
	Init();
}

void USkillManager::Init()
{
	AddPassiveSkillArray(MakePassiveSkill(ESkillTemplateId::eSkillTemplateId_Passive1));
	AddPassiveSkillArray(MakePassiveSkill(ESkillTemplateId::eSkillTemplateId_Passive2));
	AddPassiveSkillArray(MakePassiveSkill(ESkillTemplateId::eSkillTemplateId_Passive3));
	AddPassiveSkillArray(MakePassiveSkill(ESkillTemplateId::eSkillTemplateId_Passive4));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active1));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active12));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active2));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active22));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active3));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active32));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active4));
	AddActiveSkillArray(MakeActiveSkill(ESkillTemplateId::eSkillTemplateId_Active42));
}

UPassiveSkill* USkillManager::MakePassiveSkill(ESkillTemplateId inTemplateId)
{
	UPassiveSkill* newSkill = Cast<UPassiveSkill>(NewObject<UPassiveSkill>());
	newSkill->templateId = inTemplateId;
	newSkill->skillPoint = 0;
	newSkill->maxPoint = 5;

	return newSkill;
}

UActiveSkill* USkillManager::MakeActiveSkill(ESkillTemplateId inTemplateId)
{
	UActiveSkill* newSkill = Cast<UActiveSkill>(NewObject<UActiveSkill>());
	newSkill->templateId = inTemplateId;
	newSkill->skillPoint = 1;
	newSkill->maxPoint = 10;

	return newSkill;
}

void USkillManager::AddActiveSkillArray(UActiveSkill* ASkill)
{
	ActiveSkillArray.Add(ASkill);
}

void USkillManager::AddPassiveSkillArray(UPassiveSkill* PSkill)
{
	PassiveSkillArray.Add(PSkill);
}

TArray<UActiveSkill*> USkillManager::GetActiveSkillArray()
{
	return ActiveSkillArray;
}

void USkillManager::SetActiveSkillArray(TArray<UActiveSkill*> ActiveSkill)
{
	ActiveSkillArray = ActiveSkill;
}

TArray<UPassiveSkill*> USkillManager::GetPassiveSkillArray()
{
	return PassiveSkillArray;
}

void USkillManager::SetPassiveSkillArray(TArray<UPassiveSkill*> PassiveSkill)
{
	PassiveSkillArray = PassiveSkill;
}

UActiveSkill* USkillManager::GetActiveSkillArrayWithId(ESkillTemplateId inTemplateId)
{
	for (auto it : ActiveSkillArray)
	{
		if (it->templateId == inTemplateId)
			return it;
	}
	return nullptr;
}

UPassiveSkill* USkillManager::GetPassiveSkillArrayWithId(ESkillTemplateId inTemplateId)
{
	for (auto it : PassiveSkillArray)
	{
		if (it->templateId == inTemplateId)
			return it;
	}
	return nullptr;
}

