// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "CommonStruct.h"
#include "ActiveSkill.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class UNSOUL5_API UActiveSkill : public USkillBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void ActiveSkillUp(Aunsoul5Character* morglay);
};
