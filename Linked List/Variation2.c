#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
typedef struct{
    Node *head;
    int count;
}List;

List* initialize(List *L);
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main() {
    // TESTING PURPOSES THE MAIN IS FROM GPT TO CHECK WHETHER CODE IS CORRECT OR NOT
    List *list = initialize(NULL);
    if(list == NULL) return 1;

    printf("Inserting at the start:\n");
    insertFirst(list, 10);
    insertFirst(list, 20);
    insertFirst(list, 30);
    display(list); // Expected: 30 20 10

    printf("\nInserting at the end:\n");
    insertLast(list, 40);
    insertLast(list, 50);
    display(list); // Expected: 30 20 10 40 50

    printf("\nInserting at position 2:\n");
    insertPos(list, 99, 2);
    display(list); // Expected: 30 20 99 10 40 50

    printf("\nDeleting first element:\n");
    deleteStart(list);
    display(list); // Expected: 20 99 10 40 50

    printf("\nDeleting last element:\n");
    deleteLast(list);
    display(list); // Expected: 20 99 10 40

    printf("\nDeleting element at position 1:\n");
    deletePos(list, 1);
    display(list); // Expected: 20 10 40

    printf("\nRetrieve index 1: %d\n", retrieve(list, 1)); // Expected: 10
    printf("Locate value 40: %d\n", locate(list, 40));   // Expected: 2
    printf("Locate value 100: %d\n", locate(list, 100)); // Expected: -1 (not found)

    printf("\nEmptying list...\n");
    empty(list);
    display(list); // Expected: nothing

    free(list); // Free the list structure itself
    return 0;
}

List* initialize(List *L){
    List *list= malloc(sizeof(List));
    if(list == NULL){
        printf("NULL");
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;

}
void empty(List *list){
    Node *current = list->head;
    Node *temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    list->head = NULL; 
    list->count = 0;     
}

void insertFirst(List *list, int data){

    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("failed");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;

}
void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("failed");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
    }else{
        Node *current = list->head;
        while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    }
    list->count++;
}
void insertPos(List *list, int data, int index){
    if(index < 0 || index > list->count){
        printf("Invalid index\n");
        return;
    }
    if(index == 0){
        insertFirst(list, data);
        return;
    }
    if(index == list->count){
        insertLast(list, data);
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    if(list->head == NULL){
        printf("Empty");
        return;
    }
    Node *current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}
void deleteLast(List *list){
    if(list->head == NULL){
        printf("list is already empty");
        return;
    }else if(list->count == 1){
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }
    else{
        Node *current = list->head;
        for(int i = 0; i < list->count - 2; i++){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->count--;
    }
}
void deletePos(List *list, int index){
    if(index < 0 || index >= list->count|| list->head == NULL){
        printf("invalid");
        return;
    }
    else if(index == 0){
        deleteStart(list);
        return;
    }else{
        Node *current = list->head;
        for(int i =0; i < index - 1; i++){
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        
        free(temp);
        list->count--;
    }
    
}

int retrieve(List *list, int index){
    if(index < 0|| list->head == NULL || index >= list->count){
        printf("Invalid");
        return -1;
    }else{
        Node *current = list->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        return current->data;
    }
}

int locate(List *list, int data){
    if(list->head == NULL){
        printf("list empty");
        return -1;
    }
    else{
        Node *current = list->head;
        int index = 0;
        
        while(current !=NULL){
            if(current->data == data){
                return index;
            }else{
                current = current->next;
                index++;
            }
        }
    }
    return -1;
}

void display(List *list){
    Node *current = list->head;
    while(current!= NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}
