#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////

class sqr {
public:
	sqr();
	void setSqr(int user_x, int user_y, int user_length);
	void printSqr() const;
	int sqrArea() const;
	bool inSqr(int user_x, int user_y) const;
	~sqr();
private:
	int x;
	int y;
	int length;
};

sqr::sqr() {
	x = 0;
	y = 0;
	length = 0;
}

void sqr::setSqr(int user_x, int user_y, int user_length) {
	x = user_x;
	y = user_y;
	length = user_length < 1 ? 0 : user_length;
}

void sqr::printSqr() const {
	if (length)
		cout << "square at " << x << "," << y << " side length: " << length << endl;
	else
		cout << "no square was defined" << endl;
}

int sqr::sqrArea() const {
	return length*length;
}

bool sqr::inSqr(int user_x, int user_y) const {
	int sx = user_x - x;
	int sy = user_y - y;
	if (sx < length && sx > 0 && sy < length && sy >0)
		return true;
	else
		return false;
}

sqr::~sqr() {

}

////////////////////////////////////////////////////////////////////

void getCoor(int &x, int &y) {
	cout << "enter x,y coordinates: ";
	cin >> x >> y;
}

void getLen(int &length) {
	cout << "enter length: ";
	do {
		cin >> length;
		if (length < 1)
			cout << "you must enter a positive integer for length" << endl;
	} while (length < 1);
}

////////////////////////////////////////////////////////////////////

void tarigl_3() {
	sqr s1;
	int x, y, length;
	getCoor(x, y);
	getLen(length);

	s1.setSqr(x, y, length);

	s1.printSqr();

	cout << "square are is: " << s1.sqrArea() << endl;

	getCoor(x, y);
	cout << "the coordinate " << x << "," << y << " ";
	cout << (s1.inSqr(x, y) ? "" : "not ");
	cout << "in the square" << endl << endl;

	system("pause");
}



