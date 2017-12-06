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
	Point(const Point &p);
	const Point &operator=(const Point &p);
	virtual ~Point();
private:
	int x, y;
};

/////////////////////////////////////////////////////////////////////////////////////////

class Shape : public Point {
public:
	Shape();
	Shape(const Shape &s);
	const Shape &operator=(const Shape &s);
	virtual ~Shape();

	double getArea();
	double getPerim();

	friend ostream &operator<<(ostream &output, const Shape &self);
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Rectangle : public Shape {
public:
	Rectangle(Point, Point);
	Rectangle(const Rectangle &r);
	const Rectangle &operator=(const Rectangle &r);
	virtual ~Rectangle();
private:
	Point b_left, t_right;
};

/////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Shape {
public:
	Triangle(Point, Point, Point);
	Triangle(const Triangle &t);
	const Triangle &operator=(const Triangle &t);
	virtual ~Triangle();
private:
	Point a, b, c;
};

/////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Shape {
public:
	Circle(Point, int);
	Circle(const Circle &c);
	const Circle &operator=(const Circle &c);
	virtual ~Circle();
private:
	Point o;
	int radius;
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