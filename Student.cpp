#include <iostream>
#include "student.h"
using std::string;
using namespace std;

Student::Student()
{
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->Age = 0;
	for (int i = 0; i < daysinCourseSize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK; // default value of Network 
}
Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int days[], DegreeProgram degreeProgram)
{
	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->EmailAddress = EmailAddress;
	this->Age = Age;
	for (int i = 0; i < daysinCourseSize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;

}

Student::~Student() {} // destructor 



//Getters 
string Student::getStudentID()
{
	return this->StudentID;
}

string Student::getFirstName()
{
	return this->FirstName;
}

string Student::getLastName()
{
	return this->LastName;
}

string Student::getEmailAddress()
{
	return this->EmailAddress;
}

int Student::getAge()
{
	return this->Age;
}

int* Student::getDays()
{
	return this->days;
}


DegreeProgram Student::getDegreeProgram()
{
	return this->degreeProgram;
}




//Setters

void Student::setStudentID(string ID)
{
	this->StudentID = ID;
}

 void Student::setFirstName(string FN)
{
	this->FirstName = FN;
}

void Student::setLastName(string LN)
{
	this->LastName = LN;
}

void Student::setEmailAddress(string EA)
{
	this->EmailAddress = EA;
}

void Student::setDays(int days[])
{
	for (int i = 0; i < daysinCourseSize; i++) this->days[i] = days[i];
}

void Student::setAge(int A)
{
	this->Age = A;
}

void Student::setDegree(DegreeProgram dp)
{
	this->degreeProgram = dp;
}

void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; // integer to string representation
}
