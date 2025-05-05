
#include "lab6.h"
#include <stdlib.h>
#include <stdio.h>


void print_LL(LL *list){
    int size = list->size;
    node *cur;
    cur=list->head;
    printf("list: ");
    for(int i=0;i<size;i++){
        printf("%d ", cur->data);
        cur=cur->next;
    }
}
int main(){
    int arr[]={1,2,3};
    LL *p_LL;
    //q1
    create_LL_from_data(&p_LL, arr, 3);
    print_LL(p_LL);
    append(p_LL, 3);
    print_LL(p_LL);

    //q2
    printf("The size of the recorded linked list is %d. Is the LL size equal to %d?\n", p_LL->size, p_LL->size);
    if (validate_length(p_LL)==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    //p_LL->size=3;
    printf("The size of the recorded linked list is %d. Is the LL size equal to %d?\n", p_LL->size, p_LL->size);
    if (validate_length(p_LL)==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    //q3
    print_LL(p_LL);
    delete_elem(p_LL, 3);
    print_LL(p_LL);

    char line[100];
    printf("size of line: %lf\n", sizeof(line));
}