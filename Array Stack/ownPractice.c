#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct{
    int elem[MAX];
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
int main(){
    Stack *s = initialize();
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    display(s);
    int popped = pop(s);
    printf("%d\n", popped);
    int topz = peek(s);
    printf("%d\n", topz);
    
    int topped = top(s);
    printf("%d\n", topped);
    
    
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
        printf("Stackz iz full ohready");
        return;
    }
    
    s->top++;
    s->elem[s->top] = value;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stackz iz empty cant POP");
        return -1;
    }
    
    int valueNaGiPop = s->elem[s->top];
    s->top--;
    return valueNaGiPop;
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stackz iz empty cant PEK");
        return -1;
    }
    
    return s->elem[s->top];
}

int top(Stack *s){
    return s->top;
}
void display(Stack *s){
    if(isEmpty(s)){
        printf("notin to display");
        return;
    }
    
    for(int i = s->top; i >=0; i--){
        printf("%d\n", s->elem[i]);
    }
}
