#include "Matrix.h"
#include "Vertex.h"

class MatrixArithmetic {
public:
	MatrixArithmetic();
	~MatrixArithmetic();

	bool is_matrix_square(Matrix& A);
	Matrix generate_square_matrix(Matrix& current_matrix);
	Matrix generate_identity_matrix(int size);
	Matrix generate_row_vector(Vertex& current_vertex);
	Matrix generate_column_vector(Vertex& current_vertex);
	Matrix get_matrix_transpose(Matrix& current_matrix);

	Matrix do_scalar_multiplication(int scalar, Matrix& current_matrix);
	friend Matrix operator+(Matrix& A, Matrix& B);
	friend Matrix operator-(Matrix& A, Matrix& B);
	friend Matrix operator*(Matrix& A, Matrix& B);
	double get_dot_product(Matrix& A, Matrix& B);
	Matrix get_cross_product(Matrix&A, Matrix& B);
};