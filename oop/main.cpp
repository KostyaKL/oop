#include <iostream>
#include "headers.h"

using namespace std;

class mainScreen {
public:
	mainScreen() {
		
		on = 1;
		while (on) {
			on = getInput();
		}
	}

	void printMenu() const {
		system("cls");
		cout << "Welcome to select pgae!" << endl <<
			"-----------------------" << endl <<
			"Choose your option:" << endl <<
			"1.1 - hagasha 1" << endl <<
			endl <<
			"2.1 - targil 1-2" << endl <<
			"2.3 - targil 3" << endl <<
			"2.4 - targil 4" << endl<<
			endl <<
			"Exit - Quit" << endl <<
			"Enter your choise: ";
	}
	int getInput() {
		printMenu();
		cin >> input;
		if (!strcmp(input, "2.1")) {
			system("cls");
			targil_1_2();
		}
		else if (!strcmp(input, "2.3")) {
			system("cls");
			tarigl_3();
		}
		else if (!strcmp(input, "2.4")) {
			system("cls");
			targil_4();
		}
		else if (!strcmp(input, "quit") || !strcmp(input, "0")) {
			return 0;
		}
		else {
			cout << "You have entered inavlid input" << endl << endl;
			system("pause");
			getInput();
		}
		return 1;
	}
	~mainScreen() {
		cout <<endl << "you have exited the program" << endl << endl;
		system("pause");
	}
private:
	char input[5] = "";
	int on;
};

void main() {
	mainScreen A;
}