// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FinalPJGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FINALPJ_API AFinalPJGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:


AFinalPJGameModeBase();

void BeginPlay();

void SpawnPlayerAtStart(UWorld* World);

};
