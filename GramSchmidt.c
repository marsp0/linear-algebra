#include <stdio.h>
#include "GramSchmidt.h"

void orthogonalize(float input[][MAX_DIMENSION], float output[][MAX_DIMENSION], int dimension){
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			output[i][j] = input[i][j];
		}
		for (int k = 0; k < i; k++) {
			float projectionVec[MAX_DIMENSION];
			clear_vector(projectionVec);
			float scaledProjection[MAX_DIMENSION];
			clear_vector(scaledProjection);
			float currentResult[MAX_DIMENSION];
			clear_vector(currentResult);
			projection(input[i], output[k], projectionVec, dimension);
			scale(projectionVec, -1.f, scaledProjection, dimension);
			add(output[i], scaledProjection, currentResult, dimension);
			for (int x = 0; x < dimension; x++) {
				output[i][x] = currentResult[x];
			}
		}
	}
}