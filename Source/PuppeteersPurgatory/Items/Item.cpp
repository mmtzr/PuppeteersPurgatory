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
	UWorld* World = GetWorld();
	SetActorLocation(FVector(2200.f, 740.f, 130.f));
	SetActorRotation(FRotator(0.f, 45.f, 0.f)); // double in degrees

	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	DRAW_RED_SPHERE(Location);
	DRAW_RED_VECTOR(Location, Location + Forward * 100.f);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

