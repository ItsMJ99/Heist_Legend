// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"

#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
}

// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldMove)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLocation);
	}
}

// float t1 = 10;
// float *t2 = &t1;
// UE_LOG(LogTemp, Display, TEXT("t1 value = %f"), t1);		   // 10
// UE_LOG(LogTemp, Display, TEXT("t1 Address = %u"), &t1);		   // t1 add
// UE_LOG(LogTemp, Display, TEXT("t1 from t2 Address = %u"), t2); // t1 add
// UE_LOG(LogTemp, Display, TEXT("t2 Address = %u"), &t2);		   // t2 add
// UE_LOG(LogTemp, Display, TEXT("t1 value = %f"), *t2);		   // t2 val which is from t1 = 10

// AActor *Owner = GetOwner();
// // FString name = (*Owner).GetActorNameOrLabel();
// FString Name = Owner->GetActorNameOrLabel();
// FString Location = Owner->GetActorLocation().ToCompactString();

// UE_LOG(LogTemp, Display, TEXT("Mover Owner Address = %u"), Owner); // Actor add
// UE_LOG(LogTemp, Display, TEXT("Actor Name = %s"), *Name);
// UE_LOG(LogTemp, Display, TEXT("Actor Name = %s"), *Location);