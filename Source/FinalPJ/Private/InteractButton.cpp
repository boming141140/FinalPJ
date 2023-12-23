// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractButton.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AInteractButton::AInteractButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Create the mesh component and attach it as the root component
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    // Load the mesh asset
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube1.Shape_Cube1'"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load the mesh. Check the path is correct."));
    }

    // In your AInteractButton.cpp
    // Inside the constructor:
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialFinder(TEXT("Material'/Game/StarterContent/Materials/green_button_material1.green_button_material1'"));
    if (MaterialFinder.Succeeded())
    {
        ButtonMaterial = MaterialFinder.Object;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not find material!"));
    }
	togglable = true;
}

// Called when the game starts or when spawned
void AInteractButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractButton::OnInteract()
{
    switch (marker)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if (ButtonMaterial != nullptr && ReferencedActor)
            {
                // The function name must match the exact name of the custom event in your Blueprint
                FName FunctionName = FName(TEXT("opendoor"));
                UFunction* Function = ReferencedActor->FindFunction(FunctionName);

                if (Function)
                {
                    // Call the function
                    ReferencedActor->ProcessEvent(Function, nullptr);
                }
            }
           
            MeshComponent->SetMaterial(0, ButtonMaterial);
            togglable = false;
            break;
            
    }
}

