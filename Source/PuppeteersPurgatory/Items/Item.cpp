// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(430.f, 920.f, 280.f));
	
}

float AItem::TransformedCosine()
{
	return AmpZ* FMath::Cos(RunningTime * PerZ);;
}

float AItem::TransformedSine()
{
	return AmpZ * FMath::Sin(RunningTime * PerZ);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

}

