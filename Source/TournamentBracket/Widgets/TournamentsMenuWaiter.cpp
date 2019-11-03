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
