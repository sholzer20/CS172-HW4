//This program utilizes a function called doubleCapacity that returns an array twice the size of the original array passed. It also 
//copies the contents of the original array into the first half of the new array

#include <iostream>
using namespace std;

int* doubleCapacity(const int* list, int size)
{
	int* doubleSize = new int[2 * size]; //Creating a new array that's twice the size of the original one

	for (int i = 0; i < size; i++)
	{
		doubleSize[i] = list[i]; //Copies the original array into the new array, which occupies the first half
	}
	return doubleSize;
}


int main()
{
	int ar1[5] = { 1,2,3,4,5}; //Test array with size of 5
	int* ar2 = doubleCapacity(ar1, 5); //Passing the array into doubleCapacity

	//For the sake of testing the whole array, the next loop asks the user for the remaining five integers to fill the array
	for (int i = 5; i < 10; i++)
	{
		cout << "Please enter an integer: ";
		cin >> ar2[i];
	}
	cout << endl << "The contents of the new array is: ";
	for (int i = 0; i < 10; i++) //Outputs the contents of the complete array
	{
		if (i <= 8)
		{
			cout << *(ar2 + i) << ", ";
		}
		else
		{
			cout << *(ar2 + i) << endl;
		}
	}
	delete ar2; //Finally, deletes the array to free memory
	return 0;
}