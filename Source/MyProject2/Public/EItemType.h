#pragma once

#include "CoreMinimal.h"
#include "EItemType.generated.h"

/**
 * Custom enum to demonstrate how to expose enums to Blueprints.
 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
    Obtainable UMETA(DisplayName = "Obtainable"),
    Interactible UMETA(DisplayName = "Interactible"),
    Describtion UMETA(DisplayName = "Describtion")
};