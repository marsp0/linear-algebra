#include <stdio.h>
#include <stdlib.h>
#include "GramSchmidt.h"

int main(int argc, char const *argv[])
{
	int dimension;
	float input[MAX_DIMENSION][MAX_DIMENSION];
	clear_vectors(input);
	float output[MAX_DIMENSION][MAX_DIMENSION];
	clear_vectors(output);
	printf("Vector space dimension (2-10): ");
    if (scanf("%d", &dimension) != 1 || dimension > 10 || dimension < 2)
    {
    	printf("Invalid input\n");
    	exit(1);
    }
    printf("Dimension is - %d\n", dimension);
    for (int i = 0; i < dimension; i++) {
    	for (int j = 0; j < dimension; j++) {
    		printf("Vector %d - Entry %d: ", i + 1, j + 1);
		    if (scanf("%f", &input[i][j]) != 1)
		    {
		    	printf("\nInvalid input\n");
		    	exit(1);
		    }
    	}
    }
    printf("----------------------------------\n");
    // check if vectors are linearly independent
    // orthogonalize
    orthogonalize(input, output, dimension);
    // show result
    for (int i = 0; i < dimension; i++) {
    	for (int j = 0; j < dimension; j++) {
    		printf("Vector %d - Entry %d: %f\n", i + 1, j + 1, output[i][j]);
    	}
    }
	return 0;
}