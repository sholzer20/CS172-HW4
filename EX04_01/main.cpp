//This program prompts the user for an integer to define the size of an array. It then asks for that number of
//of integers from the user and computes the average and how many numbers are above the average
#include <iostream>
using namespace std;

int main()
{
	int greaterThanAve = 0; //Stores the number of elements greater than average
	double average = 0;
	int arraySize = 0;
	cout << "Please enter an int size for an array: ";
	cin >> arraySize;

	int* intArray = new int[arraySize]; //Creates the array using pointers
	for (int i = 0; i < arraySize; i++) //This loop adds integers to the array and also to average
	{
		cout << "Please enter an integer: ";
		cin >> intArray[i];
		average += intArray[i];
	}
	average /= arraySize; //Computes the average
	cout << endl << "The average is: " << average << endl;

	for (int i = 0; i < arraySize; i++)
	{
		if (intArray[i] > average) //If the int inside the array is greater than average, the total goes up by one
		{
			greaterThanAve++;
		}
	}
	cout << "The number of integers in the array that are greater than the average is: " << greaterThanAve << endl;

	delete intArray; //Deletes the dynamically allocated array
	return 0;
}