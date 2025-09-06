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
    printf("Location of 20: %d\n", loc);

    // Test insertSorted
    L = insertSorted(L, 15);
    L = insertSorted(L, 5);
    L = insertSorted(L, 40);
    display(L);

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
    if (L.count >= MAX) {
        printf("List is full, cannot insert.\n");
        return L;
    }
    if (pos < 0 || pos > L.count) {
        printf("Invalid position.\n");
        return L;
    }

    for (int i = L.count; i > pos; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position.\n");
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;  // found
        }
    }
    return -1; // not found
}

List insertSorted(List L, int data) {
    if (L.count >= MAX) {
        printf("List is full, cannot insert.\n");
        return L;
    }

    int pos = 0;
    while (pos < L.count && L.elem[pos] < data) {
        pos++;
    }

    // shift elements to the right
    for (int i = L.count; i > pos; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
