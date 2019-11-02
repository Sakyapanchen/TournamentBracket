// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "Engine/Texture2DDynamic.h"
#include "TournamentsMenuWaiter.generated.h"

USTRUCT(BlueprintType)
struct FTeamData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Team Name"))
		FString TeamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Team Emblem"))
		UTexture2DDynamic * TeamEmblem = nullptr;
};

USTRUCT(BlueprintType)
struct FMatchData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "First Team Name"))
		FString FirstTeamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Second Team Name"))
		FString SecondTeamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Winner"))
		uint8 Winner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Timestamp"))
		FString Timestamp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Round"))
		uint8 Round;
};

USTRUCT(BlueprintType)
struct FTournamentData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Teams"))
		TArray<FTeamData> Teams;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Matches"))
		TArray<FMatchData> Matches;
};


UCLASS()
class TOURNAMENTBRACKET_API UTournamentsMenuWaiter : public UWidgetBlueprint
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, Category = "Tournaments", meta = (DisplayName = "Cache Tournament Data"))
		void CacheTournamentData(FString TournamentName, FTournamentData TournamentData);

	UFUNCTION(BlueprintCallable, Category = "Tournaments", meta = (DisplayName = "Find Tournament Data"))
		void FindTournamentData(FString TournamentName, FTournamentData & TournamentData, bool & bSuccess);

private:

	TMap <FString, FTournamentData> CachedTournaments;
	
};
