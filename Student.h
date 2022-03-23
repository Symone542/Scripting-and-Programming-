#pragma once
#include "degree.h" 
#include <iostream>
using std::string;
using namespace std;
class Student
{
public:
	const static int daysinCourseSize = 3;

private:
	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int  Age;
	int days[daysinCourseSize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int days[], DegreeProgram degreeProgram);
	~Student();

	//Setters 
	void setStudentID(string ID);
	void setFirstName(string FN);
	void setLastName(string LN);
	void setEmailAddress(string EA);
	void setDays(int days[]);
	void setAge(int age);
	void setDegree(DegreeProgram dp);

	// Getters 
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int* getDays();
	// Pointer or return indivudally 
	int getAge();
	DegreeProgram getDegreeProgram();

	void print(); // displays this-> students data 
};
