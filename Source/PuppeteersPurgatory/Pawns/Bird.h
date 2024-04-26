// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"

//forward declarations (pointers only)
class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PUPPETEERSPURGATORY_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//void MoveForward(float Value);

	//Enhanced Input Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<UInputMappingContext> IMC_Bird;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);

private:
	// Capsule pointer
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UCapsuleComponent> Capsule;
	// Skeletal Mesh pointer
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<USkeletalMeshComponent> SK_Bird;
	//Camera Arm & View
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UCameraComponent> ViewCamera;
};
