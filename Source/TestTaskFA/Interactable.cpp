// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable.h"
#include "Components/SphereComponent.h"
#include "InteractMessage.h"

// Sets default values
AInteractable::AInteractable() {
    // Set this actor to call Tick() every frame.  You can turn this off to
    // improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    proximityHitbox =
        CreateDefaultSubobject< USphereComponent >( TEXT( "ProximityHitbox" ) );
    proximityHitbox->OnComponentBeginOverlap.AddDynamic(
        this, &AInteractable::BeginOverlap );

    wMessage = CreateDefaultSubobject< UInteractMessage >(
        TEXT( "InteractMessageWidget" ) );
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void AInteractable::Tick( float DeltaTime ) { Super::Tick( DeltaTime ); }

void AInteractable::BeginOverlap( UPrimitiveComponent* OverlappedComponent,
                                  AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp,
                                  int32 OtherBodyIndex, bool bFromSweep,
                                  const FHitResult& SweepResult ) {
    playerInRadius = true;
    wMessage->SetMessageText( interactMessage );
}

void AInteractable::EndOverlap( UPrimitiveComponent* OverlappedComponent,
                                AActor* OtherActor,
                                UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex ) {
    playerInRadius = false;
}
