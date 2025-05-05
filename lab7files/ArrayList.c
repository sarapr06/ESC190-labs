
#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>


void create_list(AL **list){
    *list = (AL *)malloc(sizeof(AL));
    (*list)->array = (int *)malloc(sizeof(int) * 10);
    (*list)->size = 0;
    (*list)->capacity = 10;
}

void destroy_list(AL *list){
    free(list->array);
    free(list);
}

void insert_list(AL *list, int data){
    if(list->size == list->capacity){
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, sizeof(int) * list->capacity);
    }
    list->array[list->size++] = data;
}

void print_list(AL *list){
    for(int i = 0; i < list->size; i++){
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void delete_list(AL *list, int data){
    int i = 0;
    for(i = 0; i < list->size; i++){
        if(list->array[i] == data){
            break;
        }
    }
    if(i == list->size){
        return;
    }
    for(int j = i; j < list->size - 1; j++){
        list->array[j] = list->array[j + 1];
    }
    list->size--;
}

void delete_list_ind(AL *list, int index){
    if(index < 0 || index >= list->size){
        return;
    }
    for(int i = index; i < list->size - 1; i++){
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}

// typedef struct ArrayList{
//     int *array;
//     int size;
//     int capacity;
// } AL;

// void create_list(AL **list);
// void destroy_list(AL *list);


// void insert_list(AL *list, int data);
// void print_list(AL *list);
// void delete_list(AL *list, int data);
// void destroy_list(AL *list);