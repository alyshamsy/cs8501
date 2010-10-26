#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(double init_value, int rows, int columns):
init_value(init_value),
rows(rows),
columns(columns) {
	matrix = new double* [rows];
	for(int i = 0; i < rows; i++) {
		matrix[i] = new double[columns];
		for(int j = 0; j < columns; j++)
			matrix[i][j] = init_value;
	}
}

Matrix::~Matrix() {
	for(int i = 0; i < rows; i++) 
		delete [] matrix[i];

	delete [] matrix;
	matrix = NULL;
}

Matrix::Matrix(const Matrix& src):
rows(src.rows), columns(src.columns), matrix(new double*[src.rows])
{
	for(int i = 0; i < rows; ++i) {
		matrix[i] = new double[columns];
		for(int j = 0; j < columns; ++j) {
			matrix[i][j] = src.matrix[i][j];
		}
	}
}

bool Matrix::is_matrix_square() {
	if(rows == columns)
		return true;
	else
		return false;
}

Matrix Matrix::generate_square_matrix(Matrix& current_matrix) {
	int number_of_rows = current_matrix.get_rows();
	int number_of_columns = current_matrix.get_columns();

	int size = min(number_of_rows, number_of_columns);
	
	Matrix square_matrix;
	
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++)
			square_matrix.set_matrix_element(i, j, current_matrix.get_matrix_element(i, j));
	}

	return square_matrix;
}

Matrix Matrix::generate_identity_matrix(int size) {
	Matrix identity_matrix(0.0, size, size);

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j)
				identity_matrix.set_matrix_element(i, j, 1);
		}
	}

	return identity_matrix;
}

Matrix Matrix::generate_row_vector(Vertex& current_vertex) {
	Matrix row_vector(0.0, 1, 3);

	row_vector.set_matrix_element(0, 0, current_vertex.x);
	row_vector.set_matrix_element(0, 1, current_vertex.y);
	row_vector.set_matrix_element(0, 2, current_vertex.z);

	return row_vector;
}

Matrix Matrix::generate_column_vector(Vertex& current_vertex) {
	Matrix column_vector(0.0, 3, 1);

	column_vector.set_matrix_element(0, 0, current_vertex.x);
	column_vector.set_matrix_element(1, 0, current_vertex.y);
	column_vector.set_matrix_element(2, 0, current_vertex.z);

	return column_vector;
}

Matrix Matrix::get_matrix_transpose(Matrix& current_matrix) {
	int rows = current_matrix.get_rows();
	int columns = current_matrix.get_columns();
	Matrix transpose(0.0, rows, columns);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++)
			transpose.set_matrix_element(i, j, current_matrix.get_matrix_element(j, i));
	}

	return transpose;
}

void Matrix::set_matrix_element(int row, int column, double value) {
	matrix[row][column] = value;
}

double Matrix::get_matrix_element(int row, int column) {
	return (matrix[row][column]);
}