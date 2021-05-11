#pragma once
#include "Constants.h"

typedef struct {
	float 	matrix[MAX_DIMENSION][MAX_DIMENSION];
	int 	dimension;
} LinearSystem;

void solve(LinearSystem* system);

void swap_rows(LinearSystem* system, int first, int second);
void scale_row(LinearSystem* system, int row, float scale);
void add_rows(LinearSystem* system, int first, float first_scale, int second, float second_scale);