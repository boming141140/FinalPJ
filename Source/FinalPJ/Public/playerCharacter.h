// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Character.h"
#include "playerCharacter.generated.h"

UCLASS()
class FINALPJ_API AplayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AplayerCharacter();
	UStaticMeshComponent* MeshComponentForCharacter;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Sets default values for this character's properties

	// Function to move the cylinder in the X direction
	void MoveCylinderForward(float Value);

	// Function to move the cylinder in the Y direction
	void MoveCylinderRight(float Value);

	void PitchInput(float val);
};
