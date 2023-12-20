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
