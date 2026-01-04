#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

/* Function prototypes */
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);

int main() {
    Stack* S = initialize();

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

/* Initialize stack */
Stack* initialize() {
    Stack* s = malloc(sizeof(Stack));
    s->top = MAX;   // stack is empty
    return s;
}

/* Check if stack is full */
bool isFull(Stack* s) {
    return s->top == 0;
}

/* Check if stack is empty */
bool isEmpty(Stack* s) {
    return s->top == MAX;
}

/* Push operation */
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is FULL\n");
        return;
    }
    s->top--;
    s->items[s->top] = value;
}

/* Pop operation */
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top++;
    return value;
}

/* Peek operation */
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY\n");
        return -1;
    }
    return s->items[s->top];
}

/* Return top index */
int top(Stack* s) {
    return s->top;
}

/* Display stack contents */
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = s->top; i < MAX; i++) {
        printf("%d\n", s->items[i]);
    }
}
