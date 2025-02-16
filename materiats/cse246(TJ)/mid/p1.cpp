#include<iostream>
using namespace std;
void conquer(int arr[],int start,int mid,int endd)
{
    int n1=mid-start+1;
    int n2=endd-mid;
    int l1[n1+1];
    int l2[n2+1];
    int t=0;

    for(int i=start; i<=mid; i++)
    {
        l1[t++]=arr[i];
    }
    l1[n1]=2e9;
    t=0;
    for(int i=mid+1; i<=endd; i++)
    {
        l2[t++]=arr[i];
    }
    l2[n2]=2e9;
    int i2=0;
    int j2=0;
    for(int i=start; i<=endd; i++)
    {
        if(l1[i2]<l2[j2])
        {
            arr[i]=l1[i2++];
        }
        else
            arr[i]=l2[j2++];
    }
}
void mergee(int arr[],int start,int endd)
{
    if(start>=endd)
    {
        return;
    }
    int mid=(start+endd)/2;
    mergee(arr,start,mid);
    mergee(arr,mid+1,endd);
    conquer(arr,start,mid,endd);

}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter elements" <<i+1<<" : ";
        cin>>arr[i];

    }
    mergee(arr,0,n-1);
    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";

    }
    return 0;
}
