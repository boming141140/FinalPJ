// Fill out your copyright notice in the Description page of Project Settings.


#include "playerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AplayerCharacter::AplayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Adjust the capsule component properties if necessary
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 110.0f);
	// Create a static mesh component
	UStaticMeshComponent* CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment(RootComponent); // Attach the mesh to the root component (CapsuleComponent)
	CharacterMesh->SetRelativeLocation(FVector(0, 0, 0));

	// Load a mesh. Note: Replace 'PathToYourMesh' with the actual path to your mesh.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (MeshAsset.Succeeded())
	{
		CharacterMesh->SetStaticMesh(MeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("mesh not found"));
	}

	// Instantiating your class Components

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	// Attaching your class Components to the default character's Skeletal Mesh Component.

	

	//Setting class variables of the Character movement component

	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	GetCharacterMovement()->bIgnoreBaseRotation = true;

	GetCharacterMovement()->JumpZVelocity = 500.f;

	// Create a Spring Arm component
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	// Adjust the Spring Arm properties
	SpringArm->TargetArmLength = 300.0f; // The camera follows at this distance behind the character 
	SpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Adjust the Camera component setup
	CameraComp->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach the Camera to the Spring Arm
	CameraComp->SetRelativeLocation(FVector(0, 0, 110));
}

void AplayerCharacter::MoveCylinderForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AplayerCharacter::MoveCylinderRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// Find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Called when the game starts or when spawned
void AplayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AplayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AplayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Bind the axis events to the movement functions
	PlayerInputComponent->BindAxis("forward", this, &AplayerCharacter::MoveCylinderForward);
	PlayerInputComponent->BindAxis("rightward", this, &AplayerCharacter::MoveCylinderRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AplayerCharacter::PitchInput);
	// Bind jump functions
	PlayerInputComponent->BindAction("jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("jump", IE_Released, this, &ACharacter::StopJumping);
}

void AplayerCharacter::PitchInput(float val)
{
	if (CameraComp)
	{
		FRotator NewRotation = CameraComp->GetRelativeRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch - val, -80.0f, 80.0f);  // Clamping to avoid full rotation
		CameraComp->SetRelativeRotation(NewRotation);
	}
}
