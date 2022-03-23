#include <iostream>
#include <string>
#include "ROSTER.H"
#include "STUDENT.H"


using namespace std;

int main()
{

	cout << "Class: Scripting and Programming - Applications - C867" << endl;
	cout << "Langauge Used: C++" << endl;
	cout << "Student ID: #004337676" << endl;
	cout << "Student Name: Zenobia Malone" << endl << endl;

	const string studentData[5] =
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,10,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Zenobia,Malone,zmalon2@student.wgu.edu,24,30,60,90,SOFTWARE"};

	const int numStudents = 5;
	Roster  classRoster;



	for (int i = 0; i < numStudents; i++)
		classRoster.parse(studentData[i]);
	cout << "Displaying All Students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying Invalid Emails: " << std::endl;
	cout << "debug test" << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;


	cout << "Displaying Average Days In Course: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << std::endl;

	cout << "Removing A3 " << endl;
	classRoster.remove("A3");

	cout << "Remvoing A3" << endl;
	classRoster.remove("A3");
	cout << std::endl << std::endl;;

	system("pause");
	return 0;
}
