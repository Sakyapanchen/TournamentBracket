// Fill out your copyright notice in the Description page of Project Settings.


#include "TournamentBracketGrid.h"
#include "Widgets/TeamPlate.h"

void UTournamentBracketGrid::AddWidgets(int32 Round, FMatchWidgetCouple WidgetCouple)
{
	if (TournamentMathces.Contains(Round))
	{
		FRoundMateches matchesData = *TournamentMathces.Find(Round);
		matchesData.MatchWidgetCouples.Add(WidgetCouple);
		TournamentMathces.Emplace(Round, matchesData);
		TournamentMathces.KeySort
		(
			[](int32 A, int32 B)
			{return A > B; }
		);
		return;
	}
	FRoundMateches matchesData;
	matchesData.MatchWidgetCouples.Add(WidgetCouple);
	TournamentMathces.Add(Round, matchesData);
	TournamentMathces.KeySort
	(
		[](int32 A, int32 B)
		{return A > B; }
	);
	return;
}

void UTournamentBracketGrid::GetTournamentWidgets(int32 Round, bool & bSuccess, FRoundMateches & RoundWidgets)
{
	bSuccess = false;
	if (!TournamentMathces.Contains(Round))
		return;
	bSuccess = true;
	RoundWidgets = *TournamentMathces.Find(Round);
}

void UTournamentBracketGrid::ClearBracketWidgets()
{
	TournamentMathces.Empty();
}

void UTournamentBracketGrid::CalculateWidgetPlatePosition(int32 MatchRound, int32 MaxRound, FMatchWidgetCouple WidgetCouple, FVector2D & Position)
{
	if (!WidgetCouple.MatchPlate || !WidgetCouple.MatchPlateAsSlot)
		return;
	Position.X = MatchRound * XStep + StartXPos;
	if (MatchRound == MaxRound)
	{
		Position.Y = (FMath::Pow(2, MaxRound) * YStep)/2 + StartYPos;
		return;
	}
	bool success;
	FRoundMateches roundWidgets;
	GetTournamentWidgets(MatchRound + 1, success, roundWidgets);
	if (!success)
		return;
	for (FMatchWidgetCouple nextRoundWidgetCouple : roundWidgets.MatchWidgetCouples)
	{
		if (nextRoundWidgetCouple.MatchPlate && nextRoundWidgetCouple.MatchPlateAsSlot)
		{
			FMatchData nextRoundMatchData;
			nextRoundWidgetCouple.MatchPlate->GetMatchData(nextRoundMatchData);
			FMatchData currentRoundMatchData;
			WidgetCouple.MatchPlate->GetMatchData(currentRoundMatchData);
			if (nextRoundMatchData.FirstTeamName == currentRoundMatchData.FirstTeamName || nextRoundMatchData.FirstTeamName == currentRoundMatchData.SecondTeamName)
			{
				Position.Y = nextRoundWidgetCouple.MatchPlateAsSlot->GetPosition().Y;
				Position.Y = Position.Y - FMath::Pow(2, MatchRound) * YStep / 2;
				break;
			}		
			if (nextRoundMatchData.SecondTeamName == currentRoundMatchData.FirstTeamName || nextRoundMatchData.SecondTeamName == currentRoundMatchData.SecondTeamName)
			{
				Position.Y = nextRoundWidgetCouple.MatchPlateAsSlot->GetPosition().Y;
				Position.Y = Position.Y + FMath::Pow(2, MatchRound) * YStep / 2;
				break;
			}
		}

	}
	
}

void UTournamentBracketGrid::HoveredRequest(FString TeamName, bool bIsHovered)
{
	TArray<int32> Rounds;
	TournamentMathces.GenerateKeyArray(Rounds);
	for (int32 currentRound : Rounds)
	{
		FRoundMateches Matches = *TournamentMathces.Find(currentRound);
		for (FMatchWidgetCouple currentCouple : Matches.MatchWidgetCouples)
		{
			FMatchData MatchData;
			UTeamPlate * FirstTeam;
			UTeamPlate * SecondTeam;
			currentCouple.MatchPlate->GetMatchData(MatchData);
			currentCouple.MatchPlate->GetTeamPlates(FirstTeam, SecondTeam);
			if (MatchData.FirstTeamName == TeamName)
			{
				FirstTeam->SetHovered(bIsHovered);
				break;
			}
			if (MatchData.SecondTeamName == TeamName)
			{
				SecondTeam->SetHovered(bIsHovered);
				break;
			}
		}
	}
}
