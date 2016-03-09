/*
	Filename:		a2main.cpp		
	Student Name:	Benjamin Rogers
	Student Number:	4503600
	Login:		bjr342
	File Description:	CSCI204 Assignment 2
*/

#include "classes.h"
#include <stdlib.h>
#include <cstring>

string hockey = "hockey";
string soccer = "soccer";
string handball = "handball";

int main(int argc, char *argv[])
{
	
	
	//Checks number of arguments and number of teams
	if ((argc == 3) || ((atoi(argv[2])) > 1))	
	{
		int numTeams =atoi(argv[2]);
		//If League type is either hockey, soccer or handball
		if ((strcmp(argv[1],"hockey")==0)  || (strcmp(argv[1],"soccer")==0) || (strcmp(argv[1],"handball")==0))
		{
			Championship myChampionship(argv[1], numTeams);		//create championship
			myChampionship.assignGames();	//Assigns teams to games
			myChampionship.rankings();	//Calculates rankings of teams
			myChampionship.printResults();	//Prints results	
		}
		else
		{
			cerr << "Error invalid command line parameters \n";
			return 1;
		}
	}
	else 
	{
		cerr << "Error invalid command line parameters \n";
		return 1;
	}
	
	return 0;
}

