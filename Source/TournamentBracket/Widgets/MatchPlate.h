// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/TournamentsMenuWaiter.h"
#include "MatchPlate.generated.h"

/**
 * 
 */
UCLASS()
class TOURNAMENTBRACKET_API UMatchPlate : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, BlueprintNativeEvent, Category = "Match Data", meta = (DisplayName = "Get Match Data"))
		void GetMatchData(struct FMatchData & MatchData);
	UFUNCTION(BlueprintPure, BlueprintNativeEvent, Category = "Match Data", meta = (DisplayName = "Get Team Plates"))
		void GetTeamPlates(class UTeamPlate * & FirstTeam, class UTeamPlate * & SecondTeam);
	UFUNCTION(BlueprintPure, Category = "Match Data", meta = (DisplayName = "Get Match Date Form Unix Timestamp"))
		void GetMatchDateFormUnixTimestamp(int64 Timestamp, FDateTime & Date);

};
