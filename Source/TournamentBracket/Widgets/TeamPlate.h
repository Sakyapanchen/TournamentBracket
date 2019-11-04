// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TeamPlate.generated.h"

/**
 * 
 */
UCLASS()
class TOURNAMENTBRACKET_API UTeamPlate : public UUserWidget
{
	GENERATED_BODY()

public:

		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Team Plate", meta = (DisplayName = "Set Hovered"))
			void SetHovered(bool bIsHovered);
	
};
