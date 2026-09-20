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

	int counter = 0;
	int loc_i = 1;
	int loc_j = 1;

	// assign values to the matrix
	for (int i=0; i < matrixA.rows * matrixA.columns; i++) {
		
		int matrix_value;
		
		printf("(%d, %d) : ", loc_i, loc_j);
		scanf("%d", &matrix_value);

		if ( loc_j == matrixA.columns ) {
			loc_i++;
			loc_j = 1;
		} else {
			loc_j++;
		};

		matrixA.values[i] = matrix_value;
		counter++;
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


matrix add_matrix(matrix matrixA, matrix matrixB) {

	if ( matrixA.rows != matrixB.rows || matrixA.columns != matrixB.columns) {
		printf("Error: Matrices should have same dimensions to add.\n");
		exit(1);
	};

	matrix added_matrix;

	added_matrix.rows = matrixA.rows;
	added_matrix.columns = matrixA.columns;

	added_matrix.values = malloc(
		added_matrix.rows * added_matrix.columns * sizeof(int)
	);

	if ( added_matrix.values == NULL ) {
		printf("Memory allocation failed. \n");
		exit(1);
	};

	for (int i = 0; i < added_matrix.rows * added_matrix.columns; i++) {
		added_matrix.values[i] = matrixA.values[i] + matrixB.values[i];
	};

	return added_matrix;
};


int main() {
	// matrix MatrixA = create_matrix();
	// print_matrix(MatrixA);

	matrix MatrixA = create_matrix();
	matrix MatrixB = create_matrix();

	matrix added_matrix = add_matrix( MatrixA, MatrixB );

	print_matrix(added_matrix);
	

	// matrix transposed_matrix = transpose_matrix(MatrixA);
	// print_matrix(transposed_matrix);

	free(MatrixA.values);
	free(MatrixB.values);
	free(added_matrix.values);

	// free(transposed_matrix.values);




	return 0;
};

