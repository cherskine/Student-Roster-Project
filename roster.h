//
//
// roster.h
// C867 - Performance Assessment -
//
//
#include<iostream>
#include<string>
#ifndef roster_h
#define roster_h
#include "student.h"
using namespace std;


  // Roster Class
    class Roster {
    private:
 
    int lastIndex = -1;
 
    const static int numStudents = 5;
     
        

  public:
  //  Creates  an array of pointers
    Student* classRosterArray[numStudents];
  
  //  Parses each set of data indentified in studentData Table and add student objectS to classRoster array
      void parse(string row);
  
  //  Creates a public method to add student data and updates the roster
     void add(string StudentID, string FirstName, string LastName, string EmailAddress, int  Age, int DaysToComplete1, int   DaysToComplete2, int DaysToComplete3, DegreeProgram degreeProgram);
  
   // Method to remove students from the roster
      void remove(string studentID);
  
   // Prints a tab-seperated list of student data
      void printAll();
  
   // Prints students avetage number of days in courses
      void printAvgDaysCourse(string studentID);
  
    // Prints invalid email addresses
      void printInvalidEmails();
  
    // Prints students by degree program
      void printbyDegreeProgram(DegreeProgram degreeProgram);
  
    //  Destructor
      ~Roster();
      
  };

#endif
