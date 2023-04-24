#ifndef SHAPE_H
#define SHAPE_H

// DON"T CHANGE THIS FILE

// Shape: 2D shapes
class Shape
{
public:
	virtual double GetArea() const = 0;
};

// Rectangle
class Rectangle : public Shape
{
public:
	Rectangle(double l, double w) : length(l), width(w) {}
	virtual double GetArea() const { return length*width; }
	
private:
	double length;
	double width;
};

// Circle
class Circle : public Shape
{
public:
	Circle(double r) : radius(r) {}
	virtual double GetArea() const { return radius*radius*3.1415926; }
	
private:
	double radius;
};

#endif
