#include "headers.h"
#include <iostream>
using namespace std;

class circle {
public:
	circle();
	circle(double in_x = 0, double in_y = 0, double in_r = 0);
	~circle();
	const circle &operator=(const circle &op) ;

	void set(double in_x, double in_y, double in_r);
	void get(double &out_x, double &out_y, double &out_r) const;

	double area() const;
	double diam() const;

private:
	double x;
	double y;
	double r;
	const double pi = 3.14;
};

circle::circle() {
	x = 0;
	y = 0;
	r = 0;
}
circle::circle(double in_x = 0, double in_y = 0, double in_r = 0) {

}
circle::~circle() {

}
const circle &circle::operator=(const circle &op) {
	x = op.x;
	y = op.y;
	r = op.r;
	return *this;
}

void circle::set(double in_x, double in_y, double in_r) {
	x = in_x;
	y = in_y;
	r = in_r;
}
void circle::get(double &out_x, double &out_y, double &out_r) const {
	out_x = x;
	out_y = y;
	out_r = r;
}

double circle::area() const {
	return(pi*r*r);
}
double circle::diam() const {
	return(2 * pi*r);
}

void targil_4() {

}