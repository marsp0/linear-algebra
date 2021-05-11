#include "gram_schmidt_tests.h"

#include <math.h>
#include <assert.h>

#include "../Constants.h"
#include "../GramSchmidt.h"
#include "../Util.h"

void gram_test_1() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 3;
	// first col
	input[0][0] = 1.f;
	input[0][1] = 0.f;
	input[0][2] = 0.f;
	// second col
	input[1][0] = 0.f;
	input[1][1] = 1.f;
	input[1][2] = 0.f;
	// third col
	input[2][0] = 4.f;
	input[2][1] = 0.f;
	input[2][2] = 0.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 1.f) < 0.005f);
	assert(fabs(output[0][1] - 0.f) < 0.005f);
	assert(fabs(output[0][2] - 0.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] - 0.f) < 0.005f);
	assert(fabs(output[1][1] - 1.f) < 0.005f);
	assert(fabs(output[1][2] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.f) < 0.005f);
	assert(fabs(output[2][1] - 0.f) < 0.005f);
	assert(fabs(output[2][2] - 0.f) < 0.005f);
}

void gram_test_2() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 3;
	// first col
	input[0][0] = 1.f;
	input[0][1] = 0.f;
	input[0][2] = 0.f;
	// second col
	input[1][0] = 0.f;
	input[1][1] = 1.f;
	input[1][2] = 0.f;
	// third col
	input[2][0] = 0.f;
	input[2][1] = 0.f;
	input[2][2] = 1.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 1.f) < 0.005f);
	assert(fabs(output[0][1] - 0.f) < 0.005f);
	assert(fabs(output[0][2] - 0.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] - 0.f) < 0.005f);
	assert(fabs(output[1][1] - 1.f) < 0.005f);
	assert(fabs(output[1][2] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.f) < 0.005f);
	assert(fabs(output[2][1] - 0.f) < 0.005f);
	assert(fabs(output[2][2] - 1.f) < 0.005f);
}

void gram_test_3() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 3;
	// first col
	input[0][0] = 1.f;
	input[0][1] = 0.f;
	input[0][2] = 0.f;
	// second col
	input[1][0] = 1.f;
	input[1][1] = 0.f;
	input[1][2] = 0.f;
	// third col
	input[2][0] = 1.f;
	input[2][1] = 0.f;
	input[2][2] = 0.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 1.f) < 0.005f);
	assert(fabs(output[0][1] - 0.f) < 0.005f);
	assert(fabs(output[0][2] - 0.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] - 0.f) < 0.005f);
	assert(fabs(output[1][1] - 0.f) < 0.005f);
	assert(fabs(output[1][2] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.f) < 0.005f);
	assert(fabs(output[2][1] - 0.f) < 0.005f);
	assert(fabs(output[2][2] - 0.f) < 0.005f);
}

void gram_test_4() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 3;
	// first col
	input[0][0] = 0.f;
	input[0][1] = 0.f;
	input[0][2] = 0.f;
	// second col
	input[1][0] = 0.f;
	input[1][1] = 0.f;
	input[1][2] = 0.f;
	// third col
	input[2][0] = 0.f;
	input[2][1] = 0.f;
	input[2][2] = 0.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 0.f) < 0.005f);
	assert(fabs(output[0][1] - 0.f) < 0.005f);
	assert(fabs(output[0][2] - 0.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] - 0.f) < 0.005f);
	assert(fabs(output[1][1] - 0.f) < 0.005f);
	assert(fabs(output[1][2] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.f) < 0.005f);
	assert(fabs(output[2][1] - 0.f) < 0.005f);
	assert(fabs(output[2][2] - 0.f) < 0.005f);
}

void gram_test_5() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 3;
	// first col
	input[0][0] = 1.f;
	input[0][1] = 1.f;
	input[0][2] = 1.f;
	// second col
	input[1][0] = -1.f;
	input[1][1] = 1.f;
	input[1][2] = 0.f;
	// third col
	input[2][0] = 1.f;
	input[2][1] = 2.f;
	input[2][2] = 1.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 1.f) < 0.005f);
	assert(fabs(output[0][1] - 1.f) < 0.005f);
	assert(fabs(output[0][2] - 1.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] + 1.f) < 0.005f);
	assert(fabs(output[1][1] - 1.f) < 0.005f);
	assert(fabs(output[1][2] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.16666f) < 0.005f);
	assert(fabs(output[2][1] - 0.16666f) < 0.005f);
	assert(fabs(output[2][2] + 0.33333f) < 0.005f);
}

void gram_test_6() {
	float input[MAX_DIMENSION][MAX_DIMENSION];
	float output[MAX_DIMENSION][MAX_DIMENSION];
	int dimension = 4;
	// first col
	input[0][0] = 0.f;
	input[0][1] = 2.f;
	input[0][2] = 1.f;
	input[0][3] = 0.f;
	// second col
	input[1][0] = 1.f;
	input[1][1] = -1.f;
	input[1][2] = 0.f;
	input[1][3] = 0.f;
	// third col
	input[2][0] = 1.f;
	input[2][1] = 2.f;
	input[2][2] = 0.f;
	input[2][3] = -1.f;
	// fourth col
	input[3][0] = 1.f;
	input[3][1] = 0.f;
	input[3][3] = 1.f;
	input[3][2] = 0.f;
	orthogonalize(input, output, dimension);
	// first col
	assert(fabs(output[0][0] - 0.f) < 0.005f);
	assert(fabs(output[0][1] - 2.f) < 0.005f);
	assert(fabs(output[0][2] - 1.f) < 0.005f);
	assert(fabs(output[0][3] - 0.f) < 0.005f);
	// second col
	assert(fabs(output[1][0] - 1.f) < 0.005f);
	assert(fabs(output[1][1] + 0.2f) < 0.005f);
	assert(fabs(output[1][2] - 0.4f) < 0.005f);
	assert(fabs(output[1][3] - 0.f) < 0.005f);
	// third col
	assert(fabs(output[2][0] - 0.5f) < 0.005f);
	assert(fabs(output[2][1] - 0.5f) < 0.005f);
	assert(fabs(output[2][2] + 1.f) < 0.005f);
	assert(fabs(output[2][3] + 1.f) < 0.005f);
	// fourth col
	assert(fabs(output[3][0] - 0.26666f) < 0.005f);
	assert(fabs(output[3][1] - 0.26666f) < 0.005f);
	assert(fabs(output[3][2] + 0.53333f) < 0.005f);
	assert(fabs(output[3][3] - 0.8f) < 0.005f);
}

void run_gram_schmidt_tests() {
	gram_test_1();
	gram_test_2();
	gram_test_3();
	gram_test_4();
	gram_test_5();
	gram_test_6();
}