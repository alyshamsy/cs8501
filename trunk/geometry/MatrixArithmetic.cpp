#include "MatrixArithmetic.h"
#include <iostream>

using namespace std;

MatrixArithmetic::MatrixArithmetic() {

}

MatrixArithmetic::~MatrixArithmetic() {

}

bool MatrixArithmetic::is_matrix_square(Matrix& A) {
	if(A.get_rows() == A.get_columns())
		return true;
	else
		return false;
}

Matrix MatrixArithmetic::generate_square_matrix(Matrix& current_matrix) {
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

Matrix MatrixArithmetic::generate_identity_matrix(int size) {
	Matrix identity_matrix(0.0, size, size);

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j)
				identity_matrix.set_matrix_element(i, j, 1);
		}
	}

	return identity_matrix;
}

Matrix MatrixArithmetic::generate_row_vector(Vertex& current_vertex) {
	Matrix row_vector(0.0, 1, 3);

	row_vector.set_matrix_element(0, 0, current_vertex.x);
	row_vector.set_matrix_element(0, 1, current_vertex.y);
	row_vector.set_matrix_element(0, 2, current_vertex.z);

	return row_vector;
}

Matrix MatrixArithmetic::generate_column_vector(Vertex& current_vertex) {
	Matrix column_vector(0.0, 3, 1);

	column_vector.set_matrix_element(0, 0, current_vertex.x);
	column_vector.set_matrix_element(1, 0, current_vertex.y);
	column_vector.set_matrix_element(2, 0, current_vertex.z);

	return column_vector;
}

Matrix MatrixArithmetic::get_matrix_transpose(Matrix& current_matrix) {
	int rows = current_matrix.get_rows();
	int columns = current_matrix.get_columns();
	Matrix transpose(0.0, rows, columns);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++)
			transpose.set_matrix_element(i, j, current_matrix.get_matrix_element(j, i));
	}

	return transpose;
}

Matrix MatrixArithmetic::do_scalar_multiplication(int scalar, Matrix& current_matrix) {
	int rows = current_matrix.get_rows();
	int columns = current_matrix.get_columns();
	
	Matrix scaled_matrix(0.0, rows, columns);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++)
			scaled_matrix.set_matrix_element(i, j, scalar*current_matrix.get_matrix_element(i, j));
	}

	return scaled_matrix;
}

Matrix operator+(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	//if(rows_a == rows_b && columns_a == columns_b) 
	Matrix added_matrix(0.0, rows_a, columns_a);

	for(int i = 0; i < rows_a; i++) {
		for(int j = 0; j < columns_a; j++)
			added_matrix.set_matrix_element(i, j, A.get_matrix_element(i, j)+B.get_matrix_element(i, j));
	}

	return added_matrix;
}

Matrix operator-(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	//if(rows_a == rows_b && columns_a == columns_b) 
	Matrix subtracted_matrix(0.0, rows_a, columns_a);

	for(int i = 0; i < rows_a; i++) {
		for(int j = 0; j < columns_a; j++)
			subtracted_matrix.set_matrix_element(i, j, A.get_matrix_element(i, j)-B.get_matrix_element(i, j));
	}

	return subtracted_matrix;
}

Matrix operator*(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	//if(columns_a == rows_b) 
	double element = 0.0;
	Matrix multiplied_matrix(0.0, rows_a, columns_b);

	for(int i = 0; i < rows_a; i++) {
		for(int j = 0; j <columns_b; j++) {
			for(int k = 0; k < columns_a; k++) {
				element += A.get_matrix_element(i, k) * B.get_matrix_element(k, j);
			}
			multiplied_matrix.set_matrix_element(i, j, element);
		}	
	}

	return multiplied_matrix;
}

double MatrixArithmetic::get_dot_product(Matrix& A, Matrix& B) {
	double dot_product = 0.0;
	int rows = A.get_rows();
	int columns = A.get_columns();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++)
			dot_product += A.get_matrix_element(i, j) * B.get_matrix_element(j, i);
	}

	return dot_product;
}

Matrix MatrixArithmetic::get_cross_product(Matrix&A, Matrix& B) {
	Matrix cross_product(0.0, 3, 1);

	double element = (A.get_matrix_element(0, 1)*B.get_matrix_element(0, 2)) - (A.get_matrix_element(0, 2)*B.get_matrix_element(0, 1));
	cross_product.set_matrix_element(0, 0, element);

	element = (A.get_matrix_element(0, 2)*B.get_matrix_element(0, 0)) - (A.get_matrix_element(0, 0)*B.get_matrix_element(0, 2));
	cross_product.set_matrix_element(0, 0, element);

	element = (A.get_matrix_element(0, 2)*B.get_matrix_element(0, 0)) - (A.get_matrix_element(0, 0)*B.get_matrix_element(0, 2));
	cross_product.set_matrix_element(0, 0, element);

	return cross_product;
}