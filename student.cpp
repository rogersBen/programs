/*------------------------------------------------------
Student's Name:	Benjamin Rogers
Student's email address:	bjr342@uowmail.edu.au
Laboratory group (group code and time):	Friday 10:30-12:30
Purpose of this assignment: Establish basic familiarity with C++ classes
-------------------------------------------------------*/



#include <iostream>
#include "student.h"
using namespace std;


void studentClass::setDetails(char* StuName, int mark1, int mark2, int mark3, int mark4, int numSubjects)
{
	name = StuName;
	marks[0] = mark1;
	marks[1] = mark2;
	marks[2] = mark3;
	marks[3] = mark4;
	numSub = numSubjects;
	total = mark1 + mark2 + mark3 + mark4;
	average = total / numSubjects;
}

studentClass::studentClass()
{

}


studentClass::~studentClass()
{

}

void studentClass::printDetails()
{
	cout << "\t" << name << "\t \t" << marks[0] << "\t" << marks[1] << "\t" << marks[2] << "\t" << marks[3] << 
		"\t" << total << "\t" << average << endl;
}

int studentClass::calcTotal1()
{
	return marks[0];
}

int studentClass::calcTotal2()
{
	if (numSub > 1)
	{
		return marks[1];
	}
	else
	{
		return 0;
	}
}

int studentClass::calcTotal3()
{
	if (numSub > 2)
	{
		return marks[2];
	}
	else
	{
		return 0;
	}
}

int studentClass::calcTotal4()
{
	if (numSub > 3)
	{
		return marks[3];
	}
	else
	{
		return 0;
	}
}