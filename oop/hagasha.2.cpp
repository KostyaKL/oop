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
	Matrix(int r, int c);
	Matrix(const Matrix &m2);
	const Matrix &operator=(const Matrix &m2);
	~Matrix();

	friend const Matrix &operator+(const Matrix &m1, const Matrix &m2);
	friend const Matrix &operator+(int num, const Matrix &m2);
	friend const Matrix &operator+(const Matrix &m2, int num);

	friend const Matrix &operator*(const Matrix &m1, const Matrix &m2);
	friend const Matrix &operator*(int num, const Matrix &m2);
	friend const Matrix &operator*(const Matrix &m2, int num);

	Matrix &operator-();
	friend const Matrix &operator-(const Matrix &m1, const Matrix &m2);

	int *operator[](int c) const;

	friend ostream &operator<<(ostream &, const Matrix &m);
private:
	int *mat;
	int row, col, size;
};

Matrix::Matrix(int r = 0, int c = 0) {
	row = r;
	col = c;
	size = row*col;
	if (size){
		mat = new int[size];
		for (int i = 0; i < size;i++) {
			mat[i] = 0;
		}
}
	else
		mat = NULL;

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
	row = m2.row;
	col = m2.col;
	size = m2.size;
	int *temp;
	
	temp = new int[size];
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			temp[i*row + j] = m2.mat[i*row + j];
		}
	}
	if (mat)
		delete[] mat;
	mat = temp;
	return *this;
}
Matrix::~Matrix() {
	if (mat)
		delete[] mat;
}

const Matrix &operator+(const Matrix &m1, const Matrix &m2) {
	if (m1.row != m2.row || m1.col != m2.col)
		return NULL;
	Matrix *tmp;
	tmp = new Matrix(m1.col, m1.row);
	for (int i = 0;i < tmp->size;i++)
	{
		tmp->mat[i] = m1.mat[i] + m2.mat[i];
	}
	return *tmp;
}
const Matrix &operator+(int num, const Matrix &m2) {
	Matrix *tmp;
	tmp = new Matrix;
	*tmp = m2;
	for (int i = 0;i < tmp->row;i++) {
		for (int j = 0;j < tmp->col;j++) {
			tmp->mat[i*tmp->row + j] += num;
		}
	}
	return *tmp;
}
const Matrix &operator+(const Matrix &m2, int num) {
	Matrix *tmp;
	tmp = new Matrix;
	*tmp = m2;
	for (int i = 0;i < tmp->row;i++) {
		for (int j = 0;j < tmp->col;j++) {
			tmp->mat[i*tmp->row + j] += num;
		}
	}
	return *tmp;
}
const Matrix &operator*(const Matrix &m1, const Matrix &m2) {
	if (m1.row != m2.col)
		return NULL;
	Matrix *tmp;
	tmp = new Matrix(m1.row, m2.col);
	for (int i = 0;i < tmp->row;i++) {
		for (int j = 0;j < tmp->col;j++) {
			for (int k = 0;k < tmp->row;k++) {
				tmp->mat[i*tmp->row + j] += m1.mat[k*tmp->row + j]*m2.mat[i*tmp->row + k];
			}
		}
	}
	return *tmp;
}

const Matrix &operator*(int num, const Matrix &m2) {
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

const Matrix &operator*(const Matrix &m2, int num) {
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

Matrix &Matrix::operator-() {
	Matrix *tmp;
	int *m;
	tmp = new Matrix;
	tmp->row = row;
	tmp->col = col;
	tmp->size = size;
	m = new int[size];
	for (int i = 0;i < size;i++) {
		m[i] = mat[i] * -1;
	}
	tmp->mat = m;
	return *tmp;
}
const Matrix &operator-(const Matrix &m1, const Matrix &m2) {
	if (m1.row != m2.row || m1.col != m2.col)
		return NULL;
	Matrix *tmp;
	tmp = new Matrix(m1.col, m1.row);
	for (int i = 0;i < tmp->size;i++)
	{
		tmp->mat[i] = m1.mat[i] - m2.mat[i];
	}
	return *tmp;
}

int *Matrix::operator[](int c) const {
	return &mat[c*row];
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
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrix s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * -m * m * 2 - s;
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;

	system("pause");
}