// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"

// Sets default values
UMyItem::UMyItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;
	// Set default values for properties
	Name = TEXT("Item");
	Description = TEXT("This is an item.");
	Quantity = 1;
}

void UMyItem::Use()
{
	// Implement common "use" behavior for items
	// For instance, decrement quantity or remove the item from inventory
}





