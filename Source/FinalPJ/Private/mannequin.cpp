// Fill out your copyright notice in the Description page of Project Settings.


#include "mannequin.h"

// Sets default values
Amannequin::Amannequin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LeftArm = CreateDefaultSubobject<Umaterial_limb>(TEXT("LeftHand"));
	LeftArm->setBodyPart(BodyParts::LeftArm);
	RightArm = CreateDefaultSubobject<Umaterial_limb>(TEXT("RightHand"));
	RightArm->setBodyPart(BodyParts::RightArm);
	LeftLeg = CreateDefaultSubobject<Umaterial_limb>(TEXT("LeftLeg"));
	LeftLeg->setBodyPart(BodyParts::LeftLeg);
	RightLeg = CreateDefaultSubobject<Umaterial_limb>(TEXT("RightLeg"));
	RightLeg->setBodyPart(BodyParts::RightLeg);
}

Amannequin::Amannequin(Umaterial_limb* LeftHand, Umaterial_limb* RightHand, Umaterial_limb* LeftLeg, Umaterial_limb* RightLeg)
	: LeftArm(LeftHand), RightArm(RightHand), LeftLeg(LeftLeg), RightLeg(RightLeg)
{
	// Constructor body (if any additional initialization is needed)
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

}

void Amannequin::StatsCheck()
{

}

void Amannequin::equip(Umaterial_limb* limbs)
{
	switch (limbs->GetBodyPart())
	{
	case BodyParts::LeftArm:
		if (LeftArm->GetBodyPart() == BodyParts::Nothing)
		{

		}
		break;
	case BodyParts::RightArm:
		break;
	case BodyParts::LeftLeg:
		break;
	case BodyParts::RightLeg:
		break;
	default:
		break;
	}
}

void Amannequin::drop(Umaterial_limb* limbs)
{
}

