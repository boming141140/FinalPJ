// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINALPJ_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UpdateText")
    void UpdateText(const FText& NewText);

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* MyTextBlock;
};
