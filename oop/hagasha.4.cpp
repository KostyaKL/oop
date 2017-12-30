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

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T> class Node
{
public:
	Node(T);                                                    // constructor
	T getData();                                                // get data
	Node<T>* getLeft() const;                                   // get left
	Node<T>* getRight() const;                                  // get right
	void setLeft(Node<T> *);                                    // set left
	void setRight(Node<T> *);                                   // set right

private:
	T data;                                                     // data
	Node *left;                                                 // pointer to the left son
	Node *right;                                                // pointer to the right son
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // constructor
Node<T>::Node(T data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // get data
T Node<T>::getData()
{
	return this->data;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // get left
Node<T>* Node<T>::getLeft() const
{
	return this->left;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // get right
Node<T>* Node<T>::getRight() const
{
	return this->right;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // set left 
void Node<T>::setLeft(Node<T> *nodeT)
{
	this->left = nodeT;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // set right
void Node<T>::setRight(Node<T> *nodeT)
{
	this->right = nodeT;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T> class Tree
{
public:
	Tree() { this->root = NULL; };                              // constructor
	Node<T> * getRoot() const;                                  // get root
	void insert(T);                                             // insert new data
	bool exist(T) const;                                        // find data in tree
	int size() const;                                           // size of tree
	~Tree();                                                    // destructor

	friend ostream & operator<< (ostream &, const Tree<T> &);   // operatot <<
	void printTree();                                           // print tree
	void printTree(Node<T> *);                                  // print tree

private:
	Node<T> *root;                                              // pointer to the tree
	void insert(Node<T> *, Node<T> *);                          // insert node
	bool exist(Node<T> *, T) const;                             // find data in tree - if not found at the first node 
	int size(Node<T> *) const;                                  // size of tree - if is not empty
	void deleteTree(Node<T> *);                                 // delete tree - if is not empty

};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Node<T>* Tree<T>::getRoot() const                               // get root
{
	return this->root;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // insert node
void Tree<T>::insert(T data)
{
	Node<T> *temp = new Node<T>(data);
	if (!this->root)
	{
		this->root = temp;
	}
	else
		this->insert(this->root, temp);
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // insert new data
void Tree<T>::insert(Node<T> *theNode, Node<T> *temp)
{
	if (temp->getData() < theNode->getData())
	{
		if (!theNode->getLeft())
			theNode->setLeft(temp);
		else
			insert(theNode->getLeft(), temp);
	}
	else
	{
		if (!theNode->getRight())
			theNode->setRight(temp);
		else
			insert(theNode->getRight(), temp);
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // size of tree
int Tree<T>::size() const
{
	if (!this->root)
		return 0;
	else
		size(this->getRoot());
}

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // size of tree - if not empty
int Tree<T>::size(Node<T> *nodeT) const
{
	if (!nodeT)
		return 0;
	else
		return (size(nodeT->getLeft()) + 1 + size(nodeT->getRight()));
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // find data in tree
bool Tree<T>::exist(T data) const
{
	if (this->root->getData() == data)
		return true;
	else
		this->exist(this->root, data);
}

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // find data in tree
bool Tree<T>::exist(Node<T> *nodeT, T data) const
{
	if (nodeT->getData() == data)
		return true;

	Node<T> *temp = NULL;
	if (nodeT->getData() > data)
		temp = nodeT->getLeft();
	else
		temp = nodeT->getRight();

	if (temp)
		return exist(temp, data);
	else
		return false;
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // destructor   
Tree<T>::~Tree()
{
	if (!this->root)
		return;
	else
		deleteTree(this->root);
}

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // delete tree - if is not empty
void Tree<T>::deleteTree(Node<T> *nodeT)
{
	if (!nodeT)
		return;
	deleteTree(nodeT->getRight());
	deleteTree(nodeT->getLeft());
	delete(nodeT);
};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // print tree
void Tree<T>::printTree()
{
	if (!this->root)
		cout << "Empty" << endl;
	else
		printTree(this->root);

};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // print tree
void Tree<T>::printTree(Node<T> *nodeT)
{
	if (!nodeT)
		return;
	else
	{
		printTree(nodeT->getLeft());
		cout << nodeT->getData() << ", ";
		printTree(nodeT->getRight());
	}

};

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>                                              // operator <<
ostream & operator<< (ostream &os, const Tree<T> &tree)
{
	tree.printTree();
	return os;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hagasha_4()
{

	Tree<int> intTree;
	Tree<double> doubTree;

	intTree.insert(42);
	intTree.insert(10);
	intTree.insert(30);
	intTree.insert(17);
	intTree.insert(100);

	cout << "Int tree: ";
	intTree.printTree(intTree.getRoot());
	cout << endl;

	cout << "Size of int tree: " << intTree.size() << endl;
	cout << "Is 17 exist? (0/1)  -  " << intTree.exist(17) << endl;
	cout << "Is 24 exist? (0/1)  -  " << intTree.exist(24) << endl;

	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;

	doubTree.insert(4.2);
	doubTree.insert(1.1);
	doubTree.insert(3.4);
	doubTree.insert(1.7);
	doubTree.insert(10.8);
	doubTree.insert(2.5);

	cout << "Double tree: ";
	doubTree.printTree(doubTree.getRoot());
	cout << endl;


	cout << "Size of double tree: " << doubTree.size() << endl;
	cout << "Is 2.4 exist? (0/1)  -  " << doubTree.exist(2.4) << endl;
	cout << "Is 1.7 exist? (0/1)  -  " << doubTree.exist(1.7) << endl;

	cout << endl;

	system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////

//void hagasha_4() {
//	int n;
//	double f;
//	void q;
//
//	Tree tree;
//	cout << "enter integer: ";
//	cin >> n;
//	cout << "enter double: ";
//	cin >> f;
//
//	tree.insert(n);
//	tree.insert(f);
//
//	cout << "the size of the tree is " << tree.size() << endl;
//
//	cout << "enter a number you want to search: ";
//	cin >> q;
//
//	if (tree.exist(q))
//		cout << q << " is found in tree" << endl;
//	else
//		cout << q << " is NOT found in tree" << endl;
//
//	cout << tree;
//
//	cout << endl;
//	system("pause");
//}

/////////////////////////////////////////////////////////////////////////////////////////