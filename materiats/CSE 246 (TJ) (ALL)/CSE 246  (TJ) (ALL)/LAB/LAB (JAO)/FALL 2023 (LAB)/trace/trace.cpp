#include<iostream>

using namespace std;
int dp[100][100];
int trace[100][100];

int Knapsack(int v[], int w[], int n, int cap){

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]= -1;
        }
    }

    if(n==0 || cap==0){
        return dp[n][cap]=0;
    }
    if(dp[n][cap]!=-1)
        return dp[n][cap];

   else{
        if(w[n]<=cap){
        int l1=(v[n]+Knapsack(v,w,n, cap-w[n]));
        int l2= Knapsack(v,w,n-1,cap);

    if(l1>=l2){
        dp[n][cap]=l1;
        trace[n][cap]=1;
            return dp[n][cap];

  }
  else{
         dp[n][cap]=l2;
        trace[n][cap]=0;
        return dp[n][cap];
     }
}
 else if (w[n]>cap)
    {
        trace [n][cap]=0;
        return dp[n][cap]=Knapsack(v,w,n-1,cap);

    }
        }
}
void traceback(int v[], int w[], int n, int cap){
     if(n==0 || cap==0)
        return;
        if(trace [n][cap]==1){
            return traceback(v,w,n, cap-w[n]);
            cout<<n;

        }
        else {
         traceback(v,w,n-1,cap);
        }
     }

 int main(){
    int n=4;
    int v[]={12,7,10,100};
    int w[]={5,3,2,10};
    int cap=10;

    int profit=Knapsack(v,w,4,10);
    cout << "Your maximum profit is :"<<profit<<endl;;
    traceback(v,w,4,10);
}
