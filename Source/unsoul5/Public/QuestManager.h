// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonStruct.h"
#include "QuestManager.generated.h"

/**
 * 
 */
UCLASS()
class UNSOUL5_API UQuestManager : public UObject
{
	GENERATED_BODY()

	UQuestManager();

public:
	UFUNCTION()
		void Init();

	// NPC �� ǥ���� ���� ����Ʈ�� �����Ѵ�
	UFUNCTION(BlueprintCallable)
		void SetNextDisplayQuest(AActor* APlayer);

	// QuestId ����Ʈ ����
	UFUNCTION(BlueprintCallable)
		bool AcceptQuest(AActor* APlayer, int32 QuestId);

	// ����Ʈ�� ���� �� �ִ� �����ΰ�?
	UFUNCTION(BlueprintCallable)
		bool CanAcceptQuest(AActor* APlayer, int32 QuestId);

	// ����Ʈ ���� ǥ�ø� ���� ���ڿ�
	UFUNCTION(BlueprintCallable)
		TArray<FString> GetQuestText(AActor* APlayer, int32 QuestId);

	// ����Ʈ ���� ��Ȳ ǥ�ø� ���� ���ڿ�
	UFUNCTION(BlueprintCallable)
		FString GetCurrentQuestInfoText(AActor* APlayer);

	// ����Ʈ ����
	UFUNCTION(BlueprintCallable)
		FQuestInfo GetQuestInfo(AActor* APlayer, int32 QuestId);

	// ���� ������ ����Ʈ�� ������ �����´� (���� ���� �� Ŭ���� üũ�� �� ������ ���� �Ǵ��Ѵ�.) ���� �����ؿ� ����.
	UFUNCTION(BlueprintCallable)
		FQuestInfo GetCurrentAcceptedQuestInfo(AActor* APlayer);

	// ���� ����Ʈ ���� �����̸� monstercnt�� �ø���. ����Ʈ ���Ͱ� �ƴϸ� false ��ȯ
	UFUNCTION(BlueprintCallable)
		bool AddMonsterCnt(AActor* APlayer, int32 EnemyId);

	// ���� ����Ʈ�� Ŭ�����Ͽ��°�?
	UFUNCTION(BlueprintCallable)
		bool IsQuestClear(AActor* APlayer);

public:
	FQuestInfo EmptyQuestInfo;

	// ���� NPC �� ǥ���� ����Ʈ Id
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentDisplayQuestId;

	// ���� �������� ����Ʈ Id (-1 �̸� �������� ���� ����)
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentAcceptedQuestId = -1;

	// ���� ����Ʈ ����Ʈ
	UPROPERTY(BlueprintReadWrite)
		TArray<FQuestInfo> AcceptedQuestInfoList;
};
