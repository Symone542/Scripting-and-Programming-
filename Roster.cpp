#pragma once
#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

void Roster::parse(string studentData)
{

		//studentdID find the ,
		int rhs = studentData.find(",");
	string id = studentData.substr(0, rhs);
	//firstName looks for 2 comma
	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string first = studentData.substr(lhs, rhs - lhs);
	//lastName looks for 3 comma
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string last = studentData.substr(lhs, rhs - lhs);
	//emailAddress looks for 4 comma
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);
	//age looks for 5 comma use stoi for string to int
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	//numOfDays1 looks for 6 comma use stoi for string to int
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day1 = stoi(studentData.substr(lhs, rhs - lhs));
	//numOfDays2 looks for 7 comma use stoi for string to int
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day2 = stoi(studentData.substr(lhs, rhs - lhs));
	//numOfDays3 looks for 8 comma use stoi for string to int
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day3 = stoi(studentData.substr(lhs, rhs - lhs));
	//DegreeProgram
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string dProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (dProgram.compare("NETWORK") == 0) {
		degree = DegreeProgram::NETWORK;
	}
	if (dProgram == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	

	add(id,first,last,email,age,day1,day2,day3,degree);

}


void Roster::add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int day1, int day2, int day3, DegreeProgram degreeProgram)
{
	int days[3] = { day1, day2, day3 };
	classRosterArray[lastIndex++] = new Student(StudentID, FirstName, LastName, EmailAddress, Age, days, degreeProgram);
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print(); // check student.cpp if this fails
}



void Roster::printAverageDaysInCourse(string StudentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID);
		{
			cout << StudentID << ":";
			cout << (classRosterArray[i]->getDays()[0]+
				classRosterArray[i]->getDays()[1]+
				classRosterArray[i]->getDays()[2]) / 3.0 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool InvalidEmail = false;
	for (int i = 0; i < Roster::lastIndex; i++)
	{
		string e = classRosterArray[i]->getEmailAddress();
		// looking for these things. if not found npos/ no matches 
		if (( e.find('@') == string::npos )||  (e.find(".") == string::npos) || (e.find(" ", 0) != string::npos));
		{
			// found email that was invalid 
			InvalidEmail = true;
			cout << e << ":" << classRosterArray[i]->getEmailAddress() << std::endl;
		}
		if (!InvalidEmail) cout << "No invalid emails found." << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << endl; 
}

bool Roster::remove(string StudentID)
{
	bool success = false; // assuming the student is not there
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true; // student was found
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i]; // swapping with last student 
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; // student is invisible, not actually deleted 
		}
	}
	if (success)
	{
		cout << StudentID << "Removed" << std::endl << std::endl;
		this->printAll();
	}
	else cout << StudentID << " Error:Not Found" << std::endl << std::endl;;
	return 0;
}
Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED" << std::endl << std::endl;;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
