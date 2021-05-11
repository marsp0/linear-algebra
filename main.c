#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GramSchmidt.h"
#include "Solver.h"
#include "Util.h"
#include "test/test.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Invalid command line option\n");
        printf("Options are: SOLVER, GRAM_SCHMIDT, CHANGE_OF_BASIS, INVERSE, TEST\n");
        exit(1);
    }
    const char* input_type = argv[1];
    if (strcmp(input_type, "TEST") == 0) {
        run_tests();
    } else {
        int dimension;
        printf("Dimension (2-9): ");
        if (scanf("%d", &dimension) != 1 || dimension > 9 || dimension < 2)
        {
            printf("Invalid input\n");
            exit(1);
        }
        if (strcmp(input_type, "GRAM") == 0) {
            float input[MAX_DIMENSION][MAX_DIMENSION] = {};
            float output[MAX_DIMENSION][MAX_DIMENSION] = {};
            input_gram_schmidt(input, dimension);
            orthogonalize(input, output, dimension);
            print_matrix(output, dimension, dimension);
        } else if (strcmp(input_type, "SOLVER") == 0) {
            LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
            system->dimension = dimension;
            input_solver(system);
            solve(system);
            print_matrix(system->matrix, system->dimension, system->dimension + 1);
            free(system);
        }
    }
	return 0;
}