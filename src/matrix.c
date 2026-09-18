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

	printf("---------------------------------------\n");
	printf("Matrix format: (%d,%d)\n", matrixA.rows, matrixA.columns);
	printf("---------------------------------------\n");

	// assign values to the matrix
	for (int i=0; i < matrixA.rows * matrixA.columns; i++) {
		int matrix_value;

		printf("Enter the value for %d: ", i+1 );
		scanf("%d", &matrix_value);

		matrixA.values[i] = matrix_value;
	}

	printf("---------------------------------------\n");

	return matrixA;
}

void print_matrix( matrix Matrix ) {
	
	for (int i = 0; i < (Matrix.columns * Matrix.rows); i++) {
		printf("%d ", *(Matrix.values+i));
		
		if ( (i+1) % Matrix.columns == 0 ) {
			printf("\n");
		};
	};
	
	printf("---------------------------------------\n");
};

matrix transpose_matrix(matrix Matrix) {
	
	
	// create new transposed matrix
	matrix transposed_matrix;
	transposed_matrix.rows = Matrix.columns;
	transposed_matrix.columns = Matrix.rows;

	printf("New rows: %d \n", transposed_matrix.rows);
	printf("New columns: %d \n", transposed_matrix.columns);

	printf("---------------------------------------\n");
	
	
	// assign memory for transpose matrix 
	transposed_matrix.values = malloc( 
			transposed_matrix.rows * transposed_matrix.columns * sizeof(int)
	);
	
	if (transposed_matrix.values == NULL) {
		printf("Memory allocation failed. \n");
		exit(1);
	};


	// add values to transposed matrix
	int position = 0; // position in transposed matrix to add new value

	for (int i = 0; i < transposed_matrix.rows; i++){
		
		int buffer = i;

		while (buffer < transposed_matrix.rows * transposed_matrix.columns) {
			
			transposed_matrix.values[position] = *(Matrix.values + buffer);	

			buffer += transposed_matrix.rows;	
			position++;

		};
	};

	return transposed_matrix;

};


int main() {
	matrix MatrixA = create_matrix();
	print_matrix(MatrixA);

	matrix transposed_matrix = transpose_matrix(MatrixA);
	print_matrix(transposed_matrix);

	free(MatrixA.values);
	free(transposed_matrix.values);

	return 0;
};

