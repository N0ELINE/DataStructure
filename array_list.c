/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void init_array_list(Array_list *l) {
//    struct Array_list *l = malloc(sizeof (struct Array_list));
//    l->size = 0;
//    l->data = calloc(2, sizeof (void *));
//    l->data[0] = NULL;
//    return list;
}
void insert_at(Array_list *l, int position, float value);
void add(Array_list *l, float value);
float remove_at(Array_list *l, int position);
float get_at(Array_list *l, int position);
void clear(Array_list *l);