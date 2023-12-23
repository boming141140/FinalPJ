// Fill out your copyright notice in the Description page of Project Settings.


#include "mannequin.h"
#include "InteractButton.h"
#include "MyUserWidget.h"
#include "SpaceshipActor.h"
#include "MyInterface.h"
#include "GameFramework/PlayerController.h"

// Sets default values
Amannequin::Amannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void Amannequin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    RayCasting();
}


void Amannequin::RayCasting()
{
    // Get the player's viewport size
    int32 ViewportSizeX, ViewportSizeY;
    FVector WorldLocation;
    FVector WorldDirection;
    APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (PlayerController)
    {
        PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

        // Get the screen position in the middle of the screen
        FVector2D ScreenPosition(ViewportSizeX / 2.0f, ViewportSizeY / 2.0f);
        bool bIsDeprojected = PlayerController->DeprojectScreenPositionToWorld(
            ScreenPosition.X,
            ScreenPosition.Y,
            WorldLocation,
            WorldDirection
        );

        if (bIsDeprojected)
        {
            // Define the start and end locations
            FVector Start = WorldLocation;
            FVector End = (WorldDirection * 800.f) + Start;

            // Perform the raycast
            FHitResult HitResult;
            FCollisionQueryParams CollisionParams;
            CollisionParams.AddIgnoredActor(this); // Ignore the player

            bool bHit = GetWorld()->LineTraceSingleByChannel(
                HitResult,
                Start,
                End,
                ECC_Visibility, // Or another collision channel
                CollisionParams
            );

            // Check if we hit something
            if (bHit)
            {
                // Process the hit
                AActor* HitActor = HitResult.GetActor();
                if (HitActor)
                {
                    // The hit actor is interactable
                    // Cast it to the interface to call interface methods
                    IMyInterface* InteractableActor = Cast<IMyInterface>(HitActor);
                    if (InteractableActor) 
                    {
                        if (InteractableActor->togglable && MyWidget)
                        {
                            InteractableActors = InteractableActor;
                            MyWidget->ShowFKey();
                        }
                    }
                    else if(MyWidget)
                    {
                        InteractableActors = nullptr;
                        MyWidget->HideFKey();
                    }
                    FString HitObjectName = HitActor->GetName();

                    // Display the name of the hit object on the screen
                    if (GEngine)
                    {
                        int32 Key = -1; // Use a unique key for each message, -1 means no key (new message every time)
                        float TimeToDisplay = 5.0f; // Duration to display the message
                        FColor DisplayColor = FColor::Green; // Color of the text
                        FString Message = FString::Printf(TEXT("Hit object: %s"), *HitObjectName);

                        GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, DisplayColor, Message);
                    }
                }
                else if (MyWidget)
                {
                    InteractableActors = nullptr;
                    MyWidget->HideFKey();
                }
               
            }
            else if (MyWidget)
            {
                MyWidget->HideFKey();
            }
            /*
            FColor LineColor = bHit ? FColor::Red : FColor::Green;
            DrawDebugLine(
                GetWorld(),
                Start,
                End,
                LineColor,
                false,  // Persistent (remains for more than one frame)
                1.0f,   // Lifetime (1 second)
                0,      // Depth priority
                5.0f    // Thickness
            );
            */
        }
    }
    
}
void Amannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Bind the Interact action to a local method
    PlayerInputComponent->BindAction("interact", IE_Pressed, this, &Amannequin::AttemptInteract);
    

}

void Amannequin::AttemptInteract()
{
    // Attempt to cast and call OnInteract each time the button is pressed
    AInteractButton* MyInteractButton = Cast<AInteractButton>(InteractableActors);
    if (MyInteractButton)
    {
        MyInteractButton->OnInteract();
        return;
    }
    
    ASpaceshipActor* MySpaceshipActor = Cast<ASpaceshipActor>(InteractableActors);
    if (MySpaceshipActor)
    {
        MySpaceshipActor->OnInteract();
        return; // If you want to only interact with the first valid spaceship actor
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No valid spaceship actor found to interact with."));
    }


}