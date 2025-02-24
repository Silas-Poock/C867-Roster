#pragma once
#include <string>
#include <iostream>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, NONE };
class Degree
{
private:
	
	DegreeProgram studentDegreeEnrolled = NONE; 
public:
	void SetDegreeProgram(string uDegree) {
		if (uDegree == "SECURITY") {
			studentDegreeEnrolled = SECURITY;
		}
		else if (uDegree == "NETWORK") {
			studentDegreeEnrolled = NETWORK;
		}
		else if (uDegree == "SOFTWARE") {
			studentDegreeEnrolled = SOFTWARE;
		}
		}
	void PrintDegreeProgram() {
		if (studentDegreeEnrolled == 0) {
			cout << "SECURITY" << endl;
		}
		else if (studentDegreeEnrolled == 1) {
			cout << "NETWORK" << endl;
		}
		else if (studentDegreeEnrolled == 2) {
			cout << "SOFTWARE" << endl;
		}
	}
	DegreeProgram GetDegreeProgram() {
		return studentDegreeEnrolled;
	}

	static string DegreeProgramToString(DegreeProgram uDegree) {
		switch (uDegree) {
		case SECURITY: return "SECURITY";
		case NETWORK: return "NETWORK";
		case SOFTWARE: return "SOFTWARE";
		default: return "NONE";
		}
	}
	
	/*bool operator==(const string& uDegree) {
		return (uDegree == "SECURITY" && studentDegree == SECURITY ||
			uDegree == "NETWORK" && studentDegree == NETWORK ||
			uDegree == "SOFTWARE" && studentDegree == SOFTWARE);
	}*/
};

