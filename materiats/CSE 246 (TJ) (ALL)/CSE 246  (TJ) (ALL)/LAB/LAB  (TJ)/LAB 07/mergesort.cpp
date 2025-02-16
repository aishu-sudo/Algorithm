#include<bits/stdc++.h>
using namespace std;
void mergearray(int arr[],int l,int m,int r){
int l1=m-l+1,l2=r-m;
int left[l1],right[l2];
for(int i=0;i<l1;i++)left[i]=arr[l+i];
for(int j=0;j<l2;j++)right[j]=arr[m+1+j];
int i=0,j=0,k=l;
while(i<l1 && j<l2){

  if(left[i]<=right[j]){
    arr[k]=left[i];
    i++;
  }
    else{
        arr[k]=right[j];
        j++;

    }
    k++;
}
 while (i <l1) {
        arr[k]=left[i];
        i++;
        k++;
    }
while (j < l2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
if(l<r){
int m=(l+r)/2;
mergesort(arr,l,m);
mergesort(arr,m+1,r);
mergearray(arr,l,m,r);
}
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
mergesort(arr,0,n-1);
for(int i=0;i<n;i++)cout<<arr[i]<<" ";

}

