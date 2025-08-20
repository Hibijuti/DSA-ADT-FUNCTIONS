#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int pos, int data);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    L.count = 0;
    L = initialize(L);

    L = insertPos(L, 0, 10);
    L = insertPos(L, 1, 20);
    L = insertPos(L, 2, 30);

    display(L);

    L = deletePos(L, 1);
    display(L);

    int loc = -1;
    loc = locate(L, 20);
    printf("%d", loc);
    
    return 0;
}

List initialize(List L) {
    for (int i = 0; i < MAX; i++) {
        L.elem[i] = -1;
    }
    L.count = 0;
    return L;
}

List insertPos(List L, int pos, int data) {

    for (int i = L.count; i > pos; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position) {
    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data){
    for(int i = 0; i < MAX; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
