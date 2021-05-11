#pragma once

#include "Constants.h"
#include "Solver.h"

void print_matrix(float matrix[][MAX_DIMENSION], int rows, int cols);
void print_vector(float vec[MAX_DIMENSION], int dimension);
void input_gram_schmidt(float matrix[][MAX_DIMENSION], int dimension);
void input_solver(LinearSystem* system);