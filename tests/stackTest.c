/*
 * File:   newcunittest.c
 * Author: student
 *
 * Created on Oct 15, 2020, 4:17:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <stack.h>

/*
 * CUnit Test Suite
 */

int initStack_test(){
    Stack s;
    init_stack(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
}




int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test initialisation",initStack_test)) || (NULL == CU_add_test(pSuite,"test initialisation",initStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    
    
    
    
    return CU_get_error();
}
