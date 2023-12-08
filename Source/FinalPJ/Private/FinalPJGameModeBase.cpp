// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalPJGameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "playerCharacter.h" 
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"


AFinalPJGameModeBase::AFinalPJGameModeBase()
{
    // Set the default pawn class to your player character class
    DefaultPawnClass = AplayerCharacter::StaticClass();
}

void AFinalPJGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Assuming you have this method implemented to handle custom player spawning.
    //SpawnPlayerAtStart(GetWorld());
}

void AFinalPJGameModeBase::SpawnPlayerAtStart(UWorld *World)
{
    if (World)
    {
        // Find the PlayerStart
        APlayerStart* PlayerStart = nullptr;
        for (TActorIterator<APlayerStart> It(World); It; ++It)
        {
            PlayerStart = *It;
            break; // Assumes the first PlayerStart found is used. Modify as needed.
        }

        if (PlayerStart)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

            // Spawn the player character
            APawn* PlayerPawn = World->SpawnActor<APawn>(DefaultPawnClass, PlayerStart->GetActorLocation(), PlayerStart->GetActorRotation(), SpawnParams);

            if (PlayerPawn)
            {
                // Possess the pawn with the player controller
                APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
                if (PlayerController)
                {
                    PlayerController->Possess(PlayerPawn);
                }
            }
        }
    }
}
