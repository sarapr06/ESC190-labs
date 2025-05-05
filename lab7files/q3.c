#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *array;   
    int size;     //number of elements
    int capacity; //capacity before resizing
    int front;    
    int rear;     
} Queue;

// create a queue with a given initial capacity
void create_queue(Queue **q, int capacity) {
    *q = (Queue *)malloc(sizeof(Queue));
    (*q)->array = (int *)malloc(sizeof(int) * capacity);
    (*q)->size = 0;
    (*q)->capacity = capacity;
    (*q)->front = 0;
    (*q)->rear = 0;
}


void enqueue(Queue *q, int data) {
    //FOR QUESTION 4:
    if (q->size == q->capacity) {
        // Resize: Double the capacity
        q->capacity *= 2;
        q->array = (int *)realloc(q->array, sizeof(int) * q->capacity);
        printf("Queue resized to %d capacity.\n", q->capacity);
    }
    q->array[q->rear] = data;
    q->rear = (q->rear + 1) % q->capacity;  // circular increment (gets sent back to 0 after)
    q->size++;
}

// dequeue an element from the queue
int dequeue(Queue *q) {
    int removed = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;  // circular increment
    q->size--;
    return removed;
}

// print the queue elements
void print_queue(Queue *q) {
    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        if(q->array[i]!='\0'){
            printf("%d", q->array[i]);
        }
        if(i!=q->size-1){
            printf("-> ");
        }
    }
    printf("\n");
}

// free memory allocated for the queue
void destroy_queue(Queue *q) {
    free(q->array);
    free(q);
}

int main() {
    Queue *q;
    create_queue(&q, 5);  // Initial capacity = 5

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);

    dequeue(q);
    print_queue(q);

    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);  // goes around
    print_queue(q);

    destroy_queue(q);
    return 0;
}
