// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "TestTaskFACharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN( LogTemplateCharacter, Log, All );

UENUM()
enum class E_InputStatus : uint8 {
    IS_Game UMETA( DisplayName = "InputGame" ),
    IS_Menu UMETA( DisplayName = "InputMenu" )
};

UCLASS( config = Game )
class ATestTaskFACharacter : public ACharacter {
    GENERATED_BODY()

    /** Pawn mesh: 1st person view (arms; seen only by self) */
    UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Mesh,
               meta = ( AllowPrivateAccess = "true" ) )
    USkeletalMeshComponent* Mesh1P;

    /** First person camera */
    UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera,
               meta = ( AllowPrivateAccess = "true" ) )
    UCameraComponent* FirstPersonCameraComponent;

    /** Jump Input Action */
    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input,
               meta = ( AllowPrivateAccess = "true" ) )
    UInputAction* JumpAction;

    /** Move Input Action */
    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input,
               meta = ( AllowPrivateAccess = "true" ) )
    UInputAction* MoveAction;

public:
    ATestTaskFACharacter();

    UFUNCTION( BlueprintCallable )
    void SetInputStatus( E_InputStatus newInputStatus );

protected:
    virtual void BeginPlay();

public:
    /** Look Input Action */
    UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input,
               meta = ( AllowPrivateAccess = "true" ) )
    class UInputAction* LookAction;

protected:
    /** Called for movement input */
    void Move( const FInputActionValue& Value );

    /** Called for looking input */
    void Look( const FInputActionValue& Value );

protected:
    // APawn interface
    virtual void
    SetupPlayerInputComponent( UInputComponent* InputComponent ) override;
    // End of APawn interface

public:
    /** Returns Mesh1P subobject **/
    USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
    /** Returns FirstPersonCameraComponent subobject **/
    UCameraComponent* GetFirstPersonCameraComponent() const {
        return FirstPersonCameraComponent;
    }

private:
    E_InputStatus inputStatus = E_InputStatus::IS_Game;
};
