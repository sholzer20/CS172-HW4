//This program represents a course with students. This test will add three students to the course, remove one, 
//and display the students in the course
#include "Course.h"
#include <iostream>
int main() 
{
	Course* courseTest = new Course("CS172", 10); //Creating the course

	courseTest->addStudent("Sam"); //Adding initial students to the course
	courseTest->addStudent("Nathaniel");
	courseTest->addStudent("David");
	cout << "The students in the class are: ";
	courseTest->printStudents();

	courseTest->dropStudent("Nathaniel"); //Dropping a student and reprinting the roster
	cout << "The students in the class are: ";
	courseTest->printStudents();

	courseTest->addStudent("Jacob"); //Adding a new student to see that it replaces the old student on the roster
	cout << "The students in the class are: ";
	courseTest->printStudents();
	
	delete courseTest;

	return 0;
}
