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

MU_TEST(test_array_copy_constructor){
    hlcpp::Array<int, 3> a;
    a[0] = a[1] = a[2] = 15151515;
    hlcpp::Array<int, 3> b = a;

    mu_check(b.len() == a.len());
    mu_check(b[0] == 15151515);
    mu_check(b[1] == 15151515);
    mu_check(b[2] == 15151515);
}

MU_TEST(test_array_assignment_operator){
    hlcpp::Array<int, 3> a;
    a[0] = a[1] = a[2] = 15151515;
    hlcpp::Array<int, 3> b;

    b = a;

    mu_check(b.len() == a.len());
    mu_check(b[0] == 15151515);
    mu_check(b[1] == 15151515);
    mu_check(b[2] == 15151515);
}

MU_TEST(test_string_len_empty){
    hlcpp::String<10> str;
	
    mu_check(str.len() == 0u);
    mu_check(str.to_cstr()[0] == '\0');
}

MU_TEST(test_string_cstr_constructor){
    hlcpp::String<10> str("ivan");
	
    mu_check(str.len() == 4);
    mu_check(str.to_cstr()[0] == 'i');
    mu_check(str.to_cstr()[1] == 'v');
    mu_check(str.to_cstr()[2] == 'a');
    mu_check(str.to_cstr()[3] == 'n');
    mu_check(str.to_cstr()[4] == '\0');
}

MU_TEST(test_string_index){
    hlcpp::String<10> str("ivan");

	mu_check(str[0] == 'i');
	str[0] = 'x';
	mu_check(str[0] == 'x');
}

MU_TEST(test_string_copy_constructor){
    hlcpp::String<10> a("ivan");
    hlcpp::String<10> b = a;

    mu_check(b.len() == a.len());
    mu_check(b[0] == 'i');
    mu_check(b[1] == 'v');
    mu_check(b[2] == 'a');
    mu_check(b[3] == 'n');
    mu_check(b[4] == '\0');
}

MU_TEST_SUITE(test_array) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_array_len);
	MU_RUN_TEST(test_array_index);
    MU_RUN_TEST(test_array_copy_constructor);
    MU_RUN_TEST(test_array_assignment_operator);
}

MU_TEST_SUITE(test_string) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_string_len_empty);
	MU_RUN_TEST(test_string_cstr_constructor);
	MU_RUN_TEST(test_string_index);
    MU_RUN_TEST(test_string_copy_constructor);
}

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

	MU_RUN_SUITE(test_array);
	MU_RUN_SUITE(test_string);
	
    MU_REPORT();
	
    return MU_EXIT_CODE;
}
