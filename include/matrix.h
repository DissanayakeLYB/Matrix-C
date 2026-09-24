#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
	int rows;
	int columns;
	int *values;
} matrix;

matrix create_matrix();

void print_matrix(matrix Matrix);

matrix transpose_matrix(matrix Matrix);

matrix add_matrix(matrix MatrixA, matrix MatrixB);

matrix subtract_matrix(matrix MatrixA, matrix MatrixB);

void free_matrix(matrix Matrix);

#endif
