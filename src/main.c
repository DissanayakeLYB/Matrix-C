#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

int main() {

	printf("========= Matrix Calculator ==========\n");

	printf("1 - Print matrix\n");
	printf("2 - Transpose Matrix\n");
	printf("3 - Add Matrix\n");
	printf("4 - Substract Matrix\n");
	
	printf("0 - Exit\n");

	printf("\nEnter a number: ");
	int user_input;
	scanf("%d", &user_input);

	printf("---------------------------------------\n");

	if (user_input == 0) {
		return 0;

	} else if (user_input == 1) {

		matrix matrixA = create_matrix();
		print_matrix(matrixA);
		
		// free up allocated memory
		free(matrixA.values);

	} else if (user_input == 2) {
		
		matrix matrixA = create_matrix();
		matrix transposed_matrix = transpose_matrix(matrixA);
		print_matrix(transposed_matrix);
		
		// free up allocated memory
		free(matrixA.values);
		free(transposed_matrix.values);

	} else if ( user_input == 3 ) {

		matrix matrixA = create_matrix();
		matrix matrixB = create_matrix();

		matrix added_matrix = add_matrix(matrixA, matrixB);
		print_matrix(added_matrix);

		// free up allocated memory
		free(matrixA.values);
		free(matrixB.values); 
		free(added_matrix.values);

	} else if ( user_input == 4 ) {

		matrix matrixA = create_matrix();
		matrix matrixB = create_matrix();

		matrix subtracted_matrix = subtract_matrix(matrixA, matrixB);
		print_matrix(subtracted_matrix);

		// free up allocated memory
		free(matrixA.values);
		free(matrixB.values); 
		free(subtracted_matrix.values);
	}

	return 0;
};

