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

class Node {
public:
	Node();
	~Node();
private:
	void num;
	Node * father;
	Node *left;
	Node *right;
};

/////////////////////////////////////////////////////////////////////////////////////////

Node::Node() {

}

Node::~Node() {

}

/////////////////////////////////////////////////////////////////////////////////////////

class Tree {
public:
	Tree();
	~Tree();

	void insert(void);
	bool exist(void);
	int size();

	friend ostream &operator<<(ostream &out, const Tree &tree);
private:
	Node * root;
};

/////////////////////////////////////////////////////////////////////////////////////////

Tree::Tree() {

}

Tree::~Tree()
{

}

void Tree::insert(void) {

}

bool Tree::exist(void) {

}

int Tree::size() {

}

ostream &operator<<(ostream &out, const Tree &tree) {

}

/////////////////////////////////////////////////////////////////////////////////////////

void hagasha_4() {
	int n;
	double f;
	void q;

	Tree tree;
	cout << "enter integer: ";
	cin >> n;
	cout << "enter double: ";
	cin >> f;

	tree.insert(n);
	tree.insert(f);

	cout << "the size of the tree is " << tree.size() << endl;

	cout << "enter a number you want to search: ";
	cin >> q;

	if (tree.exist(q))
		cout << q << " is found in tree" << endl;
	else
		cout << q << " is NOT found in tree" << endl;

	cout << tree;

	cout << endl;
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////