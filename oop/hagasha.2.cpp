/*
Assigned by:
Student 1: Melinda Levi ID:201310356
Student 2: Kostya Lokshin ID:310765821

Lecturer: Dr. Vladimir Nodelman  61307-1
Targil: Dr. Leonid Kugel 661307-1 / Motti Rosso 661307-2
*/

#include "headers.h"
#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int r, int c);
	const Matrix &operator=(const Matrix &m2);
	~Matrix();

	Matrix &operator+(Matrix &m2);
	Matrix &operator*(Matrix &m2);
	Matrix &operator*(int num);
	Matrix &operator-();

	int *operator[](int num);

	friend ostream &operator<<(ostream &, const Matrix &m);
private:
	int *mat;
	int row, col, size;
};

Matrix::Matrix() {
	row = 0;
	col = 0;
	size = row*col;
	mat = NULL;

}
Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	size = row*col;
	mat = new int[size];
	for (int i = 0;i < size;i++) {
		mat[i] = 0;
	}
}
const Matrix &Matrix::operator=(const Matrix &m2) {
	row = m2.row;
	col = m2.col;
	size = m2.size;
	if (mat)
		delete[] mat;
	mat = new int[size];
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			mat[i*row + j] = m2.mat[i*row + j];
		}
	}
	return *this;
}
Matrix::~Matrix() {
	delete[] mat;
}

Matrix &Matrix::operator+(Matrix &m2) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			mat[i*row + j] += m2.mat[i*row + j];
		}
	}
	return *this;
}
Matrix &Matrix::operator*(Matrix &m2) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			mat[i*row + j] *= m2.mat[i*row + j];
		}
	}
	return *this;
}
//Matrix &Matrix::operator*(int num) {
//
//}
Matrix &Matrix::operator-() {
	for (int i = 0;i < size;i++) {
		mat[i] *= -1;
	}
	return *this;
}

int *Matrix::operator[](int c) {

	return &mat[r*row];
}

ostream &operator<<(ostream &output, const Matrix &m) {
	for (int i = 0;i < m.row;i++) {
		for (int j = 0;j < m.col;j++) {
			output << m.mat[i*m.row + j] << "\t";
		}
		output << endl;
	}
	return output;
}

void hagasha_2() {
	Matrix m(2, 2);
	//m[0][0] = 2;
	//m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrix s = -m;
	cout << m << endl << s << endl;
	//m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	//cout << s[1][1] << endl;

	system("pause");
}