#ifndef MATRIX_H
#define MATRIX_H

#include "Vertex.h"

class Matrix {
public:
	Matrix(double init_value = 0, int rows = default_rows, int columns = default_columns);
	~Matrix();
	Matrix(const Matrix& src);
	bool is_matrix_square();
	Matrix generate_square_matrix(Matrix& current_matrix);
	Matrix generate_identity_matrix(int size);
	Matrix generate_row_vector(Vertex& current_vertex);
	Matrix generate_column_vector(Vertex& current_vertex);
	Matrix get_matrix_transpose(Matrix& current_matrix);

	int get_rows() { return rows; }
	int get_columns() { return columns; }
	void set_matrix_element(int row, int column, double value);
	double get_matrix_element(int row, int column);

	static const int default_rows = 3;
	static const int default_columns = 3;
private:
	double** matrix;
	double init_value;
	int rows;
	int columns;
};
#endif