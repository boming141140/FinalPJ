// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItem.generated.h"

UCLASS()
class FINALPJ_API UMyItem : public UActorComponent
{
    GENERATED_BODY()

public:
    // Constructor
    UMyItem();

    // Common properties shared by all items
    UPROPERTY(EditDefaultsOnly, Category = "Item Properties")
    FString Name;

    UPROPERTY(EditDefaultsOnly, Category = "Item Properties")
    FString Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Properties")
    int32 Quantity;

    // Common functionality
    virtual void Use();

};
