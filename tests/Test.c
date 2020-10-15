/*
 * File:   newcunittest.c
 * Author: student
 *
 * Created on Oct 15, 2020, 4:17:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include </home/student/Desktop/DataStructure/stack.h>

/*
 * CUnit Test Suite
 */

int globalStack_test(){
    Stack s;
    init_stack(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
    push(&s, 8);
    CU_ASSERT_FALSE(is_stack_empty(&s));
    pop(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
    push(&s, 8);
    CU_ASSERT_FALSE(is_stack_empty(&s));
    push(&s, 1.2);
    push(&s, 8.555);
    push(&s, 96.332);
    push(&s, 47);
    CU_ASSERT_EQUAL(47, peek(&s));
    dup(&s);
    CU_ASSERT_EQUAL(47, s.data[s.index]);
    CU_ASSERT_EQUAL(47, s.data[(s.index) - 1]);
    push(&s, 49);
    swap(&s);
    CU_ASSERT_EQUAL(47,s.data[s.index]);
    CU_ASSERT_EQUAL(49, s.data[(s.index) - 1]);
    clear_stack(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
}

int initStack_test(){
    Stack s;
    init_stack(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
}

int pushStack_test(){
    Stack s;
    init_stack(&s);
    push(&s, 8);
    CU_ASSERT_FALSE(is_stack_empty(&s));
    CU_ASSERT_EQUAL(s.data[0],8);
}

int popStack_Test(){
    Stack s;
    init_stack(&s);
    push(&s, 8);
    pop(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
}

int dupStack_test(){
    Stack s;
    init_stack(&s);
    push(&s, 8);
    pop(&s);
    push(&s, 8);
    push(&s, 1.2);
    push(&s, 8.555);
    push(&s, 96.332);
    push(&s, 47);
    dup(&s); 
    CU_ASSERT_EQUAL(47, s.data[s.index]);
    CU_ASSERT_EQUAL(47, s.data[(s.index) - 1]);
}

int swapStack_test(){
    Stack s;
    init_stack(&s);
    push(&s, 8);
    pop(&s);
    push(&s, 8);
    push(&s, 1.2);
    push(&s, 8.555);
    push(&s, 96.332);
    push(&s, 47);
    dup(&s);
    push(&s, 49);
    swap(&s);
    CU_ASSERT_EQUAL(47,s.data[s.index]);
    CU_ASSERT_EQUAL(49, s.data[(s.index) - 1]);
}

int clearStack_test(){
    Stack s;
    init_stack(&s);
    push(&s, 8);
    pop(&s);
    push(&s, 8);
    push(&s, 1.2);
    push(&s, 8.555);
    push(&s, 96.332);
    push(&s, 47);
    dup(&s);
    push(&s, 49);
    swap(&s);
    clear_stack(&s);
    CU_ASSERT_TRUE(is_stack_empty(&s));
}



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
    
    if (NULL == CU_add_test(pSuite,"test global",globalStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test initialisation",initStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test push",pushStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test pop",popStack_Test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test dup",dupStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test swap",swapStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite,"test clear",clearStack_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    
    
    
    
    
    
    
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
