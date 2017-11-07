#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////

class myTime {
public:
	myTime();
	void setTime(int h, int m, int s);
	void printTime();
	~myTime();
private:
	int hours, minutes, seconds;
};

myTime::myTime() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void myTime::setTime(int h, int m, int s) {
	seconds = s % 60;

	m += s / 60 ? s / 60 : 0;
	minutes += m % 60;

	h += m / 60 ? m / 60 : 0;
	hours += h;
}

void myTime::printTime() {
	cout << ((hours < 9) ? ("0") : ("")) << hours << ":"
		<< ((minutes < 9) ? ("0") : ("")) << minutes << ":"
		<< ((seconds < 9) ? ("0") : ("")) << seconds << endl;
}

myTime::~myTime() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

////////////////////////////////////////////////////////////////////

myTime timeClone(const myTime &in) {
	return in;
}

void timeInput(int &h, int &m, int &s) {
	cout << "Enter hour, min, sec: ";
	do {
		cin >> h >> m >> s;
		if (h < 0 || m < 0 || s < 0) {
			cout << "You must enter positive integers for time" << endl << endl;
		}
	} while (h < 0 || m < 0 || s < 0);
}

////////////////////////////////////////////////////////////////////

void targil_1_2() {
	myTime *arr;
	int size;

	cout << "Enter how many values: ";
	do {
		cin >> size;
		if (size < 1) {
			cout << "You must enter a positive integer" << endl << endl;
		}
	} while (size < 1);
	arr = new myTime[size];

	for (int i = 0;i < size;i++) {
		int h, m, s;
		timeInput(h, m, s);
		(arr + i)->setTime(h, m, s);
	}

	for (int i = 0;i < size;i++) {
		(arr + i)->printTime();
	}
	cout << endl;
	system("pause");

	cout << endl << endl;
	myTime in, out;
	int h, m, s;
	timeInput(h, m, s);
	in.setTime(h, m, s);
	out = timeClone(in);
	out.printTime();

	cout << endl;
	system("pause");
	delete[] arr;
}