// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
};

USTRUCT(BlueprintType)
struct FMatchesData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Matches Data"))
		TMap<int32, FMatchData> MatchesData;
};

USTRUCT(BlueprintType)
struct FTournamentData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Teams"))
		TMap<FString, UTexture2DDynamic *> Teams;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Matches"))
		TMap<int32, FMatchesData> Matches;
};


UCLASS()
class TOURNAMENTBRACKET_API UTournamentsMenuWaiter : public UUserWidget
{
	GENERATED_BODY()

public:

public:

	UTournamentsMenuWaiter(const FObjectInitializer  &ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Tournaments", meta = (DisplayName = "Cache Tournament Data"))
		void CacheTournamentData(FString TournamentName, FTournamentData TournamentData);

	UFUNCTION(BlueprintCallable, Category = "Tournaments", meta = (DisplayName = "Find Tournament Data"))
		void FindTournamentData(FString TournamentName, FTournamentData & TournamentData, bool & bSuccess);

	UFUNCTION(BlueprintCallable, Category = "Tournaments", meta = (DisplayName = "Emplace Matche Data"))
		void EmplaceMatchesData(int32 Round, int32 Timestamp, FMatchData MatchData, TMap<int32, FMatchesData> InMatches, TMap<int32, FMatchesData> & OutMatches);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "Tournaments List Link"))
		FString TournamentsListLink = "index.json";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", Meta = (DisplayName = "Request Timeout", ClampMin = "0.1", UIMin = "0.1"))
		float RequestTimeout = 2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament", Meta = (DisplayName = "Teams Field"))
		FString TeamsField = "teams";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament", Meta = (DisplayName = "Matches Field"))
		FString MatchesField = "matches";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Team", Meta = (DisplayName = "Team Name Field"))
		FString TeamNameField = "name";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Team", Meta = (DisplayName = "Image Field"))
		FString ImageField = "image";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Match", Meta = (DisplayName = "Team 0 Field"))
		FString Team0Field = "team0";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Match", Meta = (DisplayName = "Team 1 Field"))
		FString Team1Field = "team1";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Match", Meta = (DisplayName = "Winner Team Field"))
		FString WinnerTeamField = "winner";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Match", Meta = (DisplayName = "Timestamp Field"))
		FString TimestampField = "timestamp";
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings|Tournament|Match", Meta = (DisplayName = "Round Field"))
		FString RoundField = "round";

private:

	TMap <FString, FTournamentData> CachedTournaments;
	
};
