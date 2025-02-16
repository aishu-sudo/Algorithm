#include <bits/stdc++.h>
#include <string.h>
using namespace std;



int minElements(int arr[], int n)
{
    // calculating HALF of array sum
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];
    halfSum = halfSum / 2;

    // sort the array in descending order.
     int temp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {

        curr_sum += arr[i];
        res++;

        // current sum greater than sum
        if (curr_sum > halfSum)
            return res;
    }
    return res;
}

// Driver function
int main()
{
    int arr[] = { 3, 1, 7, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}
