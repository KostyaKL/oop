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
	Point(int, int); //point cinstructor
	Point(const Point &p); //point copy constructor
	const Point &operator=(const Point &p); //point = point operator overloading
	virtual ~Point(); //point distructor, virtual alowing polymorphysm

	void setX(int); //set x coordiante
	void setY(int); //set y coordiante

	int getX() const; //get x coordiante
	int getY() const; //get y coordiante
private:
	int x, y; //x,y coordinate
};

Point::Point(int x = 0, int y = 0) {
	this->x = x; //set x, default 0
	this->y = y; //set y, default 0
}

Point::Point(const Point &p) {
	x = p.x; //copy x
	y = p.y; //copy y
}

const Point &Point::operator=(const Point &p) {
	x = p.x; //copy x
	y = p.y; //copy y
	return *this; //return refrence to itself
}

Point::~Point() {
	//no memmory to be freed
}

void Point::setX(int x) {
	this->x = x; //set x
}

void Point::setY(int y) {
	this->y = y; //set y
}

int Point::getX() const {
	return x; //return x
}

int Point::getY() const {
	return y; //return y
}

/////////////////////////////////////////////////////////////////////////////////////////

class Shape { //abstract class shape
public:
	/*Shape();
	Shape(const Shape &s);
	const Shape &operator=(const Shape &s);
	virtual ~Shape();*/

	virtual double getArea() const = 0; //abstract method allowing polymorphism to calculate area of shape
	virtual double getPerim() const = 0; //abstract method allowing polymorphism to calculate perimiter of shape

private:
	//Point ancor;
};

//Shape::Shape() {
//	//ancor.setX(0);
//	//ancor.setY(0);
//}
//
//Shape::Shape(const Shape &s) {
//	//ancor = s.ancor;
//}
//
//const Shape &Shape::operator=(const Shape &s) {
//	//ancor = s.ancor;
//	return *this;
//}
//
//Shape::~Shape() {
//
//}

/////////////////////////////////////////////////////////////////////////////////////////

class Polygon : public Shape { //abstract class polygon, son of shape
public:
	/*Polygon();
	Polygon(const Polygon &p);
	const Polygon &operator=(const Polygon &p);
	virtual ~Polygon();*/

private:

};

/////////////////////////////////////////////////////////////////////////////////////////

class Rectangle : public Polygon { //son of polygon
public:
	Rectangle(Point, Point); //Rectangle constructor
	Rectangle(const Rectangle &r); //Rectangle copy constructor
	const Rectangle &operator=(const Rectangle &r); //Rectangle = Rectangle operator overloading
	virtual ~Rectangle(); //Rectangle distructor, virtual alowing polymorphysm

	double getArea() const; //area of Rectangle
	double getPerim() const; //perimiter of Rectangle

private:
	Point b_left, t_right; //b_left - bottom left corner of Rectangle, t_right - top right corner of Rectangle
	int height, width; //height, width of Rectangle
};

Rectangle::Rectangle(Point bl, Point tr) {
	b_left = bl; //set corners
	t_right = tr;

	height = b_left.getX() - t_right.getX(); //claculate height
	if (height < 0)
		height *= -1; //absolute value for size
	width = b_left.getY() - t_right.getY(); //calculate width
	if (width < 0)
		width *= -1; //absolute value for size
}

Rectangle::Rectangle(const Rectangle &r) {
	b_left = r.b_left; //copy corners
	t_right = r.t_right;
}

const Rectangle &Rectangle::operator=(const Rectangle &r) {
	b_left = r.b_left; //copy corners
	t_right = r.t_right;
	return *this; //return refrence to itself
}

Rectangle::~Rectangle() {
	//no memmory to be freed
}


double Rectangle::getArea() const {
	return height*width; //return area
}

double Rectangle::getPerim() const {
	return 2 * (height + width); //return perimiter
}

/////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Polygon {
public:
	Triangle(Point, Point, Point); //Triangle constructor
	Triangle(const Triangle &t); //Triangle copy constructor
	const Triangle &operator=(const Triangle &t); // Triangle = Triangle opertor overloading
	virtual ~Triangle(); //Triangle distructor

	double getArea() const; //area of Triangle
	double getPerim() const; //perimiter of Triangle
private:
	Point a, b, c; //a,b,c ancors of Triangle
	double ab, bc, ca; //lengsth of Triangle edge
	double lng(Point, Point); //method to calculate edge length
};

Triangle::Triangle(Point aP, Point bP, Point cP) {
	a = aP; //set ancors
	b = bP;
	c = cP;

	ab = lng(a, b); //claculate length of edges
	bc = lng(b, c);
	ca = lng(c, a);
}

Triangle::Triangle(const Triangle &t) {
	a = t.a; //copy ancors
	b = t.b;
	c = t.c;

	ab = t.ab; //copy length of edges
	bc = t.bc;
	ca = t.ca;
}

const Triangle &Triangle::operator=(const Triangle &t) {
	a = t.a; //copy ancors
	b = t.b;
	c = t.c;

	ab = t.ab; //copy length of edges
	bc = t.bc;
	ca = t.ca;

	return *this; //return refrence to itself
}

Triangle::~Triangle() {
	//no memmory to be freed
}


double Triangle::lng(Point a, Point b) {
	int x, y;
	double lng;
	x = a.getX() - b.getX();
	y = a.getY() - b.getY();
	x *= x;
	y *= y;
	lng = sqrt(x + y);
	return lng; //calculate length of edge using pitagoras c^2=a^2+b^2
}


double Triangle::getArea() const {
	double ret;
	ret = (ab + bc + ca);
	ret *= (ab + bc - ca);
	ret *= (ab - bc + ca);
	ret *= (-ab + bc + ca);
	ret = 0.25*sqrt(ret);
	return ret; //return area using formula: 0.25*sqrt((a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c))
}

double Triangle::getPerim() const {
	return ab + bc + ca; //return perimiter
}


/////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Shape {
public:
	Circle(Point, int); //Circle constructor
	Circle(const Circle &c); //Circle copy constructor
	const Circle &operator=(const Circle &c); //Circle = Circle operator overloading
	virtual ~Circle(); //Circle distructor

	double getArea() const; //area of Circle
	double getPerim() const; //perimiter of Circle
private:
	Point o; //Circle center
	int radius; //Circle radius
	const double pi = 3.14159265359; //value of pai
};

Circle::Circle(Point c, int r) {
	o = c; //set center
	radius = r; //set radius
}

Circle::Circle(const Circle &c) {
	o = c.o; //copy center 
	radius = c.radius; //copy radius
}

const Circle &Circle::operator=(const Circle &c) {
	o = c.o; //copy center
	radius = c.radius; //copy radius
	return *this; //return refrence to itself
}

Circle::~Circle() {
	//no memmory to be freed
}


double Circle::getArea() const {
	return pi*radius*radius; //return area
}

double Circle::getPerim() const {
	return 2 * pi*radius; //return perimiter
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