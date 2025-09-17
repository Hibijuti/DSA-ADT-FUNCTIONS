#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack *initialize();
bool isEmpty();
bool isFull();
void push();
int pop();
int peek();
void display();

int main(){
    Stack *s = initialize();
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    
    display(s);
    int poppedValue = pop(s);
    printf("%d", poppedValue);
    printf("\n\n");
    display(s);
    
    int peekValue = peek(s);
    printf("\n\n%d", peekValue);
}

Stack *initialize(){
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

bool isFull(Stack *s){
    return false; //linked list can never be full
}

void push(Stack *s, int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("notin to pop cuz empty");
        return -1;
    }
    
    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("notin to peek cuz empty");
        return -1;
    }
    
    return s->top->data;
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("cant print cuz empty");
        return;
    }
    Node *temp = s->top;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}



