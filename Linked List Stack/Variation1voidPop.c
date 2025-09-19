#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    struct Node *next;
    int data;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

Stack *initialize();
bool isEmpty();
void push();
void pop();
int peek();
void display();

int main(){
    Stack *S = initialize();
    
    push(S, 5);
    push(S, 10);
    push(S, 15);
    push(S, 20);
    display(S);
    
    pop(S);
    pop(S);
    pop(S);
    display(S);
    
    int peeked = peek(S);
    printf("%d", peeked);
    
}

Stack *initialize(){
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Empty");
        return;
    }
    
    Node *temp = s->top;
    s->top = temp->next;
    free(temp);
    
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Empty");
        return -1;
    }
    
    return s->top->data;
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Empty");
        return;
    }
    
    Node *current = s->top;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
    
}
