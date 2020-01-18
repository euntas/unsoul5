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

	// NPC 가 표시할 다음 퀘스트를 세팅한다
	UFUNCTION(BlueprintCallable)
		void SetNextDisplayQuest(AActor* APlayer);

	// QuestId 퀘스트 수락
	UFUNCTION(BlueprintCallable)
		bool AcceptQuest(AActor* APlayer, int32 QuestId);

	// 퀘스트를 받을 수 있는 상태인가?
	UFUNCTION(BlueprintCallable)
		bool CanAcceptQuest(AActor* APlayer, int32 QuestId);

	// 퀘스트 내용 표시를 위한 문자열
	UFUNCTION(BlueprintCallable)
		TArray<FString> GetQuestText(AActor* APlayer, int32 QuestId);

	// 퀘스트 현재 상황 표시를 위한 문자열
	UFUNCTION(BlueprintCallable)
		FString GetCurrentQuestInfoText(AActor* APlayer);

	// 퀘스트 정보
	UFUNCTION(BlueprintCallable)
		FQuestInfo GetQuestInfo(AActor* APlayer, int32 QuestId);

	// 현재 수락된 퀘스트의 정보를 가져온다 (현재 상태 및 클리어 체크는 이 정보를 보고 판단한다.) 값만 복사해옴 주의.
	UFUNCTION(BlueprintCallable)
		FQuestInfo GetCurrentAcceptedQuestInfo(AActor* APlayer);

	// 현재 퀘스트 관련 몬스터이면 monstercnt를 늘린다. 퀘스트 몬스터가 아니면 false 반환
	UFUNCTION(BlueprintCallable)
		bool AddMonsterCnt(AActor* APlayer, int32 EnemyId);

	// 현재 퀘스트를 클리어하였는가?
	UFUNCTION(BlueprintCallable)
		bool IsQuestClear(AActor* APlayer);

public:
	FQuestInfo EmptyQuestInfo;

	// 현재 NPC 가 표시할 퀘스트 Id
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentDisplayQuestId;

	// 현재 수락중인 퀘스트 Id (-1 이면 수락중인 퀘가 없음)
	UPROPERTY(BlueprintReadWrite)
		int32 CurrentAcceptedQuestId = -1;

	// 수락 퀘스트 리스트
	UPROPERTY(BlueprintReadWrite)
		TArray<FQuestInfo> AcceptedQuestInfoList;
};
