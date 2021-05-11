#include "test.h"
#include "solver_tests.h"
#include "gram_schmidt_tests.h"

void run_tests() {
	run_solver_tests();
	run_gram_schmidt_tests();
}