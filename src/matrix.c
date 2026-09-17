#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rows;
	int columns;
	int *values;
} matrix;

matrix create_matrix() {
	
	// create matrix with (rows, columns)
	matrix matrixA;

	printf("Enter the number of rows: ");
	scanf("%d", &matrixA.rows);
	
	printf("Enter the number of columns: ");
	scanf("%d", &matrixA.columns);

	matrixA.values = malloc (
		matrixA.rows * matrixA.columns * sizeof(int)
	);
		
	if ( matrixA.values == NULL ) {
		printf("Memory allocation failed.\n");
		exit(1);
	};

	printf("Matrix format: (%d,%d)\n", matrixA.rows, matrixA.columns);


	// assign values to the matrix
	for (int i=0; i < matrixA.rows * matrixA.columns; i++) {
		int matrix_value;

		printf("Enter the value for %d: ", i+1 );
		scanf("%d", &matrix_value);

		matrixA.values[i] = matrix_value;
	}

	return matrixA;
}

int main() {

	matrix MatrixA = create_matrix();
	free(MatrixA.values);
	return 0;

};

