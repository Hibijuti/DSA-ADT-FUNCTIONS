#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack *initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void display(Stack *s);

int main() {
    Stack *S = initialize();

    push(S, 10);
    push(S, 20);
    push(S, 30);

    display(S);

    printf("Peek = %d\n", peek(S));
    printf("Pop = %d\n", pop(S));
    printf("Peek after pop = %d\n", peek(S));
    printf("Top index = %d\n", top(S));

    display(S);

    free(S);
    return 0;
}

Stack *initialize(){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack *s){
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack is FULL");
        return;
    }
    
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Empty");
        return -1;
    }
    
    return s->items[s->top];
    
}

int top(Stack *s){
    return s->top;
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Empty");
        return;
    }
    
    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->items[i]);
    }
}
