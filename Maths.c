#include "Maths.h"
#include <stdio.h>
#include <math.h>

void add(float v1[MAX_DIMENSION], float v2[MAX_DIMENSION], float result[MAX_DIMENSION], int dimension) {
	for (int i = 0; i < dimension; i++) {
		result[i] = v1[i] + v2[i];
	}
	return;
}

void scale(float v1[MAX_DIMENSION], float scale, float result[MAX_DIMENSION], int dimension) {
	for (int i = 0; i < dimension; i++) {
		result[i] = v1[i] * scale;
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
	float dot_product = dot(v1, v2, dimension);
	float magnitude_sq = magnitude_squared(v2, dimension);
	float vec_scale = 0.f;
	if (magnitude_sq > 0.00005f) {
		vec_scale = dot_product/magnitude_sq;
	}
	scale(v2, vec_scale, result, dimension);
	return;
}

void unit(float v1[MAX_DIMENSION], int dimension, float result[MAX_DIMENSION]) {
	float squared_magnitude = magnitude_squared(v1, dimension);
	float magnitude = 0.f;
	if (squared_magnitude > 0.00005f) {
		magnitude = 1.f/sqrt(squared_magnitude);
	}
	scale(v1, magnitude, result, dimension);
	return;
}