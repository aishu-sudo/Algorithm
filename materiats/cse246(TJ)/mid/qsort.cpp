#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int a[MAX];

int partion(int h,int r){
    int pivot=a[h];
    int i=h+1,j=r;
    while(1){
        while(a[i]<=pivot&&i<r)i++;
        while(a[j]>pivot&&j>h)j--;
        if(i<j){
            swap(a[i],a[j]);
        }
        else{
            swap(a[h],a[j]);
            return j;
        }
    }
}

void qsort(int l,int r){
    if(l>=r)return;
    int pivott=partion(l,r);
    qsort(l,pivott-1);
    qsort(pivott+1,r);
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    qsort(0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
