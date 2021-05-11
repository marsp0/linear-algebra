#include "Util.h"

#include <stdio.h>
#include <stdlib.h>

void print_matrix(float matrix[][MAX_DIMENSION], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%f ", matrix[j][i]);
		}
		printf("\n");
	}
	printf("------\n");
}

void print_vector(float vec[MAX_DIMENSION], int dimension) {
	for (int i = 0; i < dimension; i++) {
			printf("%f ", vec[i]);
	}
	printf("------\n");
}

void input_gram_schmidt(float matrix[][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("Vector %d - Entry %d: ", i + 1, j + 1);
            if (scanf("%f", &matrix[i][j]) != 1)
            {
                printf("\nInvalid input\n");
                exit(1);
            }
        }
    }
    printf("------\n");
}

void input_solver(LinearSystem* system) {
	for (int i = 0; i < system->dimension; i++) {
        for (int j = 0; j < system->dimension + 1; j++) {
            printf("Row %d - Entry %d: ", i + 1, j + 1);
            if (scanf("%f", &(system->matrix[j][i])) != 1)
            {
                printf("\nInvalid input\n");
                exit(1);
            }
        }
    }
    printf("------\n");
}