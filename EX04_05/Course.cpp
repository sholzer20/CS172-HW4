#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

Course::Course(const string & courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::Course(const Course& course) //Copy constructor
{
	courseName = course.getCourseName(); //Copies each of the member variables
	numberOfStudents = course.getNumberOfStudents();
	capacity = course.getCapacity();
	students = new string[capacity];

	for (int i = 0; i < numberOfStudents; i++) //Copies the contents of the array "students" using deep copy method
	{
		students[i] = course.getStudents()[i];
	}
}

Course::~Course()
{
	delete[] students;
}

string Course::getCourseName() const
{
	return courseName;
}

int Course::getCapacity() const
{
	return capacity;
}

void Course::addStudent(const string & name)
{
	if (numberOfStudents > capacity)  //If the number of students excedes the capacity of the array, calls the doubleCapacity function
	{
		students = doubleCapacity(students, capacity); //Returns an array twice as large with contents copied over
		for (int i = 0; i < capacity; i++)
		{
			if (students[i] == "null") //Sets the new student to an empty space if there is one
			{
				students[i] = name;
				return; //Does not increase numberOfStudents since we didn't add to the end of the array
			}
		}
		students[numberOfStudents] = name; //If no empty space found, puts new student at the end of the array
		numberOfStudents++;
	}
	else 
	{
		for (int i = 0; i < capacity; i++)
		{
			if (students[i] == "null") //Sets the new student to an empty space if there is one
			{
				students[i] = name;
				return; //Does not increase numberOfStudents since we didn't add to the end of the array
			}
		}
		students[numberOfStudents] = name; //If no empty space found, puts new student at the end of the array
		numberOfStudents++;
	}
}

void Course::dropStudent(const string & name)
{
	for (int i = 0; i < capacity; i++) //Finds the name of the student and excludes it from the new array
	{
		if (students[i] == name)
		{
			students[i] = "null"; //Leaves space in the array as "null" to place new students in later
			break;
		}
	}
}

string * Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

void Course::clear()
{
	numberOfStudents = 0; 
	for (int i = 0; i < capacity; i++) //Sets every name to "null", thereby removing them all from the course
	{
		students[i] = "null";
	}
}

void Course::printStudents()
{
	for (int i = 0; i < numberOfStudents; i++) //Reads through students and prints all of them
	{
		if (students[i] != "null") //Doesn't print the string "null" because it does not represent a student
		{
			if (i == numberOfStudents - 1) //Formatting
			{
				cout << students[i] << endl;
			}
			else
			{
				cout << students[i] << ", ";
			}
		}
	}
	cout << endl;
}

string* Course::doubleCapacity(const string* list, int size)
{
	string* doubleSize = new string[2 * size]; //Creating a new array that's twice the size of the original one

	for (int i = 0; i < size; i++)
	{
		doubleSize[i] = list[i]; //Copies the original array into the new array, which occupies the first half
	}
	return doubleSize;
}
