//
// main.cpp
//
//
//
//

#include <iostream>
#include <string>
#include "roster.h"


    using namespace std;

    int main(){
  
    // Title for Project, which contains course, language used, Student ID# and student name.
    cout<< "Course: Scripting and Programming Applications - C867" << endl;
    cout<< "Programming Language: C++" <<endl;
    cout<< "Student ID: 011171759" << endl;
    cout<< "Name: Christine Erskine" << endl;
    cout << endl;
    cout << endl;
    
    // Student Data Table with added personal info
    const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com, 20, 30, 35, 40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom, 19, 50, 30, 40,NETWORK",
    "A3,Jack, Napoli,The_lawyer99yahoo.com, 19, 20, 40, 33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net, 22, 50, 58, 40,SECURITY",
    "A5,Christine,Erskine,cerski7@wgu.edu, 30, 10,  16, 20,SOFTWARE"
    };
        
        
    // Created an instance of the roster class and named it ClassRoster
    Roster classRoster;
        
    
    //Adds each student to classRoster
    const int numStudents = 5;
    
    for (int x = 0; x < numStudents; x++) {
        classRoster.parse(studentData[x]);
    }
    
    // Rest of the main function
    
    //Prints all students information
    cout << "Displaying all Students: " << endl;
    classRoster.printAll();
    cout << endl;
    
    
    // Prints invalid emails
    cout << "Displaying  invalid emails :  " << endl;
    classRoster.printInvalidEmails();
    cout << endl;
        
    
    // Prints average days in courses for each student
    for (int x = 0; x < numStudents; x ++) {
    classRoster.printAvgDaysCourse(classRoster.classRosterArray[x]->getStudentID());
    }
    cout << endl;
        
        
    
    //Prints students in a specific degree program
    cout << "Showing students in degree program: SOFTWARE" << endl;
    classRoster.printbyDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    // Removes student A3 from Roster
    cout << "Removing A3:" << endl;
    classRoster. remove("A3");
    cout << endl;
        
    // Prints Roster again
    cout << "Printing Roster Again" << endl;
    classRoster.printAll();
    cout << endl;
    
    // Removes A3 from again, confirms there is no longer A3 Student.
    cout << "Removing A3 again" << endl;
    classRoster.remove("A3");
    cout << endl;
    
        return 0;
    
}
