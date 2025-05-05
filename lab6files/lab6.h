#if !defined(LAB6_H)
#define LAB6_H

typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct LL{
    node *head;
    int size;
} LL;

void create_LL_from_data(LL **p_LL, int *data_arr, int size);
void create_node(node **p_n, int data);
void append(LL *my_list, int new_elem);
int validate_length(LL *p_LL);
void delete_elem(LL *p_LL, int index);

#endif