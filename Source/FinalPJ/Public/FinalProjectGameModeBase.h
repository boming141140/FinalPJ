// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyUserWidget.h"
#include "FinalProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FINALPJ_API AFinalProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	public:
		void BeginPlay();
		UMyUserWidget* MyWidgets;
		UFUNCTION(BlueprintCallable,  Category = "UI")
		void GetWidget(UMyUserWidget* MyWidget);
		UFUNCTION(BlueprintCallable,  Category = "UI")
		void SetWidget();
};
