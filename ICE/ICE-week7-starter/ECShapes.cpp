// Created by Y. Wu, Feb 27, 2023
// Base class: Shape for different kinds of geometry
// One interface function: CalcArea(), no parameter, return int (area of the shape). How should you define it?
class Shape {
public:
    virtual int CalcArea() = 0;
};

// Rectangle class: define two constructors
// (i) take two parameters, width and height
// (ii) take four parameters: x1,y1,x2,y2  where (x1,y1) is the upper left corner and (x2,y2) is the lower right corner

template <class T>
class Rectangle : public Shape {
public:
    Rectangle(T w, T h) : width(w), height(h) {}
    Rectangle(T x1, T y1, T x2, T y2) : width(x2-x1), height(y1-y2) {}
    virtual int CalcArea() { return width * height; };
private:
    T width;
    T height;
};

template <class T>
// Class Square: a special rectangle
// One constructor: side length
class Square : public Rectangle<T> {
public:
    Square(T side) : Rectangle<T>(side, side){}
};


