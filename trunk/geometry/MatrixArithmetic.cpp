#include "MatrixArithmetic.h"
#include <iostream>

using namespace std;

MatrixArithmetic::MatrixArithmetic() {

}

MatrixArithmetic::~MatrixArithmetic() {

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

Matrix MatrixArithmetic::do_matrix_addition(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	if(rows_a == rows_b && columns_a == columns_b) {
		Matrix added_matrix(0.0, rows_a, columns_a);

		for(int i = 0; i < rows_a; i++) {
			for(int j = 0; j < columns_a; j++)
				added_matrix.set_matrix_element(i, j, A.get_matrix_element(i, j)+B.get_matrix_element(i, j));
		}

		return added_matrix;
	}
}

Matrix MatrixArithmetic::do_matrix_subtraction(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	if(rows_a == rows_b && columns_a == columns_b) {
		Matrix subtracted_matrix(0.0, rows_a, columns_a);

		for(int i = 0; i < rows_a; i++) {
			for(int j = 0; j < columns_a; j++)
				subtracted_matrix.set_matrix_element(i, j, A.get_matrix_element(i, j)-B.get_matrix_element(i, j));
		}

		return subtracted_matrix;
	}
}

Matrix MatrixArithmetic::do_matrix_multiplication(Matrix& A, Matrix& B) {
	int rows_a = A.get_rows();
	int columns_a = A.get_columns();

	int rows_b = B.get_rows();
	int columns_b = B.get_columns();

	if(columns_a == rows_b) {
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
}