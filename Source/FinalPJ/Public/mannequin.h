// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyUserWidget.h"
#include "MyInterface.h"
#include "mannequin.generated.h"

UCLASS()
class FINALPJ_API Amannequin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Amannequin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UMyUserWidget* MyWidget;
	IMyInterface* InteractableActors;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void AttemptInteract();
	void RayCasting();
};
