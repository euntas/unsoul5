// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CommonStruct.h"
#include "RangeAttack.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNSOUL5_API URangeAttack : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URangeAttack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void Attack(AActor* _Targeter, FSkillData* _SkillData);

	TArray<TWeakObjectPtr<AActor>> GetRangeTargets();

	void Reset(EAreaType AreaType);
	
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void AddSearchList(AActor* ATarget);

	UFUNCTION()
		void RemoveSearchList(AActor* ATarget);

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Debug")
		bool bDebug;

private:
	

	UPROPERTY()
	FSkillData SkillData;
	

	UPROPERTY()
	TWeakObjectPtr<AActor> Targeter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* BoxCollision;

	UPROPERTY()
		TArray<TWeakObjectPtr<AActor>> SearchList;

};
