// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"

#include "Engine/World.h"

#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Green);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, Sphere);
	if (HasHit == true)
	{
		AActor *HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Display, TEXT("Actor Hit Name = %s"), *HitActor->GetActorNameOrLabel());
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Actor Hit"));
	}
}

// FString Rotation = GetComponentRotation().ToCompactString();
// UE_LOG(LogTemp, Display, TEXT("Rotation : %s"), *Rotation);

// float TimeSec = GetWorld()->TimeSeconds;
// UE_LOG(LogTemp, Display, TEXT("Time Seconds : % f"), TimeSec);

// void UGrabber::PrintDamage(const float &Damage)
// {
// 	// Damage = 20;
// 	UE_LOG(LogTemp, Display, TEXT("Damage : %f"), Damage);
// }

// bool UGrabber::HasDamage(float &OutDamage)
// {
// 	OutDamage = 50;
// 	return true;
// }