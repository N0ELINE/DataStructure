/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "queue.h"

//comment on arrete un programme avec un message d'erreur visible

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}

void testStack() {
    Stack s;
    init_stack(&s);
    assert(true == is_stack_empty(&s));
    push(&s, 8);
    assert(false == is_stack_empty(&s));
    pop(&s);
    assert(true == is_stack_empty(&s));
    push(&s, 8);
    assert(false == is_stack_empty(&s));
    push(&s, 1.2);
    push(&s, 8.555);
    push(&s, 96.332);
    push(&s, 47);
    assert(47 == peek(&s));
    dup(&s);
    assert(47==s.data[s.index]);
    assert(47==s.data[(s.index)-1]);
    push(&s, 49);
    swap(&s);
    assert(47==s.data[s.index]);
    assert(49==s.data[(s.index)-1]);
    clear_stack(&s);
    assert(true == is_stack_empty(&s));
}

void testQueue() {
    Queue q;
    init_queue(&q);
    assert(true == is_queue_empty(&q));
    enqueue(&q,7);
    assert(false == is_queue_empty(&q));
    dequeue(&q);
    assert(true == is_queue_empty(&q));
    enqueue(&q,7);
    enqueue(&q,7.5);
    enqueue(&q,25);
    enqueue(&q,41.65);
    enqueue(&q,58);
    assert(58 == front(&q));
    clear_queue(&q);
    assert(true == is_queue_empty(&q));
}

void testArray(){
    Array_list l;
    init_array_list(&l);
    
}

int main(int argc, char** argv) {
    testStack();
    testQueue();


    return (EXIT_SUCCESS);
}

