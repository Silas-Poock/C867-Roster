// C867 Class Roster FINAL PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Roster.h"
using namespace std;

void populateRoster(string studentData[]) {
    //FIXME
}

int main()
{
    //Class Table Info
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Silas,Poock,silas.poock@gmail.com,24,14,27,39,SOFTWARE"
    };

    //Student Data to be read into class roster and student classes
    string currStudentString;
    string studentID = "Null";
    string firstName;
    string lastName; 
    string emailAddress;
    int age;
    int classDays1;
    int classDays2;
    int classDays3;
    string degreeName;

    Roster classRoster;
    int i = 0;
    int sStart = 0;
    int sEnd = 0;
    string tmp = "null";
   
    //Populating roster
    for (i = 0; i < 5; ++i) {
        currStudentString = studentData[i];
        sEnd = currStudentString.find(',');
        studentID = currStudentString.substr(sStart, sEnd);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        firstName = currStudentString.substr(sStart, sEnd);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        lastName = currStudentString.substr(sStart, sEnd);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        emailAddress = currStudentString.substr(sStart, sEnd);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        tmp = currStudentString.substr(sStart, sEnd);
        age = stoi(tmp);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        tmp = currStudentString.substr(sStart, sEnd);
        classDays1 = stoi(tmp);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        tmp = currStudentString.substr(sStart, sEnd);
        classDays2 = stoi(tmp);
        currStudentString.erase(sStart, sEnd + 1);

        sEnd = currStudentString.find(',');
        tmp = currStudentString.substr(sStart, sEnd);
        classDays3 = stoi(tmp);
        currStudentString.erase(sStart, sEnd + 1);

        degreeName = currStudentString;
        classRoster.add(studentID, firstName, lastName, emailAddress, age, classDays1, classDays2, classDays3, degreeName); 

       // cout << studentID << endl << firstName << endl << lastName << endl << emailAddress << endl << age << " mult age to check int: " << age * 100 << endl << classDays1 << endl << classDays2 << endl << classDays3 << endl << currStudentString << endl << endl;

    }
    classRoster.printAll();

    for (i = 0; i < 5; ++i) {
        string currID = "null";
        currID = classRoster.classRosterArray[i]->GetStudentID();
        //cout << currID << endl;
       classRoster.printAverageDaysInCourse(currID);
    }

    classRoster.printInvalidEmails();

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");


}
