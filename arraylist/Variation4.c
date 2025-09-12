#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;
void initialize(List *L);
void resize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
void insertSorted(List *L, int data);
void display(List *L);
void makeNULL(List *L);
int main() {
    List L;
    initialize(&L);

    insertSorted(&L, 30);
    insertSorted(&L, 10);
    insertSorted(&L, 20);
    insertSorted(&L, 50);
    insertSorted(&L, 40);

    printf("List after insertSorted: ");
    display(&L); // Expected: 10 20 30 40 50

    insertPos(&L, 99, 2);
    printf("List after insertPos at index 2: ");
    display(&L); // Expected: 10 20 99 30 40 50

    deletePos(&L, 3);
    printf("List after deletePos at index 3: ");
    display(&L); // Expected: 10 20 99 40 50

    printf("Locate 99: index %d\n", locate(&L, 99));

    makeNULL(&L); // free memory

    return 0;
}

void initialize(List *L) {
    L->elemPtr = malloc(sizeof(int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L) {
    int newMax = L->max * 2;
    int *newArr = malloc(sizeof(int) * newMax);

    for (int i = 0; i < L->count; i++) {
        newArr[i] = L->elemPtr[i];
    }

    free(L->elemPtr);
    L->elemPtr = newArr;
    L->max = newMax;
}

void insertPos(List *L, int data, int position) {
    if (position > L->count || position < 0) {
        printf("Error\n");
        return;
    }
    if (L->count == L->max) {
        resize(L);
    }

    for (int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position) {
    if (position >= L->count || position < 0) {
        printf("Error\n");
        return;
    }

    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (data == L->elemPtr[i]) {
            return i;
        }
    }
    return -1;
}

void insertSorted(List *L, int data) {
    if (L->count == L->max) {
        resize(L);
    }

    int i = L->count - 1;
    while (i >= 0 && L->elemPtr[i] > data) {
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void makeNULL(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}
