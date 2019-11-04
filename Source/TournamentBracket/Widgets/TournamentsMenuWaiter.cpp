// Fill out your copyright notice in the Description page of Project Settings.


#include "TournamentsMenuWaiter.h"

UTournamentsMenuWaiter::UTournamentsMenuWaiter(const FObjectInitializer  &ObjectInitializer) : Super(ObjectInitializer)
{

}

void UTournamentsMenuWaiter::CacheTournamentData(FString TournamentName, FTournamentData TournamentData)
{
	if (CachedTournaments.Contains(TournamentName))
	{
		CachedTournaments.Emplace(TournamentName, TournamentData);
		return;
	}
	CachedTournaments.Add(TournamentName, TournamentData);
}

void UTournamentsMenuWaiter::FindTournamentData(FString TournamentName, FTournamentData & TournamentData, bool & bSuccess)
{
	bSuccess = false;
	if (!CachedTournaments.Contains(TournamentName))
		return;
	TournamentData = *CachedTournaments.Find(TournamentName);
}

void UTournamentsMenuWaiter::EmplaceMatchesData(int32 Round, int32 Timestamp, FMatchData MatchData, TMap<int32, FMatchesData> InMatches, TMap<int32, FMatchesData>& OutMatches)
{
	if (InMatches.Contains(Round))
	{
		FMatchesData matchesData = *InMatches.Find(Round);
		matchesData.MatchesData.Add(Timestamp, MatchData);
		matchesData.MatchesData.KeySort
		(
			[](int32 A, int32 B)
			{return A < B; }
		);
		InMatches.Emplace(Round, matchesData);
		OutMatches = InMatches;
		OutMatches.KeySort
		(
			[](int32 A, int32 B)
			{return A > B;}
		);
		return;
	}
	FMatchesData matchesData;
	matchesData.MatchesData.Add(Timestamp, MatchData);
	matchesData.MatchesData.KeySort
	(
		[](int32 A, int32 B)
		{return A < B; }
	);
	InMatches.Add(Round, matchesData);
	OutMatches = InMatches;
	OutMatches.KeySort
	(
		[](int32 A, int32 B)
		{return A > B; }
	);
}


