#include<stdio.h>
#include<stdlib.h>

#define LENGTH 10 
typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);


int main() {
    //MAIN FROM AI JUST FOR CHECKING PURPOSES
    List L = initialize(L);

    printf("=== Testing insertPos ===\n");
    L = insertPos(L, 10, 0);   // insert 10 at pos 0
    L = insertPos(L, 20, 1);   // insert 20 at pos 1
    L = insertPos(L, 30, 2);   // insert 30 at pos 2
    display(L); printf("\n");  // Expected: 10 20 30

    printf("\n=== Testing deletePos ===\n");
    L = deletePos(L, 1);       // delete element at index 1 (value 20)
    display(L); printf("\n");  // Expected: 10 30

    printf("\n=== Testing insertSorted ===\n");
    L = insertSorted(L, 25);   // insert 25 in sorted order
    L = insertSorted(L, 5);    // insert 5 in sorted order
    L = insertSorted(L, 40);   // insert 40 in sorted order
    display(L); printf("\n");  // Expected: 5 10 25 30 40

    printf("\n=== Testing locate ===\n");
    int idx = locate(L, 25);
    if (idx != -1)
        printf("25 found at index %d\n", idx); // Expected: index 2
    else
        printf("25 not found\n");

    idx = locate(L, 100);
    if (idx != -1)
        printf("100 found at index %d\n", idx);
    else
        printf("100 not found\n"); // Expected: not found

    printf("\n=== Testing resize (insert many elements) ===\n");
    for (int i = 50; i <= 200; i += 10) {
        L = insertSorted(L, i);
    }
    display(L); printf("\n");  // Should print sorted list with extra values

    return 0;
}

List initialize(List L){
    L.elemPtr = malloc(sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count){
        printf("Error");
        return L;
    }
    if(L.count == L.max){
        L = resize(L);
    }
    
    for(int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position >= L.count){
        printf("Error");
        return L;
    }
    
    for(int i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(data == L.elemPtr[i]){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == L.max){
        L = resize(L);
    }
    int i = L.count - 1;
    while(i >= 0 && L.elemPtr[i] > data){
        L.elemPtr[i + 1] = L.elemPtr[i];
        i--;
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
}

List resize(List L){
    int newMax = L.max * 2;
    int *newArr = malloc(sizeof(int) * newMax);
    
    for(int i = 0; i < L.count; i++){
        newArr[i] = L.elemPtr[i];
    }
    
    free(L.elemPtr);
    L.elemPtr = newArr;
    L.max = newMax;
    return L;
}
