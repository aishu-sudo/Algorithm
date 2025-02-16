#include <stdio.h>

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];  // pivot element
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i + 1, r);
    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {12, 7, 14, 9, 10, 11};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, size);

    quicksort(A, 0, size - 1);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
