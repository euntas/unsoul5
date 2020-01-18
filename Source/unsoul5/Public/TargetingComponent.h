// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNSOUL5_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTargetingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool IsTarget();

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target")
		bool bTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
		float TargetRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target")
		TWeakObjectPtr<AActor> Target;

	UPROPERTY()
		TWeakObjectPtr<AActor> Targeter;

	UPROPERTY()
		uint32 TargetId;

	UPROPERTY()
		TArray<TWeakObjectPtr<AActor>> SearchList;

	UFUNCTION()
		void AddSearchList(AActor* ATarget);

	UFUNCTION()
		void RemoveSearchList(AActor* ATarget);

	UFUNCTION()
		bool SearchTarget();

	UFUNCTION()
		void SetTargeter(AActor* ATargeter);

	UFUNCTION()
		FVector GetTargetLocation();

	UFUNCTION(BlueprintCallable)
		void CancelTargeting();

		
};
