#include "minunit.h"
#include "../heapless_cpp.hpp"

void test_setup(void) 
{
}

void test_teardown(void) 
{
}

MU_TEST(test_array_len){
    hlcpp::Array<int, 10> a;

    mu_check(a.len() == 10);
}

MU_TEST(test_array_index){
    hlcpp::Array<int, 10> a;
	
	a[3] = 4;
    mu_check(a[3] == 4);
	a[3] = 5;
    mu_check(a[3] == 5);
}

MU_TEST(test_string_len_empty){
    hlcpp::String<10> str;
	
    mu_check(str.len() == 0u);
    mu_check(str.to_cstr()[0] == '\0');
}

MU_TEST_SUITE(test_array) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_array_len);
	MU_RUN_TEST(test_array_index);
}

MU_TEST_SUITE(test_string) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_string_len_empty);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_array);
	MU_RUN_SUITE(test_string);
	MU_REPORT();
	return MU_EXIT_CODE;
}
