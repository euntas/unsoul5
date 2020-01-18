// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawn.generated.h"

UCLASS()
class UNSOUL5_API AEnemySpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintImplementableEvent)
		AActor* SpawnMonster();


	void CreateEnemy();
	void DeleteEnemy();

	void SelectMonster();
	
public:


	//몬스터 최대 수
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Spawn")
		int32 EnemyMaxCount;

	//몬스터 현재 수
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Spawn")
		int32 EnemyCount;
	
	//몬스터 태그 int? string?
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Spawn")
		int32 EnemyTag;

	//몬스터 리젠 시간
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Spawn")
		float RespawnTime;

	//몬스터 리젠 반경
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Spawn")
		float RespawnCircleRadius;

private:

	float Time;

	float CurrentTime;

	bool bFrist;
	   
};
