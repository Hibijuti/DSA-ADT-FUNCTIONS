#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} PriorityQueue;

/* Function prototypes */
PriorityQueue* initialize();
int isFull(PriorityQueue* pq);
int isEmpty(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, int elem);
int dequeue(PriorityQueue* pq);
int peek(PriorityQueue* pq);
void display(PriorityQueue* pq);

PriorityQueue* initialize() {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->count = 0;
    return pq;
}

int isFull(PriorityQueue* pq) {
    return pq->count == MAX;
}

int isEmpty(PriorityQueue* pq) {
    return pq->count == 0;
}

/* Enqueue based on priority (higher value = higher priority) */
void enqueue(PriorityQueue* pq, int elem) {
    if (isFull(pq)) {
        printf("PRIORITY QUEUE IS FULL!\n");
        return;
    }

    int i = pq->count - 1;

    /* Shift lower-priority elements */
    while (i >= 0 && pq->items[i] < elem) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }

    pq->items[i + 1] = elem;
    pq->count++;

    printf("Successfully queued %d\n", elem);
}

/* Remove highest priority element */
int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PRIORITY QUEUE IS EMPTY!\n");
        return -1;
    }

    int value = pq->items[0];

    /* Shift elements left */
    for (int i = 1; i < pq->count; i++) {
        pq->items[i - 1] = pq->items[i];
    }

    pq->count--;
    return value;
}

/* Peek highest priority */
int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PRIORITY QUEUE IS EMPTY!\n");
        return -1;
    }
    return pq->items[0];
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("PRIORITY QUEUE IS EMPTY!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->count; i++) {
        printf("%d\n", pq->items[i]);
    }
}

int main() {
    PriorityQueue* pq = initialize();

    int elem, choice = 0;

    while (choice != 5) {
        printf("\nWHAT TO DO:\n"
               "[1] ENQUEUE\n"
               "[2] DEQUEUE\n"
               "[3] CHECK HIGHEST PRIORITY\n"
               "[4] DISPLAY\n"
               "[5] EXIT\n\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element: ");
            scanf("%d", &elem);
            enqueue(pq, elem);
        }
        if (choice == 2) {
            elem = dequeue(pq);
            if (elem != -1)
                printf("Dequeued %d\n", elem);
        }
        if (choice == 3) {
            elem = peek(pq);
            if (elem != -1)
                printf("Highest priority is %d\n", elem);
        }
        if (choice == 4) {
            display(pq);
        }
    }

    free(pq);
    return 0;
}
