#include<bits/stdc++.h>
using namespace std;
void mcm(int arr[],int n){
int result[n+1][n+1];
for(int i=1;i<n;i++)result[i][i]=0;
int j;
for(int l=2;l<n;l++){
   for(int i=1;i<n-l+1;i++){
      j=i+l-1;
      result[i][j]=INT_MAX;
      for(int k=i;k<=j-1;k++){
        int cost=result[i][k]+result[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
        if(cost<result[i][j])result[i][j]=cost;
      }

   }

}
for(int i=1;i<n;i++){
  for(int j=1;j<n;j++){
   cout<<result[i][j]<<" ";
  }
  cout<<endl;
}
//cout<<result[1][n-1];
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)cin>>arr[i];
    mcm(arr,n);



}
