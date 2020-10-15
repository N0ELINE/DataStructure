
#include "array_list.h"

///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
void init_array_list(Array_list *l) {
    
    l->index=-1;
}

void insert_at(Array_list *l, int position, float value){
    int temp;
    for(int i=(l->index); i>=position; i--){
        temp = l->data[i+1];
        l->data[i+1]=l->data[i];
        l->data[i]=temp;
    }
    
    l->index++;
    l->data[position]=value;
}

void add(Array_list *l, float value){
    l->index++;
    l->data[l->index]=value;
}

float remove_at(Array_list *l, int position){
    int temp;
    for(int i=position; i>=l->index; i++){
        temp = l->data[i+1];
        l->data[i+1]=l->data[i];
        l->data[i]=temp;
    }
    l->index--;
}

float get_at(Array_list *l, int position){
    return l->data[position];
}

void clear_array_list(Array_list *l){
    init_array_list(l);
}