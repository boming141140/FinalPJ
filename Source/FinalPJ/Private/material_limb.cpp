	// Fill out your copyright notice in the Description page of Project Settings.


#include "material_limb.h"

Umaterial_limb::Umaterial_limb()
{
}

// Sets default values
Umaterial_limb::Umaterial_limb(BodyParts BodyPartsName):BodyPartsName(BodyPartsName)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	type = MaterialType::wood;
	mass = Weight::light;
	bouncy = Bouncy::LittleBouncy;
	length = Length::MediumLength;
	fireResist = false;
	health = 2;
}


// Called every frame
void Umaterial_limb::Use()
{
	health = 2;
}

void Umaterial_limb::setBodyPart(BodyParts NewBodyPart)
{
	BodyPartsName = NewBodyPart;
}

void Umaterial_limb::setType(MaterialType NewType)
{
	type = NewType;
	switch (NewType)
	{
		case MaterialType::copper:
			mass = Weight::heavy;
			bouncy = Bouncy::LittleBouncy;
			length = Length::MediumLength;
			fireResist = true;
			break;
		case MaterialType::wood:
			mass = Weight::light;
			bouncy = Bouncy::LittleBouncy;
			length = Length::MediumLength;
			fireResist = false;
			break;
		case MaterialType::steel:
			mass = Weight::heavy;
			bouncy = Bouncy::LittleBouncy;
			length = Length::MediumLength;
			fireResist = true;
			break;
		case MaterialType::rock:
			mass = Weight::medium;
			bouncy = Bouncy::NotBouncy;
			length = Length::MediumLength;
			fireResist = true;
			break;
		case MaterialType::rubber:
			mass = Weight::light;
			bouncy = Bouncy::Bouncy;
			length = Length::MediumLength;
			fireResist = false;
			break;
	}
	health = 2;
}







