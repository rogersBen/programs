/*
	Filename:		classes.h		
	Student Name:	Benjamin Rogers
	Student Number:	4503600
	Login:		bjr342
	File Description:	CSCI20 Header file for assignment 2
*/

#ifndef CLASSES_H
#define CLASSES_H

#include <sstream>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Team;
class Game;


class Championship
{
	private:
		string leagueType;
		Team *aTeam;
		Game *aGame;
		int teams;
		int NumGames;
	public:
		Championship(string, int);	//Constructor
		~Championship();		//Destructor
		void printResults();
		void assignGames();
		void rankings();
		
};

class Team
{
	private:
		string teamName;
		int totalPoints;
		int goalsScored;
		int goalsAgainst;
		int difference;
	public:
		Team();
		void UpdatePoints(int, int);
		void assignName(int);
		void showDetails();	//
		bool operator<(const Team& arg) const;	//Overloaded < operator
		bool operator>(const Team& arg) const;	//Overloaded > operator
		bool operator==(const Team& arg) const;	//Overloaded == operator
		bool operator!=(const Team& arg) const;	//Overloaded != operator
};

class Game
{
	private:
		Team *homeTeam;
		Team *awayTeam;
		int homeGoals;
		int awayGoals;
	public:
		Game();
		~Game();
		void runGame(Team, Team);
		friend void assignTeams(Team, Team*);
		void showresults();

};




#endif