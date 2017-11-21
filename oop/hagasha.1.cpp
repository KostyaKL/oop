/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Dr. Vladimir Nodelman  61307-1
Targil: Dr. Leonid Kugel 661307-1 / Motti Rosso 661307-2
*/

#include "headers.h"
#include <iostream>
using namespace std;

class Point {
public:
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void print() const;
private:
	int x, y;
};

Point::Point(int x=0, int y=0) {
	setX(x);
	setY(y);
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setX(int x) {
	this->x = x >= 0 ? x : 0;
}

void Point::setY(int y) {
	this->y = y >= 0 ? y : 0;
}

void Point::print() const {
	cout << "point coordinates: (" << x << "," << y << ")" << endl;
}


class Circle {
public:
	Circle(int x, int y, int r, int color);
	int getColor() const;
	void setColor(int color);
	bool contains(const Point &p) const;
	void print() const;
private:
	const Point center;
	int radius, color;
};

Circle::Circle(int x=0, int y=0, int r=1, int color=0):center(x,y) {
	radius = r > 0 ? r : 1;
	setColor(color);

}

int Circle::getColor() const {
	return color;
}

void Circle::setColor(int color) {
	this->color = color >= 0 ? color : 0;
}

bool Circle::contains(const Point &p) const {
	int a, b, c;
	a = p.getX() - center.getX();
	b = p.getY() - center.getY();
	a *= a;
	b *= b;
	c = a + b;
	c = sqrt(c);
	return c < radius ? true : false;
}

void Circle::print() const {
	cout << "Circle center=(" << center.getX() << "," << center.getY() << ") radius=" << radius << " color=" << color << endl;
}

class Collection {
public:
	Collection(int radius, int width, int height, int color);
	~Collection();
	Circle& getCircleAt(const Point &p);
	void print() const;
private:
	int count;
	Circle **circles;
};

Collection::Collection(int radius = 1, int width = 1, int height = 1, int color = 0) {
	int x, y;
	x = 0;
	y = 0;
	height = height > 0 ? height : 1;
	width = width > 0 ? width : 1;
	count = height*width;
	circles = new Circle*[count];

	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			circles[i*width + j] = new Circle(x, y, radius, color);
			x += 2 * radius;
		}
		x = 0;
		y += 2 * radius;
	}
}

Collection::~Collection() {
	for (int i = 0;i < count;i++) {
		delete circles[i];
	}
	delete[] circles;
}

Circle &Collection::getCircleAt(const Point &p) {
	for (int i = 0;i < count;i++) {
		if (circles[i]->contains(p)) {
			return *circles[i];
		}
	}
}

void Collection::print() const {
	for (int i = 0;i < count;i++) {
		circles[i]->print();
	}
}

void hagasha_1() {
	Collection g(4, 3, 2, 0);
	cout << "-- before setColor(2) --" << endl;
	g.print();
	Point p(5, 1);
	g.getCircleAt(p).setColor(2);
	cout << "-- after setColor(2) --" << endl;
	g.print();

	system("pause");
}