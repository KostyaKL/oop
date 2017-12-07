///*
//Assigned by:
//Student 1: Melinda Levi ID:201310356
//Student 2: Kostya Lokshin ID:310765821
//
//Lecturer: Dr. Vladimir Nodelman  61307-1
//Targil: Dr. Leonid Kugel 661307-1 / Motti Rosso 661307-2
//*/
//
//#include "headers.h"
//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	Point(int x, int y);
//	int getX() const;
//	int getY() const;
//	void setX(int x);
//	void setY(int y);
//	void print() const;
//private:
//	int x, y;
//};
//
//Point::Point(int x, int y) { //point constructor
//	setX(x); //set x using public function of class point setX()
//	setY(y); //set y using public function of class point setY()
//}
//
//int Point::getX() const { //return the value of x
//	return x;
//}
//
//int Point::getY() const { //return the value of y
//	return y;
//}
//
//void Point::setX(int x) { //set x
//	this->x = x >= 0 ? x : 0; //chek if x is not negative, if so set it to 0, set the value of argument x to x of class point 
//}
//
//void Point::setY(int y) { //set y
//	this->y = y >= 0 ? y : 0; //chek if y is not negative, if so set it to 0, set the value of argument y to y of class point 
//}
//
//void Point::print() const { //print x and y
//	cout << "point coordinates: (" << x << "," << y << ")" << endl;
//}
//
//
//class Circle {
//public:
//	Circle(int x, int y, int r, int color);
//	int getColor() const;
//	void setColor(int color);
//	bool contains(const Point &p) const;
//	void print() const;
//private:
//	const Point center;
//	int radius, color;
//};
//
//Circle::Circle(int x, int y, int r, int color):center(x,y) { //circle constructor, set center in preconstructor as it's a constant of class point
//	radius = r > 0 ? r : 1; //check the radius is a valid value and set it, if not set it to 1
//	setColor(color); //set color using public method of class circle
//
//}
//
//int Circle::getColor() const { //return the value of color
//	return color;
//}
//
//void Circle::setColor(int color) { //set color
//	this->color = color >= 0 ? color : 0; //chek if color is not negative, if so set it to 0, set the value of argument color to color of class circle 
//}
//
//bool Circle::contains(const Point &p) const { //check if a point is inside a circle using pitagoras equation c^2 = a^2 + b^2
//	int a, b, c; //a-base, b-height, c-distance from center
//	a = p.getX() - center.getX(); //base = x of point - x of center
//	b = p.getY() - center.getY(); //height = y of point - y of center
//	a *= a; //pow(a)
//	b *= b; //pow(b)
//	c = a + b; //c^2 = a^2 + b^2
//	c = sqrt(c); //get the distance from point to center
//	return c < radius ? true : false; //if the distance is grater than the radius the the point is outside the circle, otherwise it is inside
//}
//
//void Circle::print() const { //print circle parameters
//	cout << "Circle center=(" << center.getX() << "," << center.getY() << ") radius=" << radius << " color=" << color << endl;
//}
//
//class Collection {
//public:
//	Collection(int radius, int width, int height, int color);
//	~Collection();
//	Circle& getCircleAt(const Point &p);
//	void print() const;
//private:
//	int count;
//	Circle **circles;
//};
//
//Collection::Collection(int radius, int width, int height, int color) { //collection constructor
//	int x, y; //x,y - center of circles
//	x = 0; 
//	y = 0;
//	height = height > 0 ? height : 1; //check that height is valid value, if not set it to 1
//	width = width > 0 ? width : 1; //check that width is valid value, if not set it to 1
//	radius = radius > 0 ? radius : 1; //check that radius is valid value, if not set it to 1
//	count = height*width; //set count - number of circles in the collection
//	circles = new Circle*[count]; //allocate memmory to an array of pointers to circle calss members
//
//	for (int i = 0;i < height;i++) {
//		for (int j = 0;j < width;j++) {
//			circles[i*width + j] = new Circle(x, y, radius, color); // initialize circles members as a matrix
//			x += 2 * radius;
//		}
//		x = 0;
//		y += 2 * radius;
//	}
//}
//
//Collection::~Collection() { //collection destructor
//	for (int i = 0;i < count;i++) { //free the memmory allocated to each item in the array
//		delete circles[i];
//	}
//	delete[] circles; //free the memmory allocated to the array
//}
//
//Circle &Collection::getCircleAt(const Point &p) { //get the circle in the collection that the point is in it
//	for (int i = 0;i < count;i++) {
//		if (circles[i]->contains(p)) { //check every circle until found using public functio of class circle contains(const point &)
//			return *circles[i]; //return refrence to found circle
//		}
//	}
//}
//
//void Collection::print() const {
//	for (int i = 0;i < count;i++) {
//		circles[i]->print(); //print all the circles in the collection
//	}
//}
//
void hagasha_1() {
//	Collection g(4, 3, 2, 0);
//	cout << "-- before setColor(2) --" << endl;
//	g.print();
//	Point p(5, 1);
//	g.getCircleAt(p).setColor(2);
//	cout << "-- after setColor(2) --" << endl;
//	g.print();
//
//	system("pause");
//	//return 0;
}