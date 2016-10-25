//This program generates three rectangles using the Rectandle2D class. It then tests using the first rectangle if a point is contained
//inside of it, if the second rectangle is contained inside of the first, and if the third rectangle overlaps the first

#include <iostream>
#include "Rectangle2D.h"
using namespace std;

int main() 
{
	Rectangle2D* r1 = new Rectangle2D(2, 2, 5.5, 4.9);
	Rectangle2D* r2 = new Rectangle2D(4, 5, 10.5, 3.2);
	Rectangle2D* r3 = new Rectangle2D(3, 5, 2.3, 5.4);

	cout << "The area of the first rectangle is: " << r1->getArea() << endl;
	cout << "The perimeter of the first rectangle is: " << r1->getPerimeter() << endl;
	cout << "The point (3,3) is contained within the first rectangle: " << boolalpha << r1->contains(3, 3) << endl;
	cout << "The second rectangle is contained within the first rectangle: " << boolalpha << r1->contains(*r2) << endl;
	cout << "The third rectangle overlaps the first rectangle: " << boolalpha << r1->overlaps(*r3) << endl;
}