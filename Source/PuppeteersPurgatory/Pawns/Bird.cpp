// Fill out your copyright notice in the Description page of Project Settings.
#include "Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


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

	//Camera settings
	//Create & attach components
	// - spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	// - spring arm valiables
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 60.0f, 50.0f), FRotator(0.0f, -40.0f, 0.0f));
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// - View camera
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);



	//Set as first player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(IMC_Bird, 0);
		}
	}

	
}

//void ABird::MoveForward(float Value)
//{
//	if (Controller && (Value != 0.f)) {
//		FVector Forward = GetActorForwardVector();
//		AddMovementInput(Forward, Value);
//	}
//}

void ABird::Move(const FInputActionValue& Value)
{
	const float DirectionValue = Value.Get<float>();
	if (Controller && (DirectionValue != 0.f)) {
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, DirectionValue);
	}
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

	if (UEnhancedInputComponent* EIComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABird::Move);
	}
	//PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABird::MoveForward);

}

