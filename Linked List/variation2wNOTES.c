#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List *initialize();
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
    // Initialize list
    List *myList = initialize(NULL);

    // Insert elements
    insertFirst(myList, 10);
    insertLast(myList, 20);
    insertPos(myList, 15, 1); // Insert 15 at index 1

    printf("List after inserting 10, 20, 15:\n");
    display(myList);

    // Retrieve and locate
    printf("Element at index 1: %d\n", retrieve(myList, 1));
    printf("Locate 20: %d\n", locate(myList, 20));

    // Delete elements
    deleteStart(myList);
    printf("List after deleting first element:\n");
    display(myList);

    deleteLast(myList);
    printf("List after deleting last element:\n");
    display(myList);

    insertLast(myList, 25);
    insertLast(myList, 30);
    deletePos(myList, 1);
    printf("List after deleting element at index 1:\n");
    display(myList);

    // Empty the list
    empty(myList);
    printf("List after emptying:\n");
    display(myList);

    // Free the list structure itself
    free(myList);

    return 0;
}

List *initialize(){
    List *L = malloc(sizeof(List));
    L->head = NULL;
    L->count = 0;
    return L;
}

void empty(List *list){
    Node *current = list->head;
    Node *temp;
    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    list->head = temp;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
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
    if(index > list->count){
        printf("error");
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
    Node *current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}
void deleteLast(List *list){
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        list->count--;
    }else{
        Node *current = list->head;
        for(int i = 0; i < list->count - 2; i++){ // can be while (current->next->next != NULL);
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->count--;
    }
    
}

void deletePos(List *list, int index){
    if(index == 0){
        deleteStart(list);
        return;
    }
    
    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if(index >= list->count){
        printf("error");
        return -1;
    }
    
    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data){
    if(list->head == NULL){
        return -1;
    }
    int index = 0;
    Node *current = list->head;
    while(current != NULL){
        if(current->data == data){
            return index;
        }else{
        current = current->next;
        index++;
        }
    }
    return -1;
}

void display(List *list){
    Node *current = list->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

