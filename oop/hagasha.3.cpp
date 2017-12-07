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

	void setX(int);
	void setY(int);

	int getX() const;
	int getY() const;
private:
	int x, y;
};

Point::Point(int x = 0, int y = 0) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point &p) {
	x = p.x;
	y = p.y;
}

const Point &Point::operator=(const Point &p) {
	x = p.x;
	y = p.y;
	return *this;
}

Point::~Point() {

}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

/////////////////////////////////////////////////////////////////////////////////////////

class Shape : public Point {
public:
	Shape();
	Shape(const Shape &s);
	const Shape &operator=(const Shape &s);
	virtual ~Shape();

	virtual double getArea() const = 0;
	virtual double getPerim() const = 0;

private:
	Point ancor;
};

Shape::Shape() {
	ancor.setX(0);
	ancor.setY(0);
}

Shape::Shape(const Shape &s) {
	ancor = s.ancor;
}

const Shape &Shape::operator=(const Shape &s) {
	ancor = s.ancor;
	return *this;
}

Shape::~Shape() {

}

/////////////////////////////////////////////////////////////////////////////////////////

class Rectangle : public Shape {
public:
	Rectangle(Point, Point);
	Rectangle(const Rectangle &r);
	const Rectangle &operator=(const Rectangle &r);
	virtual ~Rectangle();

	double getArea() const;
	double getPerim() const;
private:
	Point b_left, t_right;
	int height, width;
};

Rectangle::Rectangle(Point bl, Point tr) {
	b_left = bl;
	t_right = tr;

	height = b_left.getX() - t_right.getX();
	if (height < 0)
		height *= -1;
	width = b_left.getY() - t_right.getY();
	if (width < 0)
		width *= -1;
}

Rectangle::Rectangle(const Rectangle &r) {
	b_left = r.b_left;
	t_right = r.t_right;
}

const Rectangle &Rectangle::operator=(const Rectangle &r) {
	b_left = r.b_left;
	t_right = r.t_right;
	return *this;
}

Rectangle::~Rectangle() {

}


double Rectangle::getArea() const {
	return height*width;
}

double Rectangle::getPerim() const {
	return 2 * (height + width);
}

/////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Shape {
public:
	Triangle(Point, Point, Point);
	Triangle(const Triangle &t);
	const Triangle &operator=(const Triangle &t);
	virtual ~Triangle();

	double getArea() const;
	double getPerim() const;
private:
	Point a, b, c;
	double ab, bc, ca;
	double lng(Point, Point);
};

Triangle::Triangle(Point aP, Point bP, Point cP) {
	a = aP;
	b = bP;
	c = cP;

	ab = lng(a, b);
	bc = lng(b, c);
	ca = lng(c, a);
}

Triangle::Triangle(const Triangle &t) {
	a = t.a;
	b = t.b;
	c = t.c;

	ab = t.ab;
	bc = t.bc;
	ca = t.ca;
}

const Triangle &Triangle::operator=(const Triangle &t) {
	a = t.a;
	b = t.b;
	c = t.c;

	ab = t.ab;
	bc = t.bc;
	ca = t.ca;

	return *this;
}

Triangle::~Triangle() {

}


double Triangle::lng(Point a, Point b) {
	int x, y;
	double lng;
	x = a.getX() - b.getX();
	y = a.getY() - b.getY();
	x *= x;
	y *= y;
	lng = sqrt(x + y);
	return lng;
}


double Triangle::getArea() const {
	double ret;
	ret = (ab + bc + ca);
	ret *= (ab + bc - ca);
	ret *= (ab - bc + ca);
	ret *= (-ab + bc + ca);
	ret = 0.25*sqrt(ret);
	return ret;
}

double Triangle::getPerim() const {
	return ab + bc + ca;
}


/////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Shape {
public:
	Circle(Point, int);
	Circle(const Circle &c);
	const Circle &operator=(const Circle &c);
	virtual ~Circle();

	double getArea() const;
	double getPerim() const;
private:
	Point o;
	int radius;
	const double pi = 3.14159265359;
};

Circle::Circle(Point c, int r) {
	o = c;
	radius = r;
}

Circle::Circle(const Circle &c) {
	o = c.o;
	radius = c.radius;
}

const Circle &Circle::operator=(const Circle &c) {
	o = c.o;
	radius = c.radius;
	return *this;
}

Circle::~Circle() {

}


double Circle::getArea() const {
	return pi*radius*radius;
}

double Circle::getPerim() const {
	return 2 * pi*radius;
}

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

	cout << endl;
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////