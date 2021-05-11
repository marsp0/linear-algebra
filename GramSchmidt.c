#include <stdio.h>
#include "GramSchmidt.h"
#include "Util.h"

void orthogonalize(float input[][MAX_DIMENSION], float output[][MAX_DIMENSION], int dimension){
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			output[i][j] = input[i][j];
		}
		for (int k = 0; k < i; k++) {
			float projection_vector[MAX_DIMENSION] = {};
			float scaled_projection[MAX_DIMENSION] = {};
			float currentResult[MAX_DIMENSION] = {};
			projection(input[i], output[k], projection_vector, dimension);
			scale(projection_vector, -1.f, scaled_projection, dimension);
			add(output[i], scaled_projection, currentResult, dimension);
			for (int x = 0; x < dimension; x++) {
				output[i][x] = currentResult[x];
			}
		}
	}
}