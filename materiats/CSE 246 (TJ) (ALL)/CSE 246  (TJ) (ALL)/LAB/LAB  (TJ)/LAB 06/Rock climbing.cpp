#include<bits/stdc++.h>
using namespace std;
int minimumcost(int arr[],int n){
int dp[n];
if(n==1)return arr[0];
dp[0]=arr[0];
dp[1]=arr[1];
for(int i=2;i<n;i++){
  dp[i]=min(dp[i-1],dp[i-2])+arr[i];
}
return min(dp[n-2],dp[n-1]);

}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<minimumcost(arr,n);
}
