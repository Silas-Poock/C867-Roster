


#pragma once
#include "Degree.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
	string studentID = "No ID";
	string firstName = "No first name";
	string lastName = "No last name";
	string studentEmail = "No email";
	int studentAge = -1;
	vector<int>  courseNumDays = { -1, -1, -1 };
	Degree studentDegree;

public:
	//Constructors
	Student();
	Student(string uStudentID, string uFirstName, string uLastName, string uStudentEmail, int uStudentAge, int c1, int c2, int c3, string degreeProgram);
	

	//Setters
	void SetStudentID(string uStudentID) {studentID = uStudentID; };
	void SetFirstName(string uFirstName) {firstName = uFirstName; } ;
	void SetLastName(string uLastName) { lastName = uLastName; };
	void SetStudentEmail(string uStudentEmail) { studentEmail = uStudentEmail; };
	void SetStudentAge(int uStudentAge) { studentAge = uStudentAge; };
	void SetCourseNumDays(int c1, int c2, int c3);
	void SetStudentDegree(string uStudentDegree);

	//Getters
	string GetStudentID() const { return studentID;};
	string GetFirstName() const { return firstName; };
	string GetLastName() const { return lastName; };
	string GetStudentEmail() const { return studentEmail; };
	int GetStudentAge() const { return studentAge; };
	vector<int> GetCourseNumDays() const { return courseNumDays; };
	DegreeProgram GetStudentDegree();

	//Printers
	void PrintStudentID() {cout << studentID << endl;};
	void PrintFirstName() { cout << firstName << endl; };
	void PrintLastName() { cout << lastName << endl; };
	void PrintStudentEmail() { cout << studentEmail << endl; };
	void PrintStudentAge() { cout << studentAge << endl; };
	void PrintCourseNumDays();
	void PrintStudentDegree();


};

