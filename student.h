//
//  student.h
//  C867 - Performance Assessment -
//
//
#include <iostream>
#include <string>
#ifndef student_h
#define student_h
#include "degree.h"

using std::string;
using std::cout;

  // A student class which includese the variables listed

   class Student {
    
   private:
    
       string studentID;
       string firstName;
       string lastName;
       string emailAddress;
       int    age;
       int    daysToComplete[3];
       DegreeProgram degreeProgram;
       
       
   public:
   // Default Constructor
       Student();
       
  //  Constructor using all input parameters provided in the table
       Student(string studentID, string firstName, string lastName, string emailAddress, int  age, int daysToComplete[3], DegreeProgram degreeProgram);
   
  
    
   // Getter for each instance variable from class member variables
       string getStudentID();
       string getFirstName();
       string getLastName ();
       string getEmailAddress();
       int    getAge();
       int*   getDaysToComplete();
       DegreeProgram getDegreeProgram();
       
   // Setter for each instance variable from class member variables
       void setStudentId(string studentID);
       void setFirstName(string firstName);
       void setLastName (string lastName);
       void setEmailAddress(string emailAddress);
       void setAge( int age);
       void setDaysToComplete(int daysToComplete[]);
       void setDegreeProgram (DegreeProgram degreeProgram);
  
  // Prints specific data
       void print();
       
   // Destructor
       ~Student();
};










#endif /* student_h */
