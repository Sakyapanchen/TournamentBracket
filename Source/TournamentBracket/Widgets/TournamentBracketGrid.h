// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Widgets/MatchPlate.h"
#include "TournamentBracketGrid.generated.h"

USTRUCT(BlueprintType)
struct FMatchWidgetCouple
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Match Plate"))
		UMatchPlate * MatchPlate = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Team Emblem"))
		UCanvasPanelSlot * MatchPlateAsSlot = nullptr;
};

USTRUCT(BlueprintType)
struct FRoundMateches
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Match Widget Couples"))
		TArray<FMatchWidgetCouple> MatchWidgetCouples;
};

UCLASS()
class TOURNAMENTBRACKET_API UTournamentBracketGrid : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "Start X Position"))
		float StartXPos = 50;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "Start Y Position"))
		float StartYPos = 50;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "X Step"))
		float XStep = 350;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "Y Step"))
		float YStep = 100;

protected:

	UFUNCTION(BlueprintCallable, Category = "Tournament Bracket", meta = (DisplayName = "Add Widgets"))
		void AddWidgets(int32 Round, FMatchWidgetCouple WidgetCouple);
	UFUNCTION(BlueprintPure, Category = "Tournament Bracket", meta = (DisplayName = "Get Tournament Widgets"))
		void GetTournamentWidgets(int32 Round, bool & bSuccess, FRoundMateches & RoundWidgets);
	UFUNCTION(BlueprintCallable, Category = "Tournament Bracket", meta = (DisplayName = "Clear Bracket Widgets"))
		void ClearBracketWidgets();
	UFUNCTION(BlueprintCallable, Category = "Tournament Bracket", meta = (DisplayName = "Calculate Widget Plate Position"))
		void CalculateWidgetPlatePosition(int32 MatchRound, int32 MaxRound, FMatchWidgetCouple WidgetCouple, FVector2D & Position);
	UFUNCTION(BlueprintCallable, Category = "Tournament Bracket", meta = (DisplayName = "Hovered Request"))
		void HoveredRequest(FString TeamName, bool bIsHovered);

private:

	TMap <int32, FRoundMateches> TournamentMathces;
	
};
