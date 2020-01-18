// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "unsoul5Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "TargetingComponent.h"
#include "Enemy.h"
#include "Engine/World.h"
#include "BattleLogic.h"
#include "RangeAttack.h"
#include "Unsoul5GameInstance.h"

Aunsoul5Character::Aunsoul5Character()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bActionStop = false;
	//bAttacking = false;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	//static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	/*if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}*/
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	TargetComponent = CreateDefaultSubobject<UTargetingComponent>("TargetingSystem");
	AddOwnedComponent(TargetComponent);

	RangeAttack = CreateDefaultSubobject<URangeAttack>("RangeAttack");
	//RangeAttack->
	RangeAttack->SetAutoActivate(true);
	RangeAttack->SetupAttachment(RootComponent);

	SearchToCollsion = CreateDefaultSubobject<USphereComponent>("SphereToCollision");
	SearchToCollsion->SetupAttachment(RootComponent);
	SearchToCollsion->InitSphereRadius(500.0f);
	SearchToCollsion->SetHiddenInGame(true);


	SearchToCollsion->OnComponentBeginOverlap.AddDynamic(this, &Aunsoul5Character::OnBeginOverlap);
	SearchToCollsion->OnComponentEndOverlap.AddDynamic(this, &Aunsoul5Character::OnEndOverlap);

	// �÷��̾� ���� �ʱ�ȭ TODO. ���߿� �Լ�ȭ �ʿ�
	// �÷��̾� ����
	CurrentDeltaTime = 0.0f;

	skillMgr = Cast<USkillManager>(NewObject<USkillManager>());	
	//���߿� ���� �Ѵ�

}
bool Aunsoul5Character::CheckAttack()
{
	if (bActionStop)
	{
		CurrentDeltaTime = DeltaTime;
		return true;
	}
	return false;
}
void Aunsoul5Character::BeginPlay()
{
	Super::BeginPlay();

}

//void Aunsoul5Character::InitCharacter(int32 Level)
//{
//	PlayerLevel = 100;
//
//	// HP
//	HP = 100;
//
//	// MP
//	MP = 100;
//
//	// �ִ� ü��
//	MaxHP = 100;
//
//	// �ִ� ����
//	MaxMP = 100;
//
//	// ���ݷ�
//	AttackDmg = 100;
//
//	// ���� �ӵ�
//	AttackSpeed = 100;
//
//	// ����
//	Defense = 100;
//
//	// ũ��Ƽ�� Ȯ��
//	CriticalRatio = 100;
//
//	// ũ��Ƽ�� ������
//	CriticalDmg = 100;
//
//	// �̵� �ӵ�
//	MoveSpeed = 100;
//
//	// �޸��� �ӵ�
//	SprintSpeed = 100;
//
//	// ����ġ
//	Exp = 100;
//
//	// �ִ� ����ġ
//	MaxExp = 100;
//
//	// ���� ��ų����Ʈ
//	Skillpoint = 20;
//}

USceneComponent* Aunsoul5Character::GetRootComponent()
{
	return RootComponent;
}

void Aunsoul5Character::SetTarget()
{
	TargetComponent->SetTargeter(this);
	TargetComponent->SearchTarget();

	if (TargetComponent->IsTarget())
	{
		bActionStop = false;
	}
	else
	{
		bActionStop = true;
	}
}

void Aunsoul5Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	DeltaTime += DeltaSeconds;

}

void Aunsoul5Character::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UWorld * World = GetWorld())
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);

		if (Enemy != nullptr)
		{
			TargetComponent->AddSearchList(OtherActor);
		}
	}
}


void Aunsoul5Character::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (UWorld * World = GetWorld())
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);

		if (Enemy != nullptr)
		{
			TargetComponent->RemoveSearchList(OtherActor);
		}
	}
}