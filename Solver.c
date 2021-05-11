#include "Solver.h"

#include <math.h>
#include <stdio.h>

#include "Util.h"

void solve(LinearSystem* system) {
	int row = 0;
	int col = 0;
	while (row < system->dimension && col < system->dimension) {
		int largest_row = row;
		// find largest row for the current column
		for (int k = row; k < system->dimension; k++) {
			if(fabs(system->matrix[col][row]) < fabs(system->matrix[col][k])) {
				largest_row = k;
			}
		}
		// swap current row with largest row for current column
		if (largest_row != row) {
			swap_rows(system, row, largest_row);
		}
		if (system->matrix[col][row] != 0.f) {
			// scale current row so we get 1 as a leading entry
			scale_row(system, row, 1.f/system->matrix[col][row]);
			// Nullify all rows except current
			for (int j = 0; j < system->dimension; j++) {
				if (j != row) {
					add_rows(system, j, 1.f, row, -(system->matrix[col][j]));
				}
			}
			row++;
		}
		col++;
	}
}


void swap_rows(LinearSystem* system, int first, int second) {
	float temp_row[MAX_DIMENSION] = {};
	// save first row to temp row
	for (int i = 0; i < system->dimension + 1; i++) {
		temp_row[i] = system->matrix[i][first];
	}
	// move second row to first row
	for (int i = 0; i < system->dimension + 1; i++) {
		system->matrix[i][first] = system->matrix[i][second];
	}
	// move temp row to second row
	for (int i = 0; i < system->dimension + 1; i++) {
		system->matrix[i][second] = temp_row[i];
	}
}

void scale_row(LinearSystem* system, int row, float scale) {
	for (int i = 0; i < system->dimension + 1; i++) {
		system->matrix[i][row] *= scale;
	}
}

void add_rows(LinearSystem* system, int first, float first_scale, int second, float second_scale) {
	for (int i = 0; i < system->dimension + 1; i++) {
		system->matrix[i][first] *= first_scale;
		system->matrix[i][first] += system->matrix[i][second] * second_scale;
	}
}