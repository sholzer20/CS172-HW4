#include "Rectangle2D.h"
#include <cmath>
using namespace std;

Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

double Rectangle2D::getX() const
{
	return x;
}

double Rectangle2D::getY() const
{
	return y;
}

void Rectangle2D::setX(double x)
{
	this->x = x;
}

void Rectangle2D::setY(double y)
{
	this->y = y;
}

double Rectangle2D::getWidth() const
{
	return width;
}

double Rectangle2D::getHeight() const
{
	return height;
}

void Rectangle2D::setWidth(double width)
{
	this->width = width;
}

void Rectangle2D::setHeight(double height)
{
	this->height = height;
}

double Rectangle2D::getArea() const
{
	return width*height;
}

double Rectangle2D::getPerimeter() const
{
	return 2*(width+height);
}

//Calculates the endpoints on each side of the x/y axes using width and height and compares the x and y values of the passed
//point to the x and y values of each of those points
bool Rectangle2D::contains(double x, double y) const
{
	double top =  this->y + (.5 * height); 
	double right = this->x + (.5 * width);
	double bottom = this->y - (.5 * height);
	double left = this->x - (.5 * width);

	return (x >= left && x <= right && y >= bottom && y <= top);
}

//Calculates the endpoints on each side of the x/y axes using width and height for each of the rectangles.
//Then compares the points respectively to determine if the second rectangle is contained in the first
bool Rectangle2D::contains(const Rectangle2D & r) const
{
	double top1 = y + (.5 * height); //End points on the axes of the given rectangle
	double right1 = x + (.5 * width);
	double bottom1 = y - (.5 * height);
	double left1 = x - (.5 * width);

	double top2 = r.getY() + (.5 * r.getHeight()); //End points on the axes of the passed rectangle
	double right2 = r.getX() + (.5 * r.getWidth());
	double bottom2 = r.getY() - (.5 * r.getHeight());
	double left2 = r.getX() - (.5 * r.getWidth());

	return (top2 < top1) && (left2 > left1) && (bottom2 > bottom1) && (right2 < right1);
}

//Calculates two corner points on each rectangle using width, height, and center
//Then compares the points respectively to determine if the passed rectangle overlaps the given one
bool Rectangle2D::overlaps(const Rectangle2D & r) const
{
	//Defines the sides of the first rectangle. Top/left represent the upper left corner, and bottom/right represent bottom right corner
	double top1 = y + (.5 * height);  
	double left1 = x - (.5 * width);
	double bottom1 = y - (.5 * height);
	double right1 = x + (.5 * width);

	//Defines the sides of the first rectangle. Top/left represent the upper left corner, and bottom/right represent bottom right corner
	double top2 = r.getY() + (.5 * r.getHeight()); 
	double left2 = r.getX() - (.5 * r.getWidth());
	double bottom2 = r.getY() - (.5 * r.getHeight());
	double right2 = r.getX() + (.5 * r.getWidth());
	return ((left1 <= right2) && (right1 >= left2) && (top1 >= bottom2) && (bottom1 <= top2));
}
