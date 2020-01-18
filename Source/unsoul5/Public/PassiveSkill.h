// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "CommonStruct.h"
#include "PassiveSkill.generated.h"

class Aunsoul5Character;
/**
 *
 */
UCLASS(BlueprintType)
class UNSOUL5_API UPassiveSkill : public USkillBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void PassiveSkill1AtkUp(Aunsoul5Character* morglay);

	UFUNCTION(BlueprintCallable)
		void PassiveSkill2HpUp(Aunsoul5Character* morglay);

	UFUNCTION(BlueprintCallable)
		void PassiveSkill3DefUp(Aunsoul5Character* morglay);

	UFUNCTION(BlueprintCallable)
		void PassiveSkill4CriUp(Aunsoul5Character* morglay);
};
