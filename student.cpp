//
//  student.cpp
//  C867 - Performance Assessment -
//
//  
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "student.h"

using std::string;
using std::cout;

using namespace std;

 //  Default Constructor - initiates vaiables to default values
    Student::~Student() {
    this->studentID ="";
    this->firstName ="";
    this->lastName ="";
    this->emailAddress ="";
    this->age =0;
    for (int x=0; x <  3; x++) this->daysToComplete[x] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
    }

 // A constructor that  uses all input parameters provided in the table
    Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int x = 0; x < 3; x++) {
        this->daysToComplete[x] = days[x];
    }
    this->degreeProgram = degreeProgram;
    }

  // A  getter for each instance variable from class member variables
    string Student::getStudentID() { return this->studentID ; }
    string Student::getFirstName() { return this->firstName ; }
    string Student::getLastName()  { return this->lastName ;}
    string Student::getEmailAddress()  { return this->emailAddress;}
    int Student::getAge() {return this->age ;}
    int* Student::getDaysToComplete() {return this->daysToComplete; }
    DegreeProgram Student::getDegreeProgram() {return this->degreeProgram; }


 // A setter for each instance variable from class member variables 
    void Student::setStudentId(string studentID) {this->studentID = studentID;}
    void Student::setFirstName(string firstName) {this->firstName = firstName;}
    void Student::setLastName(string lastName)   {this->lastName  = lastName;}
    void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress; }
    void Student::setAge(int age) {this->age = age;}
    void Student::setDaysToComplete(int daysToComplete[]) {
    for (int x = 0; x < 3; x++) {this->daysToComplete[x] = daysToComplete[x]; }
    }
    void Student::setDegreeProgram (DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram; }

    // Prints specific data
    void Student::print() {
        cout << studentID << "\t";
        cout << firstName  <<"\t";
        cout << lastName  <<"\t";
        cout <<  emailAddress  <<"\t";
        cout << age <<"\t";
        cout <<  daysToComplete[0] << " , " << daysToComplete[1] << ", " << daysToComplete[2] <<"\t";
        cout << degreeTypeStrings[this->getDegreeProgram()] << endl;
   
    }
