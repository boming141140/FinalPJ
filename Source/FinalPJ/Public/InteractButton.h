// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "GameFramework/Actor.h"
#include "InteractButton.generated.h"

UCLASS()
class FINALPJ_API AInteractButton : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UMaterialInterface* ButtonMaterial;
	UStaticMeshComponent* MeshComponent;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	int32 marker;
	void OnInteract();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	AActor* ReferencedActor; // The type can be more specific if you know what you are referencing
};
