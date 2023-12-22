// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/TextBlock.h"


void UMyUserWidget::UpdateText(const FText& NewText)
{
    if (MyTextBlock)
    {
        MyTextBlock->SetText(NewText);
    }
}

void UMyUserWidget::ShowFKey()
{
    if (InteractButton)
    {
        // Set the visibility of the button to Visible
        InteractButton->SetVisibility(ESlateVisibility::Visible);
    }
}

void UMyUserWidget::HideFKey()
{
    if (InteractButton)
    {
        // Set the visibility of the button to Hidden or Collapsed
        InteractButton->SetVisibility(ESlateVisibility::Collapsed); // or ESlateVisibility::Hidden
    }
}

