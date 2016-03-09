/*
	Filename:		classes.cpp		
	Student Name:	Benjamin Rogers
	Student Number:	4503600
	Login:		bjr342
	File Description:	CSCI204 Classes implementation
*/

#include "classes.h"

Championship::Championship(string league, int numTeams)	//Constructor
{
	leagueType = league;
	teams = numTeams;
	aTeam = new Team[teams];	//Create array of teams for championship
	for(int i=0;i<numTeams; i++)
	{
		aTeam[i].assignName(i);	//Works correctly
	}
	NumGames = (numTeams*(numTeams--));	//Determine number of games to be played n*(n-1)
	aGame = new Game[NumGames];	//Create array of games
}

Championship::~Championship()	//Destructor
{
	delete aTeam;
	delete aGame;
}

void Championship::printResults()
{
	cout << "*** " << this->leagueType << " " << "League Campionship ***" << endl;
	cout << "- Participant List -" << endl;
	for (int i=0; i<teams; i++)
	{
		cout << "Team" << i << " " << endl;
	}
	cout << endl;
	cout << "- Games played -" << endl;
	for(int i=0; i<NumGames; i++)
	{
		//aGame[i]
	}
}

void Championship::assignGames()
{
	//Check if number of teams is even
	if (teams%2 ==0)
	{
		//Will assign correct games for at least 3/4 of values, needs more work
		int i = 0;
		int j = teams;
		int game=0;
		while (i != (teams/2) )	//While i is not at halfway
		{
			while (i != (j--))	//While j is not a single value away from i
			{
				aGame[game].runGame(aTeam[i], aTeam[j]);
				aGame[game++].runGame(aTeam[j], aTeam[i]);
				j--;
				game + 2;	//Increment gamenumber by 2
			}
			i++;
			j = teams;
			while (i != j)	//While i does not equal j
			{
				aGame[game].runGame(aTeam[i], aTeam[j]);
				aGame[game++].runGame(aTeam[j], aTeam[i]);
				j--;
				game + 2;
			}	//i will equal j at this point
		}
	}
	else
	{
		//Odd number of teams, will need a dummy team for a bye
		int i =0;
		int j= teams;
		int game = 0;
		while (i != (j--))
		{
			aGame[game].runGame(aTeam[i], aTeam[j]);
			aGame[game++].runGame(aTeam[j], aTeam[i]);
			j--;
			game + 2;			
		}
		i++;
		j = teams;
		while (i != j)
		{
			aGame[game].runGame(aTeam[i], aTeam[j]);
			aGame[game++].runGame(aTeam[j], aTeam[i]);
			j--;
			game + 2;
		}
	}
}

void Championship::rankings()
{
	//Using overloaded operators, determines the ranking of each team
	for (int i=0; i <teams; i++)
	{
		for (int j =i+1; j <(teams--); j++)
		{
			if (!(aTeam[i] < aTeam[j]))
			{
				//Total points are equal
				if (!(aTeam[i] > aTeam[j]))
				{
					//GoalDifference is the same
					if (!(aTeam[i] == aTeam[j]))
					{	
					
					}
				}
			}
		}
	}

}

Team::Team()
{

}


void Team::assignName(int teamNumber)
{
	//Convert teamNumber to string and then concatenate on the end of Team for teamname
	string name = "Team";
	string Result;
	stringstream convert;
	convert << teamNumber;
	Result = convert.str();
	
	//itoa (teamNumber,buffer,10);
	name = name + Result;
	this->teamName = name;
}

/*
void Team::showDetails()	//Testing purposes
{
	cout << "This is team name: " << this->teamName;
}

*/

void Team::UpdatePoints(int scored, int against)
{
	this->goalsScored += scored;
	this->goalsAgainst += against;
	if (scored > against)	//Win is 3 points
	{
		this->totalPoints += 3;
	}
	if (scored == against)	//Draw is 1 point
	{
		this->totalPoints += 1;
	}
	//No points recorded for a loss
	
	this->difference += (scored - against);	//Calculate goal difference for team
}

bool Team::operator<(const Team& arg) const
{
	//Usage:  TeamX < TeamY
	//Returns true if team y's totalpoints is larger than team x's
	if( totalPoints < arg.totalPoints)
	{
		return true;
	}
	if (totalPoints == arg.totalPoints)	//Returns false if values are the same
	{
		return false;
	}
}

bool Team::operator>(const Team& arg) const
{
	//Usage:  TeamX > TeamY
	//Returns true if team y's goalDifference is larger than team x's
	if ( difference < arg.difference)
	{
		return true;
	}
	if ( difference == arg.difference)	//Returns false if the same
	{
		return false;
	}
}

bool Team::operator==(const Team& arg) const
{
	//Usage:  TeamX == TeamY
	//Returns true if team y's 
	if ( goalsScored < arg.goalsScored)
	{
		return true;
	}
	if ( goalsScored == arg.goalsScored)	//Returns false if the same
	{
		return false;
	}
}

bool Team::operator!=(const Team& arg) const
{
	//Occupy the same spot
	return true;
}

Game::Game()
{

}
Game::~Game()
{
	delete homeTeam;
	delete awayTeam;
}


void Game::runGame(Team Home, Team Away) //Simulates a game
{
	//Initialize random seed
	srand(time(NULL));
	
	//Generate random values between 1 and 10
	homeGoals = rand() % 10 + 1;
	awayGoals = rand() % 10 + 1;
	
	//Updates points for each team
	Home.UpdatePoints(homeGoals, awayGoals);
	Away.UpdatePoints(awayGoals, homeGoals);
	
	
}

/*
friend void assignTeams(Team Home, Team* Away)
{
	homeTeam = new Team(Home.teamName);
	//homeTeam.
	this->awayTeam = Away;
}

*/

void Game::showresults()
{
	//Prints out home and away goals
	cout << this->homeGoals << " " << this->awayGoals << endl;
}