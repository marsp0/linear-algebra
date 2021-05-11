#include "solver_tests.h"

#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "../Constants.h"
#include "../Solver.h"
#include "../Util.h"

void solver_test_1() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 3.f;
	system->matrix[1][0] = 2.f;
	system->matrix[2][0] = -3.f;
	system->matrix[3][0] = -13.f;
	// second row
	system->matrix[0][1] = 4.f;
	system->matrix[1][1] = -3.f;
	system->matrix[2][1] = 6.f;
	system->matrix[3][1] = 7.f;
	// third row
	system->matrix[0][2] = 1.f;
	system->matrix[1][2] = 0.f;
	system->matrix[2][2] = -1.f;
	system->matrix[3][2] = -5.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] + 2.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][1] - 1.f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 3.f) < 0.005f);
	free(system);
}

void solver_test_2() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 2.f;
	system->matrix[1][0] = 1.f;
	system->matrix[2][0] = 3.f;
	system->matrix[3][0] = 0.f;
	// second row
	system->matrix[0][1] = 0.f;
	system->matrix[1][1] = 1.f;
	system->matrix[2][1] = -1.f;
	system->matrix[3][1] = 0.f;
	// third row
	system->matrix[0][2] = 1.f;
	system->matrix[1][2] = 3.f;
	system->matrix[2][2] = -1.f;
	system->matrix[3][2] = 0.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 2.f) < 0.005f);
	assert(fabs(system->matrix[3][0] - 0.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] + 1.f) < 0.005f);
	assert(fabs(system->matrix[3][1] - 0.f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 0.f) < 0.005f);
	free(system);
}

void solver_test_3() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 4.f;
	system->matrix[1][0] = 2.f;
	system->matrix[2][0] = -6.f;
	system->matrix[3][0] = 34.f;
	// second row
	system->matrix[0][1] = 2.f;
	system->matrix[1][1] = 1.f;
	system->matrix[2][1] = 3.f;
	system->matrix[3][1] = 3.f;
	// third row
	system->matrix[0][2] = 6.f;
	system->matrix[1][2] = 3.f;
	system->matrix[2][2] = -3.f;
	system->matrix[3][2] = 37.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.5f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] - 5.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][1] + 2.3333f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 0.f) < 0.005f);
	free(system);
}

void solver_test_4() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 3.f;
	system->matrix[1][0] = -1.f;
	system->matrix[2][0] = 1.f;
	system->matrix[3][0] = -1.f;
	// second row
	system->matrix[0][1] = 2.f;
	system->matrix[1][1] = 3.f;
	system->matrix[2][1] = 1.f;
	system->matrix[3][1] = 4.f;
	// third row
	system->matrix[0][2] = 5.f;
	system->matrix[1][2] = 4.f;
	system->matrix[2][2] = 2.f;
	system->matrix[3][2] = 5.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] + 1.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][1] - 1.f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 3.f) < 0.005f);
	free(system);
}

void solver_test_5() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 2.f;
	system->matrix[1][0] = 1.f;
	system->matrix[2][0] = 1.f;
	system->matrix[3][0] = -2.f;
	// second row
	system->matrix[0][1] = 2.f;
	system->matrix[1][1] = -1.f;
	system->matrix[2][1] = 3.f;
	system->matrix[3][1] = 6.f;
	// third row
	system->matrix[0][2] = 3.f;
	system->matrix[1][2] = -5.f;
	system->matrix[2][2] = 4.f;
	system->matrix[3][2] = 7.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] + 3.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][1] - 0.f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 4.f) < 0.005f);
	free(system);
}

void solver_test_6() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 6.f;
	system->matrix[1][0] = 2.f;
	system->matrix[2][0] = -4.f;
	system->matrix[3][0] = 15.f;
	// second row
	system->matrix[0][1] = -3.f;
	system->matrix[1][1] = -4.f;
	system->matrix[2][1] = 2.f;
	system->matrix[3][1] = -6.f;
	// third row
	system->matrix[0][2] = 4.f;
	system->matrix[1][2] = -6.f;
	system->matrix[2][2] = 3.f;
	system->matrix[3][2] = 8.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] - 2.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][1] + 0.5f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][2] + 1.f) < 0.005f);
	free(system);
}

void solver_test_7() {
	LinearSystem* system = (LinearSystem*)malloc(sizeof(LinearSystem));
	system->dimension = 3;
	// first row
	system->matrix[0][0] = 3.f;
	system->matrix[1][0] = 0.f;
	system->matrix[2][0] = 3.f;
	system->matrix[3][0] = 0.f;
	// second row
	system->matrix[0][1] = 2.f;
	system->matrix[1][1] = 2.f;
	system->matrix[2][1] = 0.f;
	system->matrix[3][1] = 2.f;
	// third row
	system->matrix[0][2] = 0.f;
	system->matrix[1][2] = 3.f;
	system->matrix[2][2] = 3.f;
	system->matrix[3][2] = 3.f;
	solve(system);
	// first row
	assert(fabs(system->matrix[0][0] - 1.f) < 0.005f);
	assert(fabs(system->matrix[1][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][0] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][0] - 0.f) < 0.005f);
	// second row
	assert(fabs(system->matrix[0][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][1] - 1.f) < 0.005f);
	assert(fabs(system->matrix[2][1] - 0.f) < 0.005f);
	assert(fabs(system->matrix[3][1] - 1.f) < 0.005f);
	// third row
	assert(fabs(system->matrix[0][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[1][2] - 0.f) < 0.005f);
	assert(fabs(system->matrix[2][2] - 1.f) < 0.005f);
	assert(fabs(system->matrix[3][2] - 0.f) < 0.005f);
	free(system);
}

void run_solver_tests() {
	solver_test_1();
	solver_test_2();
	solver_test_3();
	solver_test_4();
	solver_test_5();
	solver_test_6();
	solver_test_7();
}