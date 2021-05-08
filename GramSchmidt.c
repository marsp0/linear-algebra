#include <stdio.h>
#include "GramSchmidt.h"

void orthogonalize(float input[][MAX_DIMENSION], float output[][MAX_DIMENSION], int dimension){
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			output[i][j] = input[i][j];
		}
		for (int k = 0; k < i; k++) {
			float projectionVec[MAX_DIMENSION] = {};
			float scaledProjection[MAX_DIMENSION] = {};
			float currentResult[MAX_DIMENSION] = {};
			projection(input[i], output[k], projectionVec, dimension);
			scale(projectionVec, -1.f, scaledProjection, dimension);
			add(output[i], scaledProjection, currentResult, dimension);
			for (int x = 0; x < dimension; x++) {
				output[i][x] = currentResult[x];
			}
		}
	}
}