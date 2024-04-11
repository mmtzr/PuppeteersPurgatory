// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(430.f, 920.f, 280.f));
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	DeltaZ = AmpZ * FMath::Sin(RunningTime * PerZ);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	DRAW_RED_SPHERE_PF(GetActorLocation());
	DRAW_RED_VECTOR_PF(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

