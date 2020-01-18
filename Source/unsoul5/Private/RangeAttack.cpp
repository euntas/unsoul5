// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeAttack.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Enemy.h"

// Sets default values for this component's properties
URangeAttack::URangeAttack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("RangeAtkSphere");
	SphereCollision->SetupAttachment(this);
	SphereCollision->InitSphereRadius(1.0f);
	SphereCollision->SetHiddenInGame(true);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &URangeAttack::OnBeginOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &URangeAttack::OnEndOverlap);
	SphereCollision->SetCollisionProfileName(TEXT("EnemySearch"));
	SphereCollision->SetRelativeLocation(FVector::ZeroVector);
	//SphereCollision->SetVisibility(true);
	//SphereCollision->SetAutoActivate(true);


	BoxCollision = CreateDefaultSubobject<UBoxComponent>("RangeAtkBox");
	BoxCollision->SetupAttachment(this);
	BoxCollision->InitBoxExtent(FVector(1.0f, 1.0f, 1.0f));
	BoxCollision->SetHiddenInGame(true);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &URangeAttack::OnBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &URangeAttack::OnEndOverlap);
	BoxCollision->SetCollisionProfileName(TEXT("EnemySearch"));
	BoxCollision->SetRelativeLocation(FVector::ZeroVector);
//	BoxCollision->SetVisibility(true);
	//BoxCollision->SetAutoActivate(true);
	
	// ...
}


// Called when the game starts
void URangeAttack::BeginPlay()
{
	Super::BeginPlay();

	// ...	
}

// Called every frame
void URangeAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URangeAttack::Attack(AActor* _Targeter, FSkillData* _SkillData)
{
	FVector Location(_SkillData->LocationY, _SkillData->LocationX, 0.0f);
	SearchList.Empty();

	if (_SkillData->AreaType == EAreaType::eAreaType_Rectangle)
	{
		FVector Extent(_SkillData->AreaX, _SkillData->AreaY, _SkillData->AreaX);
		
		if(bDebug)
		{
			DrawDebugBox(_Targeter->GetWorld(), _Targeter->GetActorTransform().GetLocation() + Location, Extent, FColor::Green, true, 10.0f, 0, 10);
		}
		BoxCollision->SetVisibility(true);
		BoxCollision->SetBoxExtent(Extent);
		BoxCollision->SetRelativeLocation(Location);
		UE_LOG(LogTemp, Log, TEXT("Box skillAreaX : %f, skillAreaY : %f, LocationX : %f, LocationY : %f"), _SkillData->AreaX, _SkillData->AreaY, _SkillData->LocationX, _SkillData->LocationY);

	//	BoxCollision->SetHiddenInGame(false);
	}
	else if (_SkillData->AreaType == EAreaType::eAreaType_Circle)
	{
		if (bDebug)
		{
			DrawDebugSphere(_Targeter->GetWorld(), _Targeter->GetActorTransform().GetLocation() + Location, _SkillData->AreaY, 26, FColor::Green, true, 10.0f, 0, 10);
		}
		SphereCollision->SetVisibility(true);
		SphereCollision->SetSphereRadius(_SkillData->AreaY);
		SphereCollision->SetRelativeLocation(Location);
		UE_LOG(LogTemp, Log, TEXT("Sphere skillAreaX : %f, skillAreaY : %f, LocationX : %f, LocationY : %f"), _SkillData->AreaX, _SkillData->AreaY, _SkillData->LocationX, _SkillData->LocationY);
		//SphereCollision->SetHiddenInGame(false);
	}
}

TArray<TWeakObjectPtr<AActor>> URangeAttack::GetRangeTargets()
{
	return SearchList;
}

void URangeAttack::Reset(EAreaType AreaType)
{

	if (AreaType == EAreaType::eAreaType_Rectangle)
	{
		BoxCollision->SetRelativeLocation(FVector::ZeroVector);
		BoxCollision->SetBoxExtent(FVector(1.0f, 1.0f, 1.0f));
	}
	else if (AreaType == EAreaType::eAreaType_Circle)
	{
		SphereCollision->SetRelativeLocation(FVector::ZeroVector);
		SphereCollision->SetSphereRadius(1.0f);
	}

	BoxCollision->SetVisibility(false);
	SphereCollision->SetVisibility(false);

	SearchList.Empty();
}

void URangeAttack::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UWorld * World = GetWorld())
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);

		if (Enemy != nullptr && Enemy->CurrentState != EStateType::eStateType_Die)
		{
			AddSearchList(OtherActor);
		}
	}
}

void URangeAttack::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (UWorld * World = GetWorld())
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);

		if (Enemy != nullptr)
		{
			RemoveSearchList(OtherActor);
		}
	}
}

void URangeAttack::AddSearchList(AActor* ATarget)
{
	if (!SearchList.Contains(ATarget))
	{
		SearchList.Add(ATarget);
	}
}

void URangeAttack::RemoveSearchList(AActor* ATarget)
{
	if (SearchList.Contains(ATarget))
	{
		SearchList.Remove(ATarget);
	}
}

