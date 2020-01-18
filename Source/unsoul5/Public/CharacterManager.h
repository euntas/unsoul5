// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterManager.generated.h"

/**
 * 
 */

class AEnemy;

UCLASS()
class UNSOUL5_API UCharacterManager : public UObject
{
	GENERATED_BODY()
		
public:

	UCharacterManager();

	virtual void BeginDestroy() override;

	UFUNCTION()
		void Init();

	UFUNCTION()
		void Release();

	UFUNCTION()
		void AddCharacterList(AActor* ACharacter);

	UFUNCTION()
		void RemoveCharacterList(AActor* ACharacter);



public:

	UPROPERTY()
		TArray<AActor*> CharacterList;

};
