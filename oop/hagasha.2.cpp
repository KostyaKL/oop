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
	Matrix(int r, int c);
	Matrix(const Matrix &m2);
	const Matrix &operator=(const Matrix &m2);
	~Matrix();

	Matrix &operator+(const Matrix &m2) const;
	
	Matrix &operator*(int num);
	Matrix &operator*(const Matrix &m2);
	friend Matrix &operator*(int num, const Matrix &m2);

	Matrix &operator-();
	Matrix &operator-(const Matrix &m2);

	int *operator[](int c) const;

	friend ostream &operator<<(ostream &, const Matrix &m);
private:
	int *mat;
	int row, col, size;
};

/////////////////////////////////////////////////////////////////////////////////////////

Matrix::Matrix(int r = 1, int c = 1) {
	row = r > 0 ? r : 1;
	col = c > 0 ? c : 1;
	size = row*col;
	mat = new int[size];
	for (int i = 0; i < size;i++) {
		mat[i] = 0;
	}
}

Matrix::Matrix(const Matrix &m2) {
	row = m2.row;
	col = m2.col;
	size = row*col;
	mat = new int[size];
	for (int i = 0;i < size;i++) {
		mat[i] = m2.mat[i];
	}
}

const Matrix &Matrix::operator=(const Matrix &m2) {
	if (&m2 != this) {
		if (size != m2.size) {
			size = m2.size;
			if (mat!=NULL)
				delete[] mat;
			mat = new int[size];
		}
		row = m2.row;
		col = m2.col;
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				mat[i*row + j] = m2.mat[i*row + j];
			}
		}
	}
	return *this;
}

Matrix::~Matrix() {
	if (mat!=NULL)
		delete[] mat;
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix &Matrix::operator+(const Matrix &m2) const {
	Matrix *tmp;
	tmp = new Matrix(row,col);
	for (int i = 0;i < size;i++) {
		tmp->mat[i] = mat[i] + m2.mat[i];
	}
	return *tmp;
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix &Matrix::operator*(int num) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			mat[i*row + j] *= num;
		}
	}
	return *this;
}

Matrix &Matrix::operator*(const Matrix &m2) {
	int *tmp;
	tmp = new int[row * m2.col];
	for (int i = 0; i < row*m2.col;i++)
		tmp[i] = 0;
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			for (int k = 0;k < row;k++) {
				tmp[i*row + j] += mat[k*row + j] * m2.mat[i*row + k];
			}
		}
	}
	mat = tmp;
	return *this;
}

Matrix &operator*(int num, const Matrix &m2) {
	Matrix *tmp;
	tmp = new Matrix;
	*tmp = m2;
	for (int i = 0;i < tmp->row;i++) {
		for (int j = 0;j < tmp->col;j++) {
			tmp->mat[i*tmp->row + j] *= num;
		}
	}
	return *tmp;
}

/////////////////////////////////////////////////////////////////////////////////////////

Matrix &Matrix::operator-() {
	Matrix *tmp;
	tmp = new Matrix;
	*tmp = *this;
	*tmp*(-1);
	return *tmp;
}

Matrix &Matrix::operator-(const Matrix &m2) {
	for (int i = 0;i < size;i++)
	{
		mat[i] = mat[i] - m2.mat[i];
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////

int *Matrix::operator[](int c) const {
	return &mat[c*row];
}

/////////////////////////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &output, const Matrix &m) {
	for (int i = 0;i < m.row;i++) {
		for (int j = 0;j < m.col;j++) {
			output << m.mat[i*m.row + j] << "\t";
		}
		output << endl;
	}
	return output;
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