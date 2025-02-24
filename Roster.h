#pragma once
#pragma once
#include "Degree.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

class Roster
{

public:
	Student* classRosterArray[5];
	int numStudents = 0;
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram uDegree);
	//Roster();
	

	

};

