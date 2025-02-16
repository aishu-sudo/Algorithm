#include<bits/stdc++.h>
using namespace std;
int partion(int arr[],int s,int e){
int pivot=arr[e];
int pindex=s;
for(int i=s;i<=e-1;i++){
   if(arr[i]<=pivot){
    swap(arr[i],arr[pindex]);
    pindex++;
   }

}
swap(arr[e],arr[pindex]);
return pindex;
}

void quicksort(int arr[],int s,int e){
if(s<e){

  int p=partion(arr,s,e);
  quicksort(arr,s,p-1);
  quicksort(arr,p+1,e);

}

}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
quicksort(arr,0,n-1);
for(int i=0;i<n;i++)cout<<arr[i]<<" ";

}
