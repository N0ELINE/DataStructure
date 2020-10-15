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
#include "array_list.h"
#include "heap.h"

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
    assert(47 == s.data[s.index]);
    assert(47 == s.data[(s.index) - 1]);
    push(&s, 49);
    swap(&s);
    assert(47 == s.data[s.index]);
    assert(49 == s.data[(s.index) - 1]);
    clear_stack(&s);
    assert(true == is_stack_empty(&s));
}

void testQueue() {
    Queue q;
    init_queue(&q);
    assert(true == is_queue_empty(&q));
    enqueue(&q, 7);
    assert(false == is_queue_empty(&q));
    dequeue(&q);
    assert(true == is_queue_empty(&q));
    enqueue(&q, 7);
    enqueue(&q, 7.5);
    enqueue(&q, 25);
    enqueue(&q, 41.65);
    enqueue(&q, 58);
    assert(58 == front(&q));
    clear_queue(&q);
    assert(true == is_queue_empty(&q));
}

void testArray() {
    Array_list l;
    init_array_list(&l);
    add(&l, 9);
    assert(9 == l.data[0]);
    add(&l, 5);
    assert(get_at(&l, 0) == l.data[0]);
    add(&l, 6);
    insert_at(&l, 1, 8);
    assert(8 == l.data[1]);
    assert(5 == l.data[2]);
    assert(6 == l.data[3]);
    remove_at(&l, 1);
    assert(5 == l.data[1]);
}

void testHeap(){
    Heap h;
    init_heap(&h);
    assert(true == is_heap_empty(&h));
    push_heap(&h,8);
    assert(false == is_heap_empty(&h));
    assert(8 == h.data[0]);
    push_heap(&h,9);
    push_heap(&h,10);
    float value = pop_heap(&h);
    float bis=h.data[(h.index)];
    assert(10== value);
    assert(9 == h.data[0]);
    assert(9 == peek_heap(&h));
}

int main(int argc, char** argv) {
    testStack();
    testQueue();
    testArray();
    testHeap();

    return (EXIT_SUCCESS);
}

