// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ASpaceshipActor::ASpaceshipActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Create the mesh component and attach it as the root component

    UStaticMeshComponent*  MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    // Load the mesh asset
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/EF_TwinsRoom/Meshes/FlyingSaucerToy_a.FlyingSaucerToy_a'"));  
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load the mesh. Check the path is correct."));
    }
    togglable = true;
}

// Called when the game starts or when spawned
void ASpaceshipActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceshipActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpaceshipActor::OnInteract()
{
    if (ReferencedWidget)
    {
        ReferencedWidget->AddToViewport();

        

        // Get the player controller to set the input mode to UI only
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (PlayerController)
        {
            FInputModeUIOnly InputModeData;
            InputModeData.SetWidgetToFocus(ReferencedWidget->TakeWidget());
            InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

            // Set the input mode and show the cursor
            PlayerController->SetInputMode(InputModeData);
            PlayerController->bShowMouseCursor = true;
        }
    }
    
}



