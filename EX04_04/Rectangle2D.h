#pragma once
class Rectangle2D
{
private: 
	double x;
	double y;
	double width;
	double height;

public:
	Rectangle2D();
	Rectangle2D(double x, double y, double width, double height);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double getWidth() const;
	double getHeight() const;
	void setWidth(double width);
	void setHeight(double height);
	double getArea() const;
	double getPerimeter() const;
	bool contains(double x, double y) const;
	bool contains(const Rectangle2D &r) const;
	bool overlaps(const Rectangle2D &r) const;

};