#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    struct Node *next;
    int data;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}Queue;

Queue *initialize();
bool isEmpty();
void enqueue();
int dequeue();
int front();
void display();

int main(){
    
    Queue *Q = initialize();
    
    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 15);
    enqueue(Q, 20);
    
    display(Q);
    
    int dequeued = dequeue(Q);
    display(Q);
    printf("%d", dequeued);
    int frontNow = front(Q);
    printf("\n%d", frontNow);
}

Queue *initialize(){
    Queue *Q = malloc(sizeof(Queue));
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;

    return Q;
}

bool isEmpty(Queue *q){
    return q->size == 0;
}

void enqueue(Queue *q, int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(isEmpty(q)){
        q->head = newNode;
        q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
    
    q->size++;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return -1;
    }
    Node *temp = q->head;
    int value = q->head->data;
    if(q->size == 1){
        q->head = NULL;
        q->tail = NULL;
    }else{
        
        q->head = q->head->next;
    }
    free(temp);
    q->size--;
    return value;
    
}

int front(Queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return -1;
    }
    return q->head->data;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return;
    }
    Node *current = q->head;
    while(current!= NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}
