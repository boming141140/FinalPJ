// Fill out your copyright notice in the Description page of Project Settings.

#include "FinalProjectGameModeBase.h"
#include "mannequin.h"
#include "Kismet/GameplayStatics.h"



void AFinalProjectGameModeBase::BeginPlay()
{
	Super::BeginPlay();
   
}

void AFinalProjectGameModeBase::GetWidget(UMyUserWidget* MyWidget)
{
    MyWidgets = MyWidget;
}

void AFinalProjectGameModeBase::SetWidget()
{
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (PlayerController)
    {
        // Get the Pawn
        APawn* PlayerPawn = PlayerController->GetPawn();
        Amannequin* Mannequin = Cast<Amannequin>(PlayerPawn);
        if (Mannequin)
        {
            Mannequin->MyWidget = MyWidgets;
        }
    }
}
