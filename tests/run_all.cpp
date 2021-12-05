#include "minunit.h"
#include "../heapless_cpp.hpp"

void test_setup(void) 
{
}

void test_teardown(void) 
{
}

MU_TEST(test_example){
	mu_assert(true, "");
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_example);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
