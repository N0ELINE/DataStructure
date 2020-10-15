
#include "array_list.h"

///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//

/**
 * Fonction initiation d'une array list
 * 
 * @param l
 */
void init_array_list(Array_list *l) {

    l->index = -1;
}

/**
 * Fonction inserer une valeur a une certaine place
 * 
 * @param l
 * @param position
 * @param value
 */
void insert_at(Array_list *l, int position, float value) {
    int temp;
    for (int i = (l->index); i >= position; i--) {
        temp = l->data[i + 1];
        l->data[i + 1] = l->data[i];
        l->data[i] = temp;
    }
    l->index++;
    l->data[position] = value;
}

/**
 * Fonction ajout d'une valeur dans la liste
 * 
 * @param l
 * @param value
 */
void add(Array_list *l, float value) {
    l->index++;
    l->data[l->index] = value;
}

/**
 * Fonction retrait d'une valeur de la liste
 * 
 * @param l
 * @param position
 * @return value
 */
float remove_at(Array_list *l, int position) {
    float temp;
    float value = l->data[position];
    for (int i = position; i <= (l->index); i++) {
        temp = l->data[i + 1];
        l->data[i + 1] = l->data[i];
        l->data[i] = temp;
    }
    l->index--;
    return value;
}

/**
 * Fonction recuperer une valeur a une cetaine position
 * 
 * @param l
 * @param position
 * @return 
 */
float get_at(Array_list *l, int position) {
    return l->data[position];
}

/**
 * Fonction de nettoyage d'un tableau
 * 
 * @param l
 */
void clear_array_list(Array_list *l) {
    init_array_list(l);
}