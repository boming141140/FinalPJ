// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "Blueprint/UserWidget.h"
#include "SpaceshipActor.generated.h"

UCLASS()
class FINALPJ_API ASpaceshipActor : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceshipActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnInteract();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	UUserWidget* ReferencedWidget;

};
