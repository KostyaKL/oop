/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Dr. Vladimir Nodelman  61307-1
Targil: Dr. Leonid Kugel 661307-1 / Haim Shafir 661307-2
*/

/////////////////////////////////////////////////////////////////////////////////////////

#include "headers.h"
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////

class Point {
public:
	Point(int, int);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Shape : public Point {
public:
	double getArea();
	double getPerim();

	friend ostream &operator<<(ostream &output, const Shape &self);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Rectangle : public Shape {
public:
	Rectangle(Point, Point);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Shape {
public:
	Triangle(Point, Point, Point);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Shape {
public:
	Circle(Point, int);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

void hagasha_3() {
	Point o(0, 0);
	Point a(0, 1);
	Point b(1, 0);
	Shape *shapes[] = {
		new Rectangle(a, b),
		new Triangle(o, a, b),
		new Circle(o, 1) };
	for (int i = 0; i < 3; ++i)
		cout << i << ") area=" << shapes[i]->getArea() <<
		" perim=" << shapes[i]->getPerim() << endl;
	for (int i = 0; i < 3; ++i)
		delete shapes[i];
}

/////////////////////////////////////////////////////////////////////////////////////////