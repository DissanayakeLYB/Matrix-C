#include <stdio.h>

typedef struct {
	int rows;
	int columns;
} matrix;

matrix create_matrix() {
	
	matrix matrixA;

	printf("Enter the number of rows: ");
	scanf("%d", &matrixA.rows);
	
	printf("Enter the number of columns: ");
	scanf("%d", &matrixA.columns);

	printf("Matrix format: (%d,%d)\n", matrixA.rows, matrixA.columns);
	
	
	// create matrix with (rows, columns)
	
	int matrixA_values[matrixA.rows][matrixA.columns];

	// assign values to the matrix
	for (int i=0; i < matrixA.rows; i++) {
		for (int j=0; j < matrixA.columns; j++) {
			
			int matrix_value;

			printf("Enter the value for row %d, column %d: ", i+1 , j+1);
			scanf("%d", &matrix_value);

			matrixA_values[i][j] = matrix_value;
		}
	}

	// print the matrix
	for (int i=0; i < matrixA.rows; i++) {
		for (int j=0; j < matrixA.columns; j++) {
			
			if (j == 0) { printf("[ "); };

			printf("%d ", matrixA_values[i][j]);

			if (j == matrixA.columns-1) { printf("]\n"); }
		}
	}
}

int main() {

	create_matrix();
	return 0;

};

