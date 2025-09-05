// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUtils.h"
#include <Camera/CameraComponent.h>

#include <Kismet/GameplayStatics.h>

bool UGameUtils::GetScreenBoundsFromWorldBounds(
    APlayerController const* Player, 
	const FVector& Origin, const FVector& BoxExtent,
    FBox2D& screenBounds) 
{
	screenBounds.Min = FVector2D(FLT_MAX, FLT_MAX);
	screenBounds.Max = FVector2D(-FLT_MAX, -FLT_MAX);

	const FVector Min = Origin - BoxExtent;
	const FVector Max = Origin + BoxExtent;

	std::array<FVector, 8> worldPoints{
		FVector(Min.X, Min.Y, Min.Z),
			FVector(Min.X, Min.Y, Max.Z),
				FVector(Min.X, Max.Y, Min.Z),
					FVector(Min.X, Max.Y, Max.Z),
						FVector(Max.X, Min.Y, Min.Z),
							FVector(Max.X, Min.Y, Max.Z),
								FVector(Max.X, Max.Y, Min.Z),
									FVector(Max.X, Max.Y, Max.Z) };
	for (const FVector& worldPoint : worldPoints) {
		FVector2D screenPoint;
		UGameplayStatics::ProjectWorldToScreen(Player, worldPoint, screenPoint);
		screenBounds.Min = FVector2D::Min(screenBounds.Min, screenPoint);
		screenBounds.Max = FVector2D::Max(screenBounds.Max, screenPoint);
	}

	return true;
}

bool UGameUtils::IsPlayerLookingAt(
	const FBox2D& screenBounds, APlayerController const* Player
) { 
	int32 ViewportX, ViewportY;
	Player->GetViewportSize(ViewportX, ViewportY);

	FVector2D screenCenter = FVector2D(ViewportX, ViewportY) * 0.5f;
	return screenBounds.IsInside(screenCenter);
}