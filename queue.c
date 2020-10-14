
#include <stdbool.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
void init_queue(Queue *s) {
    s->index = -1;
}

void enqueue(Queue *q, float value) {
    q->index++;
    q->data[q->index] = value;
}

float dequeue(Queue *q) {
    float donnee = q->data[0];
    float temp;
    float temp2;
    while (q->index >= 0) {
        temp = q->data[q->index - 1];
        q->data[q->index - 1] = q->data[q->index];
        q->index--;

    }
    return donnee;
}

bool is_queue_empty(Queue *q) {
    if (q->index == -1) {
        return true;
    } else return false;
}

float front(Queue *q) {
    return q->data[0];
}

void clear(Queue *q) {
    init_queue(q);
}
