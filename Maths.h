#pragma once
#include "Constants.h"

void add(float v1[MAX_DIMENSION], 
		 float v2[MAX_DIMENSION], 
		 float result[MAX_DIMENSION], 
		 int dimension);

void scale(float v1[MAX_DIMENSION], 
		   float scale, 
		   float result[MAX_DIMENSION], 
		   int dimension);

float dot(float v1[MAX_DIMENSION], 
		  float v2[MAX_DIMENSION], 
		  int dimension);

float magnitude_squared(float v1[MAX_DIMENSION], int dimension);

void projection(float v1[MAX_DIMENSION], 
				float v2[MAX_DIMENSION], 
				float result[MAX_DIMENSION], 
				int dimension);

void unit(float v1[MAX_DIMENSION], int dimension, float result[MAX_DIMENSION]);