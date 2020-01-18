// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestManager.h"
#include "Public/Unsoul5GameInstance.h"
#include "unsoul5Character.h"
#include "Engine/World.h"

UQuestManager::UQuestManager()
{
	Init();
}

void UQuestManager::Init()
{
	CurrentDisplayQuestId = 1;
}

void UQuestManager::SetNextDisplayQuest(AActor* APlayer)
{
	int32 NextQuestId = CurrentDisplayQuestId + 1;

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	UDataTable* questTable = GameInstance->GetQuestTable();

	auto Names = questTable->GetRowNames();

	for (int i = 0; i < Names.Num(); i++)
	{
		auto record = questTable->FindRow<FQuestData>(Names[i], FString());

		// NextQuestId ����Ʈ�� ���̺� �����Ѵ�
		if (record->TemplateId == NextQuestId)
		{
			// ���� ��� ����Ʈ�� ��쿡�� ����
			if (record->QuestType == EQuestType::eQuestType_Monster)
			{
				CurrentDisplayQuestId = NextQuestId;
				break;
			}
		}
	}

	// ���� ���÷��� ����Ʈ�� ������� CurrentDisplayQuestId �� �״�� �д�. TODO. ���� ���� �ʿ�
}

bool UQuestManager::CanAcceptQuest(AActor* APlayer, int32 QuestId)
{
	// ������ ������ ����Ʈ�� �ȵȴ�.
	for (FQuestInfo elem : AcceptedQuestInfoList)
	{
		if (elem.QuestId == QuestId)
		{
			return false;
		}
	}

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	FQuestData tableData = GameInstance->GetQuestDataByTemplateID(QuestId);

	// ���� ���� npc ã�� ����Ʈ�� �ƴϸ� ������ �� ����.
	if (!(tableData.QuestType == EQuestType::eQuestType_Monster || tableData.QuestType == EQuestType::eQuestType_NPC))
	{
		return false;
	}

	// TODO. ��ȿ ����Ʈ id�� Ȯ���ؾ��Ѵ�.

	return true;
}

FQuestInfo UQuestManager::GetQuestInfo(AActor* APlayer, int32 QuestId)
{
	FQuestInfo result;

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	FQuestData tableData = GameInstance->GetQuestDataByTemplateID(QuestId);

	result.QuestId = QuestId;
	result.IsClear = false;
	result.DefaultQuestDetail = tableData;

	if (tableData.DestVectorX != -1)
	{
		result.HasNPCLocation = true;
	}
	else
	{
		result.HasNPCLocation = false;
	}

	result.MonsterIds.Init(-1, 3);
	result.ItemIds.Init(-1, 3);

	result.MonsterIds[0] = tableData.ReqMonsterId1;
	result.MonsterIds[1] = tableData.ReqMonsterId2;
	result.MonsterIds[2] = tableData.ReqMonsterId3;

	result.ItemIds[0] = tableData.ReqItemStringId1;
	result.ItemIds[1] = tableData.ReqItemStringId2;
	result.ItemIds[2] = tableData.ReqItemStringId3;

	result.MonsterCnts.Init(0, 3);
	result.ItemCnts.Init(0, 3);

	return result;
}

bool UQuestManager::AcceptQuest(AActor* APlayer, int32 QuestId)
{
	if (!UQuestManager::CanAcceptQuest(APlayer, QuestId))
	{
		return false;
	}

	FQuestInfo ResultQuestData;
	ResultQuestData = UQuestManager::GetQuestInfo(APlayer, QuestId);

	AcceptedQuestInfoList.Add(ResultQuestData);
	CurrentAcceptedQuestId = QuestId;

	return true;
}

FString UQuestManager::GetCurrentQuestInfoText(AActor* APlayer)
{
	FString ResultString;

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	int32 InfoListIndex = -1;
	
	for (FQuestInfo QuestInfo : AcceptedQuestInfoList)
	{
		// ���� ���÷��� ����Ʈ id �� ������ ������ ã�´�
		if (QuestInfo.QuestId == CurrentDisplayQuestId)
		{
			for (int i = 0; i < 3; i++)
			{
				int MonsterId = QuestInfo.MonsterIds[i];
				int MonsterCnt = QuestInfo.MonsterCnts[i];

				if (MonsterId != -1)
				{
					FString MonsterName = GameInstance->GetStringTableData(GameInstance->GetMonsterDataByTemplateID(MonsterId).StringID).StringDescriptionId.ToString();
					ResultString.Append(MonsterName);
					ResultString.Append(" : ");
					ResultString.Append(FString::FromInt(MonsterCnt));
					ResultString.Append("    ");
				}
			}
			break;
		}
	}

	return ResultString;
}

TArray<FString> UQuestManager::GetQuestText(AActor* APlayer, int32 QuestId)
{
	TArray<FString> result;

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());
	
	FQuestData tableData = GameInstance->GetQuestDataByTemplateID(QuestId);
	FString TitleTextOrigin = GameInstance->GetStringTableData(tableData.TitleStringId).StringDescriptionId.ToString();
	FString ContentTextOrigin = GameInstance->GetStringTableData(tableData.DescStringId).StringDescriptionId.ToString();

	TArray<FString> QuestContents;
	ContentTextOrigin.ParseIntoArray(QuestContents, TEXT("#"));

	result.Add(TitleTextOrigin);

	for (auto text : QuestContents)
	{
		// ���� �̸�
		if (text.Contains(TEXT("{NameMonster1}")))
		{
			FString MonsterName = GameInstance->GetStringTableData(GameInstance->GetMonsterDataByTemplateID(tableData.ReqMonsterId1).StringID).StringDescriptionId.ToString();
			text.ReplaceInline(TEXT("{NameMonster1}"), *MonsterName);
		}

		if (text.Contains(TEXT("{NameMonster2}")))
		{
			FString MonsterName = GameInstance->GetStringTableData(GameInstance->GetMonsterDataByTemplateID(tableData.ReqMonsterId2).StringID).StringDescriptionId.ToString();
			text.ReplaceInline(TEXT("{NameMonster2}"), *MonsterName);
		}

		if (text.Contains(TEXT("{NameMonster3}")))
		{
			FString MonsterName = GameInstance->GetStringTableData(GameInstance->GetMonsterDataByTemplateID(tableData.ReqMonsterId3).StringID).StringDescriptionId.ToString();
			text.ReplaceInline(TEXT("{NameMonster3}"), *MonsterName);
		}

		// ���� ����
		if (text.Contains(TEXT("{CntMonster1}")))
		{
			FString MonsterCnt = FString::FromInt(tableData.ReqMonsterCnt1);
			text.ReplaceInline(TEXT("{CntMonster1}"), *MonsterCnt);
		}

		if (text.Contains(TEXT("{CntMonster2}")))
		{
			FString MonsterCnt = FString::FromInt(tableData.ReqMonsterCnt2);
			text.ReplaceInline(TEXT("{CntMonster2}"), *MonsterCnt);
		}

		if (text.Contains(TEXT("{CntMonster3}")))
		{
			FString MonsterCnt = FString::FromInt(tableData.ReqMonsterCnt3);
			text.ReplaceInline(TEXT("{CntMonster3}"), *MonsterCnt);
		}
		
		result.Add(text);
	}

	// ���� ���� �߰�
	if (result.Num() > 0)
	{
		FString RewardStr = TEXT("Gold : {gold}, Exp : {exp}");
		RewardStr.ReplaceInline(TEXT("{gold}"), *FString::FromInt(tableData.ResultGold));
		RewardStr.ReplaceInline(TEXT("{exp}"), *FString::FromInt(tableData.ResultExp));

		result.Add(RewardStr);
	}

	return result;
}

FQuestInfo UQuestManager::GetCurrentAcceptedQuestInfo(AActor* APlayer)
{
	FQuestInfo ResultInfo;

	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	int32 InfoListIndex = -1;

	for (FQuestInfo QuestInfo : AcceptedQuestInfoList)
	{
		// ���� ���÷��� ����Ʈ id �� ������ ������ ã�´�
		if (QuestInfo.QuestId == CurrentAcceptedQuestId)
		{
			ResultInfo = QuestInfo;
			break;
		}
	}

	return ResultInfo;
}

bool UQuestManager::AddMonsterCnt(AActor* APlayer, int32 EnemyId)
{
	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	for (FQuestInfo& QuestInfo : AcceptedQuestInfoList)
	{
		// ���� ���� ����Ʈ id �� ������ ������ ã�´�
		if (QuestInfo.QuestId == CurrentAcceptedQuestId)
		{
			for (int i = 0; i < 3; i++)
			{
				if (QuestInfo.MonsterIds[i] == EnemyId)
				{
					// ���� ������ 1 �ø���
					QuestInfo.MonsterCnts[i] += 1;

					// ��ƾ��� �������� Ŀ���� �ʵ��� ����.
					switch (i)
					{
					case 0:
						if (QuestInfo.MonsterCnts[i] > QuestInfo.DefaultQuestDetail.ReqMonsterCnt1)
						{
							QuestInfo.MonsterCnts[i] = QuestInfo.DefaultQuestDetail.ReqMonsterCnt1;
						}
						break;
					case 1:
						if (QuestInfo.MonsterCnts[i] > QuestInfo.DefaultQuestDetail.ReqMonsterCnt2)
						{
							QuestInfo.MonsterCnts[i] = QuestInfo.DefaultQuestDetail.ReqMonsterCnt2;
						}
						break;
					case 2:
						if (QuestInfo.MonsterCnts[i] > QuestInfo.DefaultQuestDetail.ReqMonsterCnt3)
						{
							QuestInfo.MonsterCnts[i] = QuestInfo.DefaultQuestDetail.ReqMonsterCnt3;
						}
						break;
					}
					
					// Hud ������ ���� ��û
					Player->RefreshQuestTextForHud();

					return true;
				}
			}

			break;
		}
	}

	return false;
}

bool UQuestManager::IsQuestClear(AActor* APlayer)
{
	Aunsoul5Character* Player = Cast<Aunsoul5Character>(APlayer);
	UUnsoul5GameInstance* GameInstance = Cast<UUnsoul5GameInstance>(Player->GetGameInstance());

	for (FQuestInfo& QuestInfo : AcceptedQuestInfoList)
	{
		// ���� ���� ����Ʈ id �� ������ ������ ã�´�
		if (QuestInfo.QuestId == CurrentAcceptedQuestId)
		{
			// ���� ��⸸ �ϴ� ����Ʈ�� ���
			if (QuestInfo.DefaultQuestDetail.QuestType == EQuestType::eQuestType_Monster)
			{
				if (QuestInfo.MonsterCnts[0] >= QuestInfo.DefaultQuestDetail.ReqMonsterCnt1
					&& QuestInfo.MonsterCnts[1] >= QuestInfo.DefaultQuestDetail.ReqMonsterCnt2
					&& QuestInfo.MonsterCnts[2] >= QuestInfo.DefaultQuestDetail.ReqMonsterCnt3)
				{
					QuestInfo.IsClear = true;

					return true;
				}
			}
		}
	}

	return false;
}