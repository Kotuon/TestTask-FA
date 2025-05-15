// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

class USphereComponent;
class UInteractMessage;

UCLASS()
class TESTTASKFA_API AInteractable : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInteractable();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick( float DeltaTime ) override;

private: // Functions
    UFUNCTION()
    void BeginOverlap( UPrimitiveComponent* OverlappedComponent,
                       AActor* OtherActor, UPrimitiveComponent* OtherComp,
                       int32 OtherBodyIndex, bool bFromSweep,
                       const FHitResult& SweepResult );

    UFUNCTION()
    void EndOverlap( UPrimitiveComponent* OverlappedComponent,
                     AActor* OtherActor, UPrimitiveComponent* OtherComp,
                     int32 OtherBodyIndex );

protected:
    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = ItemValues,
               meta = ( AllowPrivateAccess = "true" ) )
    USphereComponent* proximityHitbox;

    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = ItemValues,
               meta = ( AllowPrivateAccess = "true" ) )
    FString interactMessage;

    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = ItemValues,
               meta = ( AllowPrivateAccess = "true" ) )
    TSubclassOf< UInteractMessage > wMessageClass;

    bool playerInRadius = false;
};
