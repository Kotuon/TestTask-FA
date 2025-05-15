// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractMessage.generated.h"

/**
 *
 */
UCLASS()
class TESTTASKFA_API UInteractMessage : public UUserWidget {
    GENERATED_BODY()

public:
    UFUNCTION( BlueprintNativeEvent )
    void SetMessageText( const FString& newMessage );
    virtual void SetMessageText_Implementation( const FString& newMessage );
};
