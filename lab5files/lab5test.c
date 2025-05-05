#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

int main(){
    int arr[] = {1,2,34};
    IntList *p_p_s;
    create_list_from_data(&p_p_s, arr, 3);
    printf("array: ");
    for(int i =0;i<3;i++){
        printf("%d ", (p_p_s->data)[i]);
    }
    printf("\n");
    printf("end of function 1\n\n");

    int new_elem=5;
    list_append(p_p_s, new_elem);
    printf("array: ");
    for(int i =0;i<4;i++){
        printf("%d ", (p_p_s->data)[i]);
    }
    printf("\n");
    printf("end of function 2\n\n");

    int index = 1;
    list_insert(p_p_s, new_elem, index);
    printf("end of function 3\n\n");

    list_delete(p_p_s, index);
    printf("array: ");
    for(int i =0;i<4;i++){
        printf("%d ", (p_p_s->data)[i]);
    }
    printf("\n");
    printf("end of function 4\n\n");

    
    //list_destroy(p_p_s);
    //printf("d\n", (*(p_p_s)->data)[0]); // segmentation fault
    
   int res = list_get(p_p_s, index);
    printf("result at index %d is: %d\n", index, res);
    printf("end of function 5\n");

}