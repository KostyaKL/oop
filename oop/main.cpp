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
			"1.2 - hagasha 2" << endl <<
			"1.3 - hagasha 3" << endl <<
			"1.4 - hagasha 4" << endl <<
			endl <<
			"2.1 - targil 1-2" << endl <<
			"2.3 - targil 3" << endl <<
			"2.4 - targil 4" << endl <<
			endl <<
			"3 - test" << endl <<
			endl <<
			"Exit - Quit" << endl <<
			"Enter your choise: ";
	}
	int getInput() {
		printMenu();
		cin >> input;
		if (!strcmp(input, "1.1")) {
			system("cls");
			hagasha_1();
		}
		else if (!strcmp(input, "1.2")) {
			system("cls");
			hagasha_2();
		}
		else if (!strcmp(input, "1.3")) {
			system("cls");
			hagasha_3();
		}
		else if (!strcmp(input, "1.3")) {
			system("cls");
			hagasha_4();
		}
		else if (!strcmp(input, "2.1")) {
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
		else if (!strcmp(input, "3")) {
			system("cls");
			test();
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
		//system("pause");
	}
private:
	char input[5] = "";
	int on;
};

void main() {
	mainScreen A;
}