/*------------------------------------------------------
Student's Name:	Benjamin Rogers
Student's email address:	bjr342@uowmail.edu.au
Laboratory group (group code and time):	Friday 10:30-12:30
Purpose of this assignment: Establish basic familiarity with C++ classes
-------------------------------------------------------*/



#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "student.h"

using namespace std;

int main (int argc, char* argv[])
{
	int numRec;


	if (argc != 2)	//Checks command line parameters
	{
		cerr << "Filename not specified \n";
		return -1;
	}
	
	//Open file
	ifstream fin;
	fin.open(argv[1]);

	if (fin.good())	//Check if file opened properly
	{
		fin >> numRec;		//get number of records
		fin.get();	//New line


		studentClass* studentArray = new studentClass[numRec];	//creates array of student objects

		int i = 0;
		
		while(!fin.eof())	//While end of file has not been reached
		{

			char* tempName = {'\0'};
			char* buff = {'\0'};
			int tempMarks[3] = {0};
			int tempSub = 0;

			fin.getline(tempName, 256, ' ');	//read first name until whitespace	
			fin.getline(buff, 256, ' ');	//read second name until whitespace
			
			strcat(tempName, buff);	//concatenate names together

			fin >> tempMarks[0];		//get first mark
			char peekNext = fin.peek();
			
			tempSub++;
			
			if(peekNext == ' ')	//if next character is whitespace then there are more marks to be read
			{
				fin >> tempMarks[1];
				peekNext = fin.peek();
				tempSub++;
				
				if (peekNext == ' ')
				{
					fin >> tempMarks[2];
					peekNext == fin.peek();
					tempSub++;
					
					if (peekNext == ' ')
					{
						fin >> tempMarks[3];
						tempSub++;
					}
				}
			}

			fin.getline(buff, 256, '\n');	//Get newline character
			studentArray[i].setDetails(tempName, tempMarks[0], tempMarks[1], tempMarks[2], tempMarks[3], tempSub);
			i++; //increment array index
		}

		int totalSub1, totalSub2, totalSub3, totalSub4;
		int avgSub2, avgSub3, avgSub4;
		for (int j = 0; j <numRec; j++)	//Calculate total of each subject
		{
			totalSub1 += studentArray[i].calcTotal1();	//All entries will have a mark[0] value
			
			if (studentArray[i].calcTotal2() == 0)	//counts how many students did not take the class
			{
				avgSub2++;
			}
			totalSub2 += studentArray[i].calcTotal2();
			
			if (studentArray[i].calcTotal3() == 0)
			{
				avgSub3++;
			}
			totalSub3 += studentArray[i].calcTotal3();
			
			if (studentArray[i].calcTotal4() == 0)
			{
				avgSub4++;
			}
			totalSub4 += studentArray[i].calcTotal4();
		}
		
		//Calculate average of each subject
		int avgSub1 = totalSub1 / numRec;
		avgSub2 = totalSub2 / (numRec - avgSub2);
		avgSub3 = totalSub3 / (numRec - avgSub3);
		avgSub4 = totalSub4 / (numRec - avgSub4);
		
		//Ouput results
		cout << "	Name		Mark1	Mark2	Mark3	Mark4	Total	Average" << endl;
		cout << "======================================================" << endl;
		for (int j = 0; j <numRec; j++)
		{
			studentArray[i].printDetails();
		}
		cout << "======================================================" << endl;
		cout << "\t \t Total \t" << totalSub1 << "\t" << totalSub2 << "\t" << totalSub3 << "\t" << totalSub4 << endl;
		cout << "\t \t Average \t" << avgSub1 << "\t" << avgSub2 << "\t" << avgSub3 << "\t" << avgSub4 << endl;
		cout << "======================================================" << endl;
		
		delete [] studentArray;
	}
	else
	{
		cerr << "File could not load";
		return -1;
	}
	

	

}
