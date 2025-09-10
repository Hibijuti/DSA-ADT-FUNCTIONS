#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX 10
typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main() {
    
    //main is from ai just to check hehe
    Etype list;
    EPtr L = &list;

    initialize(L);

    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 15, 1);
    insertSorted(L, 5);
    insertSorted(L, 30);

    display(L);

    printf("Locate 15: %d\n", locate(L, 15));
    printf("Retrieve pos 2: %d\n", retrieve(L, 2));

    deletePos(L, 1);
    display(L);

    makeNULL(L);
    display(L);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position > L->count){
        printf("Error");
        return;
    }
    if(L->count == MAX){
        printf("Array is full");
        return;
    }
    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i - 1];
    }
    
    L->elem[position] = data;
    L->count++;
    
}

void deletePos(EPtr L, int position){
    if(position > L->count){
        printf("Error");
        return;
    }
    for(int i = position; i < L->count; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}
int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1;
}
int retrieve(EPtr L, int position){
    if(position >= L->count){
        printf("Error");
        return -1;
    }
    
    return L->elem[position];
}

void insertSorted(EPtr L, int data){
    if (L->count == MAX) {
        printf("Error", data);
        return;
    }

    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;

    L->count++;
}
void display(EPtr L){
    for(int i = 0; i < L->count - 1; i++){
        printf("%d\n", L->elem[i]);
    }
}

void makeNULL(EPtr L){
    L->count = 0;
}
