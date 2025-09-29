#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
int main() {
    Queue* q = initialize();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    display(q);

    printf("Front of the queue: %d\n", front(q));

    printf("Dequeued value: %d\n", dequeue(q));
    display(q);

    enqueue(q, 20);
    display(q);

    free(q);
    return 0;
}

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->list.items[q->front];
    if (q->list.count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    q->list.count--;
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->list.items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < q->list.count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->list.items[index]);
    }
    printf("\n");
}
