//the implimentation of append in linkedlist.c,
#include "lab6.h"
#include<stdlib.h>
#include<stdio.h>

//from lecture:
void create_node(node **p_n, int data){
    *p_n=(node*)malloc(sizeof(node));
    if(!*p_n){
        printf("ERROR creating p_n");
        exit(1);
    }
    (*p_n)->data = data;
    (*p_n)->next=NULL;//dont know what it is rn
}

void create_LL_from_data(LL **p_LL, int *data_arr, int size){
    //in main, you want to say LL *myLL and then do create_LL_from_data(&myLL) 
    // -> uses pointer to pointer
    
    //crate LL:
    *p_LL  = (LL*)malloc(sizeof(LL));
    if(!*p_LL){
        printf("ERROR creating p_n");
        exit(1);
    }
    (*p_LL)->head = NULL;//first is NULL
    (*p_LL)->size=size;//set the size to what you're entering
    //you would call using create_LL_from_data(&p_LL, data_arr, size)

    int i =0;//nodes inserted so far
    node *prev=NULL;
    while(i<size){
        node *cur;
        create_node(&cur, data_arr[i]);
        if(i==0){ //first node is special, because no nodes so far
            (*p_LL)->head = cur;
            //keep setting cur to be address of new thing we created
            // want (*p_LL)->head to be address of first node
            //so we CREATE first node then we link!!
        }else{
            //need to set next address to current address
            prev->next = cur;
        }
        prev = cur;//change for the next one
        i++;
    }
}

//q1: 
//Re-do Problem 1 from the 2023 midterm, with one change: 
//put the declaration of structs in a separate h file, yes
//the implimentation of append in linkedlist.c, 
//and implement testing in test linkedlist.c.
void append(LL *my_list, int new_elem){
    if(my_list->head == NULL){
        node *new_node = (node*)malloc(sizeof(node));
        if(!new_node){
            printf("ERROR creating p_n");
            exit(1);
        }
        new_node->data=new_elem;
        new_node->next=NULL;
        my_list->head=new_node;
        my_list->size++;
        return;
    }
    node *cur = my_list->head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    //now at the null
    node *new_node=(node*)malloc(sizeof(node));
    
    cur->next=new_node;
    new_node->data = new_elem;
    new_node->next=NULL;
    my_list->size++;

}

//q2: 
//Implement a validate list length function from the linked list. 
//The function should return 1 if the length of the linked list matches 
//the recorded length (by going through the list and counting the nodes),
//and 0 otherwise.
int validate_length(LL *p_LL){
    node *cur=p_LL->head;
    int count=0;
    while(cur!=NULL){
        cur=cur->next;
        count++;
    }
    if(count == p_LL->size){
        return 1;
    }
    return 0;
}

//q3: 
//Implement a delete function for the linked list. 
//The function should take an index of a node that needs
//to be deleted, and update the linked list to remove the 
//node. Make sure to free the removed node.
void delete_elem(LL *p_LL, int index){
    node *cur = p_LL->head;
    node *prev=NULL;
    if(index==0){
        p_LL->head=cur->next;
        free(cur);
        p_LL->size--;
        return;
    }
    for(int i=0; i<index; i++){
        prev=cur;
        cur=cur->next;
    }//now at the index
    if(cur->next==NULL){//the last one is deleted
        prev->next = NULL;
        free(cur);
        p_LL->size--;
    }
    else{
    //it's not hte last one
        prev->next=cur->next;
        p_LL->size--;
        free(cur);  
    }
    
    
}