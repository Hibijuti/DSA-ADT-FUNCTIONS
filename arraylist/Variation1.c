#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10 

typedef struct{
    int elem[MAX];
    int count;
}List;
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L = initialize(L);
    L = insertPos(L, 5, 0);
    L = insertPos(L, 10, 1);
    L = insertPos(L, 15, 2);
    L = insertPos(L, 20, 3);
    display(L);
    L = deletePos(L, 1);
    
    int located = locate(L, 15);
    printf("%d\n", located);
    
    L = insertSorted(L, 30);
    display(L);
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count || L.count >= MAX){
        printf("Error1");
        return L;
    }
    
    for(int i = L.count - 1; i >= position; i--){
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position >= L.count){
        printf("Error2");
        return L;
    }
    for(int i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(data == L.elem[i]){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == MAX){
        printf("FULL");
        return L;
    }
    int i;
    for(i = L.count - 1; i >= 0 && L.elem[i] > data; i--){
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d\n", L.elem[i]);
    }
}

