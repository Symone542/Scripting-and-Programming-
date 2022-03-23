#pragma once
#include "student.h" 
#include <string >
class Roster
{
public:
	int lastIndex = 0;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
public:

	void parse(string row);
	void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int day1, int day2, int day3, DegreeProgram dp);
	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string StudentID);
	bool remove(string StudentID);
	~Roster();//destructor
};
