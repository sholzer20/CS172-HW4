//This program includes a function called findSmallest that accepts an array of integers and it's size. It finds the smallest integer and 
//returns the pointer to that integer.

#include <iostream>
using namespace std;

int* findSmallest(const int* arrayTest, int size)
{
	int smallest = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == 0) //Smallest will start with the first number in the array
		{
			smallest = *arrayTest;
		}
		if (*(arrayTest + i) < smallest) //Checks to see if any of the numbers in the array are smaller than smallest
		{
			smallest = *(arrayTest + i);
		}
	}
	return &smallest; //Returns the pointer to the smallest integer
}


int main()
{
	int arrayTest[8] = {1, 2, 4, 5, 10, 100, 2, -22}; //Test array

	cout << "The smallest number in the array is: " << *(findSmallest(arrayTest, 8)) << endl; //Dereferences the pointer returned from findSmallest

	return 0;
}