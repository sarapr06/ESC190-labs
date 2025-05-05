#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

//memmove(pointer to array where content copied, pointer to source data to be copied, number bytes)
//memcpy(pointer to array where content to be copied, pointer to data to be copied, number of byte to be copied)
//memcpy: destination CANNOT overlap with source at all, while in memmove it can
//in mempy, if hte destination overlaps after the source, some addresses will be overwritten before copied
//memmove detects this and copies in other directions if overlap

//go to intlist for the header


// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    *p_IntList = (IntList *)malloc(sizeof(IntList));
    if(*p_IntList==NULL){
        printf("ERROR: cannot copy array");
        exit(1);
    }
    (*p_IntList)->capacity = 100;
    (*p_IntList)->data = (int*)malloc(sizeof(int)*(*p_IntList)->size);
    if((*p_IntList)->data==NULL){
        printf("ERROR: failed to create block");
        exit(1);
    }
    (*p_IntList)->size = size;
    memmove((*p_IntList)->data, data_arr, size*sizeof(int));

}

// Append new_elem to the end of list
void list_append(IntList *list, int new_elem){
    if(list->capacity<list->size+1){
        int new_cap=2*(list->capacity+1);
        list->data = (int*)realloc(list->data,new_cap*sizeof(int));
        if(list->data==NULL){
            printf("ERROR: too large while appending");
            exit(1);
        }
        list->capacity=new_cap;
        
    }
    (list->data)[list->size]=new_elem;
    list->size +=1;

}

// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index){
    if(list->capacity<list->size+1){
        int new_cap=2*(list->capacity);
        list->data = (int*)realloc(list->data,new_cap*sizeof(int));
        if(list->data==NULL){
            printf("ERROR: too large while appending");
            exit(1);
        }
        list->capacity=new_cap;
    }
    printf("Before Insert: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    
   // Shift elements to the right
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int));

    // Insert the new element
    list->data[index] = new_elem;

    // Increase the size
    list->size++;
    printf("After Insert: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// Delete the element at index index
void list_delete(IntList *list, int index){
    /* BEFORE:
    int *placeholder = (int *)malloc(sizeof(int)*(list->size));
    for(int i=0;i<list->size; i++){
        if(i==index){
            (placeholder)[i]=(list->data)[i+1];
            i++;
        }else{
            (placeholder)[i]=(list->data)[i];
        }
        }
    memmove(list->data, placeholder, sizeof(int)*(list->size));
    list->size -=1;
    free(placeholder);
    */

   if (index < 0 || index >= list->size) { //invalid indexes
        printf("ERROR: Index out of bounds\n");
        return;
    }
    
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int)); // Shift elements left to overwrite the element at 'index'
    // Decrease size
    list->size--;
}

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list){
    
   if (list != NULL) { //if hte pointer points to an address
        free(list->data);  // free the dynamically allocated array
        free(list);        // free the struct itself
    }

}

// Return the element at index index in list
int list_get(IntList *list, int index){
    if(index>list->size){
        printf("ERROR: invalid index");
        exit(1);
    }
    int res = (list->data)[index];
    return res;
}

