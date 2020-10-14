/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

/**
 * Fonction initialisation stack pointeur
 * @param s
 */
void init_stack(Stack *s){
    s->index=0;
}

/**
 * Fonction mettre un élément dans la pile si la pile n'est pas pleine
 * 
 * @param s
 * @param value
 */
void push(Stack *s, float value) {
    s[(s->index)++] = value;
}

/**
 * Fonction enlève le premier élément du stack
 * 
 * @param s
 * @return 
 */
float pop(Stack *s){
    return s[--(s->index)];
}

/**
 * Fonction qui vérifie si le stack est vide
 * @param s
 * @return 
 */
bool is_stack_empty(Stack *s){
    return s->index == size ? true : false;
}

/**
 * Fonction recupere le premier élément du stack
 * 
 * @param s
 * @return 
 */
float peek(Stack *s){
    return s[s->index];
}

/**
 * Fonction qui duplique le premier élément de la pile
 * 
 * @param s
 */
void dup(Stack *s){
    s[(s->index)++] = s[s->index];
}

/**
 * Fonction qui echange les deux premiers elements de la pile(du stack)
 * 
 * @param s
 */
void swap(Stack *s){
    int temp = s[s->index];
    s[s->index] = s[s->index-1];
    s[s->index-1] = temp;
}

/**
 * Fonction qui clear le stack
 * 
 * @param s
 */
void clear(Stack *s){
    s->index=-1;
}