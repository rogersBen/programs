/*
	Filename:		student.h		
	Student Name:	Benjamin Rogers
	Student Number:	4503600
	Login:		bjr342
	File Description:	Header file for assignment 1
*/



//Class for student 
class studentClass
{
	private:
		char* name;
		int marks[3];
		int numSub;
		int total;
		int average;
	public:
		studentClass();	//default constructor
		void setDetails(char*, int=0, int=0, int=0, int=0, int=0);
		~studentClass();
		int calcTotal1();
		int calcTotal2();
		int calcTotal3();
		int calcTotal4();
		void printDetails();
};













