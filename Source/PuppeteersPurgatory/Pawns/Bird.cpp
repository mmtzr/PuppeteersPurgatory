// Fill out your copyright notice in the Description page of Project Settings.
#include "Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Bird Capsule
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Bird Capsule"));
	Capsule->SetCapsuleRadius(15.f);
	Capsule->SetCapsuleHalfHeight(20.f);
	SetRootComponent(Capsule);
	
	//Bird Skeletal Mesh
	SK_Bird = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Bird SkMesh"));
	SK_Bird->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

