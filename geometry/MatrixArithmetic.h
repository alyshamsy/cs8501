#include "Matrix.h"

class MatrixArithmetic {
public:
	MatrixArithmetic();
	~MatrixArithmetic();
	Matrix do_scalar_multiplicatio(int scalar, Matrix& current_matrix);
	Matrix do_matrix_addition(Matrix& A, Matrix& B);
	Matrix do_matrix_subtraction(Matrix& A, Matrix& B);
	Matrix do_matrix_multiplication(Matrix& A, Matrix& B);
	double get_dot_product(Matrix& A, Matrix& B);
	Matrix get_cross_product(Matrix&A, Matrix& B);

};