#include "Student.h"
#include <string>

//Constructor
Student::Student() {
	string studentID = "No ID";
	string firstName = "No first name";
	string lastName = "No last name";
	string studentEmail = "No email";
	int studentAge = -1;
	vector<int>  courseNumDays = { -1, -1, -1 };
	Degree studentDegree;
}
Student::Student(string uStudentID, string uFirstName, string uLastName, string uStudentEmail, int uStudentAge, int c1, int c2, int c3, string degreProgram) {
	studentID = uStudentID;
	firstName = uFirstName;
	lastName = uLastName;
	studentEmail = uStudentEmail;
	studentAge = uStudentAge;

	SetCourseNumDays(c1, c2, c3);
	studentDegree.SetDegreeProgram(degreProgram);
}



//Setters
void Student::SetCourseNumDays(int c1, int c2, int c3) {
	courseNumDays.at(0) = c1;
	courseNumDays.at(1) = c2;
	courseNumDays.at(2) = c3;
}
void Student::SetStudentDegree(string uStudentDegree) {
	studentDegree.SetDegreeProgram(uStudentDegree);
}

//Getters
DegreeProgram Student::GetStudentDegree() {
	return studentDegree.GetDegreeProgram();
}
//Printers
void Student::PrintCourseNumDays() {
	cout << "{ " << courseNumDays.at(0) << ", " << courseNumDays.at(1) << ", " << courseNumDays.at(2) << " }" << endl;
}
void Student::PrintStudentDegree() {
	studentDegree.PrintDegreeProgram();
}

