#include<iostream>
using namespace std;
void mergeall(int arr[],int p,int q,int r)
{
    int L[100];
    int R[100];
    int i,j,k;
    int n=0;
    for (i=p; i<=q; i++)
    {
        L[n]=arr[i];
        n++;
    }
    L[n]=999999;
    n=0;
    for (i=q+1; i<=r; i++)
    {
         R[n]=arr[i];
        n++;
    }
     R[n]=999999;
    n=0;

     i=0;
    j=0;

    for(k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
    }
}
    void MergeSort(int arr[], int p, int r){
        if (p<r){
        int q=(p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        mergeall(arr,p,q,r);
    }

}
int main()
{
    int arr[]={5,2,4,7,1,3,2,6};
    int p=0;
    int r=7;
    MergeSort(arr,0,7);
    cout<<"Array :"<<endl;
    for(int i=0;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }

}
