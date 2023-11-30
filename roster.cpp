//
//  roster.cpp
//  C867 - Performance Assessment -
//


#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


  // Parses each set of data indentified in studentData Table and adds each student object to classRoster array
      void Roster::parse (string studentData){

  
  // Reads studenID
     int rhs = (int)studentData.find(",");
     string studentID = studentData.substr (0, rhs);
  
  // Reads the first name of student
     int lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     string firstName = studentData.substr(lhs, rhs - lhs);
 
  // Reads the last nme of student
     lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     string LastName = studentData.substr(lhs, rhs - lhs);
 
  // Reads the email address of student
     lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     string emailAddress = studentData.substr(lhs, rhs - lhs);
 
  // Reads the age of student
     lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     int age = stoi(studentData.substr(lhs, rhs - lhs));
 
  // Reads number of days for course completion
     lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     int daysToComplete1 = stod(studentData.substr(lhs, rhs - lhs));
          
     lhs = rhs +1;
     rhs = (int)studentData.find(",", lhs);
     int daysToComplete2 = stod(studentData.substr(lhs, rhs - lhs));
          
     lhs = rhs +1;
     rhs = (int) studentData.find(",", lhs);
     int daysToComplete3 = stod(studentData.substr(lhs, rhs - lhs));
          
          
    // Reads the enrolled drgree program
       DegreeProgram degreeProgram = SOFTWARE;
       if (studentData. at(1) == '1') degreeProgram = NETWORK;
       else if (studentData.at(1) == '2') degreeProgram = SECURITY;
       else if (studentData.at(1) == '3') degreeProgram = SOFTWARE;
       else if (studentData.at(1) == '4') degreeProgram = NETWORK;
       else if (studentData. at(1) == '5') degreeProgram = SOFTWARE;
          
          
 
     add(studentID, firstName, LastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3,degreeProgram);
     }
    
   // Creates instance variables and updates the roster
    void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram){
    
    // Builds daysToComplete array that's added to roster
     int daysToComplete[3] = {daysToComplete1, daysToComplete2, daysToComplete3};
    
    
     classRosterArray[++lastIndex] = new Student (studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
    }
            
       


    //  Removes student from roster
void Roster::remove(string studentID) {
    
    // Searches for student ID and marks  if student was not located
    bool removed = false;
    for (int x = 0; x <= Roster::lastIndex; x++){
        if (classRosterArray[x]-> getStudentID() == studentID) {
            delete classRosterArray[x];
            classRosterArray[x] = nullptr;
            for ( int y = x; y < Roster::lastIndex; y++){
                classRosterArray[y] = classRosterArray[y +1];
            }
            classRosterArray[Roster::lastIndex] = nullptr;
            Roster::lastIndex--;
            removed = true;
        }
        }
        if (removed) {
        cout << "The student with the ID: " << studentID << " was removed." << endl;
        }
        }

     
        //  Prints all students data
        void Roster::printAll() {
        for (int x = 0; x <=lastIndex; x++) classRosterArray[x]->print();
    
        }
        

        
        

        // Prints average days to complete from array of days in the course
        void Roster::printAvgDaysCourse(string studentID) {
        bool found = false;
        for (int x = 0; x < numStudents; x++) {
        if (Roster::classRosterArray[x]->getStudentID() == studentID) {
            cout << "Student ID: " << studentID << ", " << " average days in course is: ";
            int avgDays = (classRosterArray[x]->getDaysToComplete()[0] +classRosterArray[x]->getDaysToComplete() [1] + classRosterArray[x]->getDaysToComplete()[2]) / 3;
            cout << avgDays << endl;
            return; // loop exit after finding the student
           
        }
        }
        }

        
        // Finds the invalid emails and prints for viewing
        void Roster::printInvalidEmails() {
        bool any = false;
    
        for (int x = 0; x <= Roster::lastIndex; x++) {
        string email = Roster::classRosterArray[x]->getEmailAddress();
        if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") !=string::npos) {
            any = true;
            cout << email << endl;
        }
        }
        if (!any) cout << "Not Found";
    
        }

        // Prints students by degree program
        void Roster::printbyDegreeProgram(DegreeProgram degreeProgram) {
        for (int x = 0; x <= Roster::lastIndex; x++) {
        if (Roster::classRosterArray[x]->getDegreeProgram() == degreeProgram) classRosterArray[x]->print();
        }
        cout << endl;
        }

        //Destructor
        Roster::~Roster() {
        for (int x = 0; x < numStudents; x++) {
        delete classRosterArray[x];
        classRosterArray[x] = nullptr;
        }
        cout <<  "Done." << endl;
        }
