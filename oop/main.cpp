#include <iostream>
#include "targil.1-2.cpp"

using namespace std;

class mainScreen {
public:
	mainScreen() {
		printMenu();
		getInput(0);
	}

	void printMenu() {
		system("cls");
		cout << "Welcome to select pgae!" << endl <<
			"-----------------------" << endl <<
			"Choose your option:" << endl <<
			"1.1 - hagasha 1" << endl <<
			endl <<
			"2.1 - targil 1-2" << endl <<
			endl <<
			"Exit - Quit" << endl <<
			"Enter your choise: ";
	}
	void getInput(int flag) {
		if (flag) {
			printMenu();
		}
		cin >> input;
		if (!strcmp(input, "2.1")) {
			system("cls");
			targil_1_2();
		}
		else if (!strcmp(input, "quit") || !strcmp(input, "0")) {
			exit(0);
		}
		else {
			cout << "You have entered inavlid input" << endl << endl;
			system("pause");
			getInput(1);
		}
	}
	~mainScreen() {
		cout << "you have exited the program" << endl << endl;
		system("pause");
	}
private:
	char input[5] = "";
};

void main() {
	mainScreen A;
}