#include "Roster.h"
#include <vector>

Roster::Roster() {
	int i;
	
	for (i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}
}

Roster::~Roster() {
	int i; 

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram) {
	if (numStudents < 5) {

		classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);


		++numStudents;
	}
}
void Roster::remove(string studentID) {
	int i;
	bool idFound = false;
	for (i = 0; i < 5; ++i) {
		Student* tmpStudent;
		if (classRosterArray[i] != nullptr) {
			tmpStudent = classRosterArray[i];
			if (studentID == tmpStudent->GetStudentID()) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				idFound = true;
			}
		}

	}
	if (idFound == false) {
		cout << "Requested studentID " << studentID << " was not found, it may have been removed previously : (" << endl << endl;
	}
}
void Roster::printAll() {
	int i;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			Student* currStudent;
			currStudent = classRosterArray[i];
			cout << "Student: ";
			currStudent->PrintStudentID();
			cout << "First Name: ";
			currStudent->PrintFirstName();
			cout << "Last Name: ";
			currStudent->PrintLastName();
			cout << "Student Email: ";
			currStudent->PrintStudentEmail();
			cout << "Age: ";
			currStudent->PrintStudentAge();
			cout << "Days in course: ";
			currStudent->PrintCourseNumDays();
			cout << "Degree Program: ";
			currStudent->PrintStudentDegree();
			cout << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i;
	int avgDays = -1;
	vector<int> userDays;
	int numDaysTot = 0;

	for (i = 0; i < 5; ++i) {
		Student* currStudent;
		currStudent = classRosterArray[i];
		if (studentID == currStudent->GetStudentID()) {
			userDays = currStudent->GetCourseNumDays();
			numDaysTot += userDays.at(0);
			numDaysTot += userDays.at(1);
			numDaysTot += userDays.at(2);
			avgDays = numDaysTot / 3;
			cout << "Student: " << studentID << "'s average days in a course: " << avgDays << endl << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	int i;
	string currEmail = "null";

	for (i = 0; i < 5; ++i) {
		bool invalidEmail = false;
		Student* currStudent;

		currStudent = classRosterArray[i];
		currEmail = currStudent->GetStudentEmail();

		if (currEmail.find(',') != string::npos) {
			invalidEmail = true;
		}
		if (currEmail.find(' ') != string::npos) {
			invalidEmail = true;
		}
		if (currEmail.find('@') == string::npos) {
			invalidEmail = true;
		}
		if (invalidEmail) {
			cout << currStudent->GetStudentID() << " (" << currStudent->GetFirstName() << ") has the following invalid Email Address: " << currEmail << endl << endl;
		}
		

		
	}
}

void Roster::printByDegreeProgram(DegreeProgram uDegree) {
	int i;
	bool noStudents = true;
	
	for (i = 0; i < 5; ++i) {

		Student* currStudent;
		currStudent = classRosterArray[i];
		if (currStudent->GetStudentDegree() == uDegree) {
			cout << currStudent->GetFirstName() << " " << currStudent->GetLastName() << " is enrolled in ";
			currStudent->PrintStudentDegree();
			noStudents = false;
		};
	}
	if (noStudents == true) {
		cout << "There are no students currently enrolled in the " << uDegree << " program." << endl;
	}
	cout << endl;
}