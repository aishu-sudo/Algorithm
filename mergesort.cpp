#include <stdio.h>

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

void merge(int arr[],int aux[],int low,int mid,int high)
{
    int k=low,i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            aux[k++]=arr[i++];
        }
        else
        {
            aux[k++]=arr[j++];
        }
    }

    while(i<=mid)
    {
        aux[k++]=arr[i++];
    }

     while (j <= high) {
        aux[k++] = arr[j++];
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=aux[i];
    }

}


// Function declarations here (for divider and merge)

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n], aux[n];  // Declare both 'a' and 'aux' arrays

    for (int i = 0; i < n; i++) {
        a[i]=rand()%1000; //Test sorting algorithms on unpredictable data and Avoiding Hardcoded Data
    }

    divider(a, aux, 0, n - 1);

    printf("\n\nAfter implementing Merge sort, Sorted List is :: \n\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
