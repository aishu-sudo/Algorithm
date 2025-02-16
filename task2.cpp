#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] >= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        aux[k++] = arr[i++];
    }

    while (j <= high)
    {
        aux[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = aux[i];
    }
}

void divider(int arr[], int aux[], int low, int high)
{
    if (high == low)
    {
        return;
    }

    int mid = (low + high) / 2;
    divider(arr, aux, low, mid);       // split/merge the left half
    divider(arr, aux, mid + 1, high);  // split/merge the right half
    merge(arr, aux, low, mid, high);   // merge the two half runs
}



void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int pivot) {
    int x = arr[pivot];  // Choose the pivot element
    int i = low - 1;     // Start with i one position before low

    for (int j = low; j <= pivot - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr, i, j);  // Place smaller elements to the left
        }
    }

    swap(arr, i + 1, pivot);  // Place pivot in the correct position
    return i + 1;  // Return the position of the pivot
}

void quicksort(int arr[], int low, int r) {
    if (low < r) {
        int pivot = partition(arr, low, r);  // Partition the array
        quicksort(arr, low, pivot - 1);      // Sort left part
        quicksort(arr, pivot + 1, r);        // Sort right part
    }
}



int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], aux[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 1000;
    }

    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }

    clock_t start, end;

    // Mergesort time complexity
    start = clock();
    divider(arr1, aux, 0, n - 1);
    end = clock();
    double mergeSortTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Mergesort time: %lf seconds\n", mergeSortTime);

    // Quicksort time complexity
    start = clock();
    quicksort(arr2, 0, n - 1);
    end = clock();
    double quickSortTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quicksort time: %lf seconds\n", quickSortTime);

    return 0;
}

