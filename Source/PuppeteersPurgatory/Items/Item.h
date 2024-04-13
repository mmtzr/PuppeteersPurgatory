// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuppeteersPurgatory/DebugMacros.h"
#include "Item.generated.h"

UCLASS()
class PUPPETEERSPURGATORY_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sine Parameters")
		float AmpZ = 0.25f; // amplitude (rad)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
		float PerZ = 5.f; // period (rad)
	// FUNCTIONS
	UFUNCTION(BlueprintPure)
		float TransformedSine();	
	UFUNCTION(BlueprintPure)
		float TransformedCosine();
private:
	// Track game running time
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float RunningTime;
	// add a static mesh component to the blueprint
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ItemMesh;

};
