// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "unsoul5PlayerController.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "unsoul5Character.h"
#include "TargetingComponent.h"
#include "Engine/World.h"

Aunsoul5PlayerController::Aunsoul5PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void Aunsoul5PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired

	MoveTo();

}

void Aunsoul5PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &Aunsoul5PlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &Aunsoul5PlayerController::OnSetDestinationReleased);

	// support touch devices 
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &Aunsoul5PlayerController::MoveToTouchLocation);
	//InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &Aunsoul5PlayerController::MoveToTouchLocation);
}

void Aunsoul5PlayerController::MoveTo()
{
	if (Aunsoul5Character * MyPawn = Cast<Aunsoul5Character>(GetPawn()))
	{
		if (MyPawn->GetTargetingSystem()->IsTarget() && !MyPawn->bActionStop)
		{
			FVector DestLocation = MyPawn->GetTargetingSystem()->GetTargetLocation();//MyPawn->GetCursorToWorld()->GetComponentLocation();
			float const Distance = FVector::Dist2D(DestLocation, MyPawn->GetActorLocation());
			FRotator rot = (DestLocation - MyPawn->GetActorLocation()).Rotation();
			rot.Pitch = 0.0f;
			rot.Roll = 0.0f;
			float ActorLength = MyPawn->GetTargetingSystem()->Target.Get()->GetSimpleCollisionHalfHeight() + MyPawn->GetSimpleCollisionHalfHeight();
			
			if (Distance > ActorLength + 40.0f)
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
			}
			else
			{
				MyPawn->SetActorRotation(rot);
				MyPawn->bActionStop = true;
				StopMovement();
				MyPawn->MoveStop();
			}
		}
	}
}

void Aunsoul5PlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void Aunsoul5PlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void Aunsoul5PlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void Aunsoul5PlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
