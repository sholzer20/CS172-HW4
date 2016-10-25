#pragma once
#include <string>
#include <iostream>
using namespace std;

class Course
{
private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;

public:
	Course(const string& courseName, int capacity);
	~Course();
	Course(const Course&);
	string getCourseName() const;
	int getCapacity() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudents() const;
	int getNumberOfStudents()const;
	void clear();
	string* doubleCapacity(const string* list, int size);
	void printStudents();
};