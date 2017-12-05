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

class Matrix {
public:
	Matrix(int r, int c); //dufault constructor
	Matrix(const Matrix &m2); //copy constructor
	const Matrix &operator=(const Matrix &m2); // = operator overloading
	virtual ~Matrix(); //distructor

	Matrix operator+(const Matrix &m2) const; // mat + mat operator overloading
	
	Matrix operator*(int num); //mat * integer * operator overloading
	Matrix operator*(const Matrix &m2); // mat * mat operator overloading
	friend Matrix operator*(int num, const Matrix &m2); //integer * mat operator overloading

	Matrix operator-(); //-matrix operator overloading
	Matrix operator-(const Matrix &m2); //mat - mat operator overloading

	int *operator[](int c) const; //mat[][] operator overloading

	friend ostream &operator<<(ostream &, const Matrix &m); //cout << mat operator overloading
private:
	int *mat; //arry of integer to store the matrix
	int row, col, size; //row - number of rows in matrix, col = number of columns in matrix, size - row*col
};

/////////////////////////////////////////////////////////////////////////////////////////

Matrix::Matrix(int r = 1, int c = 1) {
	row = r > 0 ? r : 1; //assure the matrix is at least of size 1x1
	col = c > 0 ? c : 1;
	size = row*col;
	mat = new int[size]; //create new array to store matrix
	for (int i = 0; i < size;i++) { //zeroize the matrix
		mat[i] = 0;
	}
}

Matrix::Matrix(const Matrix &m2) {
	row = m2.row; //copy the size of matrix
	col = m2.col;
	size = row*col;
	mat = new int[size];
	for (int i = 0;i < size;i++) {
		mat[i] = m2.mat[i]; //copy matrix items
	}
}

const Matrix &Matrix::operator=(const Matrix &m2) {
	if (&m2 != this) {//check if the operands are the same matrix
		if (size != m2.size) { //check if matrix to copy is the same size
			size = m2.size; //copy size
			if (mat != NULL) //check if the memmory for the arry needs to be freed
				delete[] mat;
			mat = new int[size];
		}
		row = m2.row; //copy matrix size
		col = m2.col;
		for (int i = 0;i < size;i++) {
			mat[i] = m2.mat[i]; //copy matrix items
		}
	}
	return *this; //return the adress of the matrix itself (left operand mat=mat)
}

Matrix::~Matrix() {
	if (mat!=NULL) //check if mat is net freed
		delete[] mat; //free memmory that was allocated for mat
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix Matrix::operator+(const Matrix &m2) const { //both operand matrix must be the same size
	Matrix tmp(row, col); //matrix to be returned in the size of the operand matrix
	for (int i = 0;i < size;i++) {
		tmp.mat[i] = mat[i] + m2.mat[i]; //set the new matrix items as the sum of both operands matrixs
	}
	return tmp; //return new matrix
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix Matrix::operator*(int num) {
	Matrix tmp; //matrix to be returned
	tmp = *this; //copy the left operand matrix to tmp
	for (int i = 0;i < size;i++) {
		tmp.mat[i] *= num; //multiply each matrix item by num
	}
	return tmp; //return new matrix
}

Matrix Matrix::operator*(const Matrix &m2) { //operand matrix must have m1.row = m2.col or m1.col = m2.row
	Matrix tmp(row, m2.col); //matrix to be returned in the size of the outcome matrix
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < m2.col;j++) {
			for (int k = 0;k < row;k++) {
				tmp.mat[i*row + j] += mat[k*row + j] * m2.mat[i*row + k]; //perform matrix multiplication algorithm
			}
		}
	}
	return tmp; //return new matrix
}

Matrix operator*(int num, const Matrix &m2) { //friend function to Matrix class
	Matrix tmp; //matrix to be returned
	tmp = m2; //copy the right operand matrix to tmp
	for (int i = 0;i < tmp.size;i++) {
		tmp.mat[i] *= num; //multiply each matrix item by num
	}
	return tmp; //return new matrix
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix Matrix::operator-() {
	Matrix tmp; //matrix to be returned
	tmp = *this*(-1); //multiply the operand matrix by -1
	return tmp; //return new matrix
}

Matrix Matrix::operator-(const Matrix &m2) { //both operand matrix must be the same size
	Matrix tmp(row,col); //matrix to be returned in the size of the operand matrix
	for (int i = 0;i < size;i++)
	{
		tmp.mat[i] = mat[i] - m2.mat[i]; //set the new matrix items as the substruction of rigth operand matrix from left
	}
	return tmp; //return new matrix
}

/////////////////////////////////////////////////////////////////////////////////////////

int *Matrix::operator[](int c) const { //access specific item in matrix by row and col index
	return &mat[c*row]; //return the adress of item in a specific location in the matrix
}

/////////////////////////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &output, const Matrix &m) {
	for (int i = 0;i < m.row;i++) {
		for (int j = 0;j < m.col;j++) {
			output << m.mat[i*m.row + j] << "\t"; //print the matrix to output stream
		}
		output << endl;
	}
	return output; //return output stream to cout
}

/////////////////////////////////////////////////////////////////////////////////////////

void hagasha_2() {
	Matrix m(2, 2);
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrix s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;

	cout << endl;
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////