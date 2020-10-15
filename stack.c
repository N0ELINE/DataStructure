/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

/**
 * Fonction initialisation stack pointeur
 * 
 * @param s
 */
void init_stack(Stack *s){
    s->index=-1;
}

/**
 * Fonction mettre un élément dans la pile si la pile n'est pas pleine
 * 
 * @param s
 * @param value
 */
void push(Stack *s, float value) {
    s->index++;
    s->data[s->index] = value;
}

/**
 * Fonction enlève le premier élément du stack
 * 
 * @param s
 * @return value
 */
float pop(Stack *s){
    float value = s->data[s->index];
    s->index--;
    return value;
}

/**
 * Fonction qui vérifie si le stack est vide
 * @param s
 * @return 
 */
bool is_stack_empty(Stack *s){
    if (-1 == s->index )
    {
        return true;
    }
    else{
        return false;
    }
}

/**
 * Fonction recupere le premier élément du stack
 * 
 * @param s
 * @return 
 */
float peek(Stack *s){
    return s->data[s->index];
}

/**
 * Fonction qui duplique le premier élément de la pile
 * 
 * @param s
 */
void dup(Stack *s){
    float value = s->data[s->index];
    push(s , value);
}

/**
 * Fonction qui echange les deux premiers elements de la pile(du stack)
 * 
 * @param s
 */
void swap(Stack *s){
    float value1 = s->data[s->index];
    pop(s);
    float value2 = s->data[s->index];
    pop(s);
    push(s, value1);
    push(s, value2);
}

/**
 * Fonction qui clear le stack
 * 
 * @param s
 */
void clear(Stack *s){
    init_stack(s);
}