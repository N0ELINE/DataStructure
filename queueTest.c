/*
 * File:   newcunittest.c
 * Author: student
 *
 * Created on Oct 15, 2020, 4:17:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include </home/student/Desktop/DataStructure/queue.h>

/*
 * CUnit Test Suite
 */

int globalQueue_test(){
    Queue q;
    init_queue(&q);
    CU_ASSERT_TRUE(is_queue_empty(&q));
    enqueue(&q, 7);
    CU_ASSERT_EQUAL(false, is_queue_empty(&q));
    dequeue(&q);
    CU_ASSERT_TRUE(is_queue_empty(&q));
    enqueue(&q, 7);
    enqueue(&q, 7.5);
    enqueue(&q, 25);
    enqueue(&q, 41.65);
    enqueue(&q, 58);
    CU_ASSERT_EQUAL(58, front(&q));
    clear_queue(&q);
    CU_ASSERT_TRUE(is_queue_empty(&q));
}

int initQueue_test(){
    Queue q;
    init_queue(&q);
    CU_ASSERT_TRUE(is_queue_empty(&q));
}

int enqueueQueue_test(){
    Queue q;
    init_queue(&q);
    enqueue(&q, 7);
    CU_ASSERT_EQUAL(false, is_queue_empty(&q));
}

int frontQueue_Test(){
    Queue q;
    init_queue(&q);
    enqueue(&q, 7);
    dequeue(&q);
    enqueue(&q, 7);
    enqueue(&q, 7.5);
    enqueue(&q, 25);
    enqueue(&q, 41.65);
    enqueue(&q, 58);
    CU_ASSERT_EQUAL(58, front(&q));
}

int clearQueue_test(){
    Queue q;
    init_queue(&q);
    enqueue(&q, 7);
    clear_queue(&q);
    CU_ASSERT_TRUE(is_queue_empty(&q));
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
    
    if (NULL == CU_add_test(pSuite,"test global",globalQueue_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test initialisation",initQueue_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test enqueue",enqueueQueue_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test front",frontQueue_Test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test clear",clearQueue_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    
    
    
    
    return CU_get_error();
}
