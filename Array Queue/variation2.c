#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

/* Function prototypes */
Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
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

/* Initialize queue */
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    return q;
}

/* Check if queue is empty */
bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

/* Check if queue is full */
bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

/* Enqueue operation */
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

/* Dequeue operation */
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

/* Return front element */
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

/* Display queue contents */
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
