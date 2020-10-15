/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "heap.h"

/**
 * Fonction d'initiation du tas
 * 
 * @param h
 */
void init_heap(Heap *h) {
    return h->index = -1;
}

/**
 * Fonction de vérification si le tas est vide
 * 
 * @param h
 * @return 
 */
bool is_heap_empty(Heap *h) {
    if (-1 == (h->index)) {
        return true;
    } else {
        return false;
    }
}

/**
 * Fonction qui retire le haut du tas et qui décale tout
 * 
 * @param h
 * @return 
 */
float pop_heap(Heap *h) {
    float value = h->data[0];
    for (int i = 0; i < (h->index); i++) {
        h->data[i] = h->data[i + 1];
    }
    h->index--;
    return value;
}
/**
 * Fonction qui remplace le haut du tas doar una utre valeur et qui decale tout
 * 
 * @param h
 * @param value
 */
void push_heap(Heap *h, float value) {
    h->index++;
    for (int i = h->index; i > 0; i--) {
        h->data[i] = h->data[i - 1];
    }
    h->data[0] = value;
}

/**
 * Fonction remplacement du haut du tas
 * 
 * @param h
 * @param value
 * @return 
 */
float replace_heap(Heap *h, float value){
    h->data[0]=value;
}

/**
 * Fonction recuparation du haut du tas
 * 
 * @param h
 * @return 
 */
float peek_heap(Heap *h){
    return h->data[0];
}
