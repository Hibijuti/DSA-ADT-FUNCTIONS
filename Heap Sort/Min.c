#include <stdio.h>

/* Swap helper */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Min-heapify */
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

/* Heap Sort */
void heapSort(int arr[], int n) {
    /* Build min heap */
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Extract elements */
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array (descending):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
