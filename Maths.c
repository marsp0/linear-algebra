#include "Maths.h"
#include <stdio.h>

void add(float v1[MAX_DIMENSION], float v2[MAX_DIMENSION], float result[MAX_DIMENSION], int dimension) {
	for (int i = 0; i < dimension; i++) {
		result[i] = v1[i] + v2[i];
	}
	return;
}

void scale(float v1[MAX_DIMENSION], float scale, float result[MAX_DIMENSION], int dimension) {
	printf("scale is : %f", scale);
	for (int i = 0; i < dimension; i++) {
		result[i] = v1[i] * scale;
		for (int i = 0; i < dimension; i++) {
			printf("scale res is : %f\n", result[i]);
		}
	}
	return;
}

float dot(float v1[MAX_DIMENSION], float v2[MAX_DIMENSION], int dimension) {
	float result = 0.f;
	for (int i = 0; i < dimension; i++) {
		result += v1[i] * v2[i];
	}
	return result;
}

float magnitude_squared(float v1[MAX_DIMENSION], int dimension) {
	float result = 0.f;
	for (int i = 0; i < dimension; i++) {
		result += v1[i] * v1[i];
	}
	return result;
}

void projection(float v1[MAX_DIMENSION], float v2[MAX_DIMENSION], float result[MAX_DIMENSION], int dimension) {
	float dotProduct = dot(v1, v2, dimension);
	float magnitude_sq = magnitude_squared(v2, dimension);
	for (int i = 0; i < dimension; i++) {
		printf("V2 is : %f\n", v2[i]);
	}
	printf("dot/mg_sq: %f, %f, %f", dotProduct, magnitude_sq, dotProduct/magnitude_sq);
	scale(v2, dotProduct/magnitude_sq, result, dimension);
	return;
}

void clear_vector(float vec[MAX_DIMENSION]) {
	for (int i = 0; i < MAX_DIMENSION; i++) {
		vec[i] = 0.f;
	}
}

void clear_vectors(float vectors[][MAX_DIMENSION]) {
	for (int i = 0; i < MAX_DIMENSION; i++) {
		clear_vector(vectors[i]);
	}
}