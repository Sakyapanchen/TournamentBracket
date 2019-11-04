// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchPlate.h"
#include "Misc/DateTime.h"


void UMatchPlate::GetMatchData_Implementation(FMatchData & MatchData)
{

}

void UMatchPlate::GetTeamPlates_Implementation(UTeamPlate * & FirstTeam, UTeamPlate * & SecondTeam)
{
}

void UMatchPlate::GetMatchDateFormUnixTimestamp(int64 Timestamp, FDateTime & Date)
{
	Date = FDateTime::FromUnixTimestamp(Timestamp);
}
