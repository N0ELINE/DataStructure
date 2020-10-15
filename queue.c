
#include <stdbool.h>
#include "queue.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Initialisation de la queue
 * 
 * @param q
 */
void init_queue(Queue *q) {
    q->index = -1;
}

/**
 * Fonction d'ajout d'un élément dans la queue
 * 
 * @param q
 * @param value
 */
void enqueue(Queue *q, float value) {
    q->index++;
    q->data[q->index] = value;
}

/**
 * Enlever enlever le premier élément de la queue
 * 
 * @param q
 * @return 
 */
float dequeue(Queue *q) {
    float value = q->data[q->index];
    q->index--;
    return value;
}

bool is_queue_empty(Queue *q) {
    if (q->index == -1) {
        return true;
    } else return false;
}

float front(Queue *q) {
    return q->data[q->index];
}

void clear_queue(Queue *q) {
    init_queue(q);
}
