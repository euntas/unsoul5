// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetingComponent.h"
#include "Public/Enemy.h"
#include "unsoul5Character.h"

// Sets default values for this component's properties
UTargetingComponent::UTargetingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();
	Target.Reset();
	TargetRange = 1000.0f;

	// ...
	
}


// Called every frame
void UTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Target.IsValid())
	{
		AEnemy* Enemy = Cast<AEnemy>(Target.Get());
		
		if (Enemy->CurrentState == EStateType::eStateType_Die)
		{
			CancelTargeting();
		}
	}

	// ...
}


void UTargetingComponent::AddSearchList(AActor* ATarget)
{
	if (SearchList.Find(ATarget) == INDEX_NONE)
	{
		SearchList.Add(ATarget);
	}
}

void UTargetingComponent::RemoveSearchList(AActor* ATarget)
{
	if (SearchList.Find(ATarget) != INDEX_NONE)
	{
		if (ATarget == Target.Get())
		{
			AEnemy* Enemy = Cast<AEnemy>(Target.Get());

			CancelTargeting();
		}

		SearchList.Remove(ATarget);
	}
}

bool UTargetingComponent::SearchTarget()
{
	if (!bTargeting && Targeter.IsValid())
	{
		float min_distance = TargetRange;

		for (auto it : SearchList)
		{
			float distance = (Targeter->GetActorTransform().GetLocation() - it->GetActorTransform().GetLocation()).Size();
			AEnemy* Enemy = Cast<AEnemy>(it);

			if (min_distance > distance && Enemy->CurrentState != EStateType::eStateType_Die)
			{
				min_distance = distance;
				Target = it;
			}
		}

		if (Target.IsValid())
		{
			AEnemy* Enemy = Cast<AEnemy>(Target.Get());
			Enemy->SetVisibleTargetParticle(true);
			bTargeting = true;

			UE_LOG(LogTemp, Log, TEXT("Monster HP : %f"), Enemy->EnemyHP);

			return true;
		}

		//arget->
	}

	return false;
}

void UTargetingComponent::SetTargeter(AActor* ATargeter)
{
	if (ATargeter != nullptr)
	{
		Targeter = ATargeter;
	}
}

FVector UTargetingComponent::GetTargetLocation()
{
	if (Target.IsValid())
	{
		return Target->GetTargetLocation();
	}

	return Targeter->GetActorLocation();
}

void UTargetingComponent::CancelTargeting()
{
	if (Target.IsValid())
	{
		AEnemy* Enemy = Cast<AEnemy>(Target.Get());

		Enemy->SetVisibleTargetParticle(false);
		bTargeting = false;
		Target.Reset();
	}
}

bool UTargetingComponent::IsTarget()
{
	return Target.IsValid();
}