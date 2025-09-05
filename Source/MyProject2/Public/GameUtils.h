#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameUtils.generated.h"


UCLASS()
class MYPROJECT2_API UGameUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public: 
    UFUNCTION(BlueprintCallable, Category = "Utilities")
    static bool GetScreenBoundsFromWorldBounds(
        APlayerController const* Player,
		const FVector& Origin, const FVector& BoxExtent,
        FBox2D& screenBounds
    );

    UFUNCTION(BlueprintCallable, Category = "Utilities")
    static bool IsPlayerLookingAt(
		const FBox2D& screenBounds, APlayerController const* Player
    );
};
