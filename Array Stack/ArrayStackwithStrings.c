#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack functions
Stack* initialize() {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is FULL\n");
        return;
    }
    s->items[++s->top] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY\n");
        return '\0';
    }
    return s->items[s->top--];
}

void freeStack(Stack *s) {
    free(s);
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    Stack *S = initialize();

    // Push all characters into the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(S, str[i]);
    }

    printf("Reversed string: ");
    // Pop characters from the stack to reverse
    while (!isEmpty(S)) {
        printf("%c", pop(S));
    }
    printf("\n");

    freeStack(S);
    return 0;
}
