// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonStruct.h"
#include "SkillBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNSOUL5_API USkillBase : public UObject
{
	GENERATED_BODY()
		
public:
	UFUNCTION(BlueprintCallable)
		bool IsMaxPoint();

public:
	UPROPERTY(BlueprintReadWrite)
		ESkillTemplateId templateId;

	UPROPERTY(BlueprintReadWrite)
		int32 maxPoint;

	UPROPERTY(BlueprintReadWrite)
		int32 skillPoint = 0;

	UPROPERTY(BlueprintReadWrite)
		FSkillData skillData;
};
