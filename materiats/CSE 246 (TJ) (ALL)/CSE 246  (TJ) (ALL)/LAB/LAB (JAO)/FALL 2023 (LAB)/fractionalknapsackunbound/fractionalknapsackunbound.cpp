#include<iostream>

using namespace std;
int dp[100][100];

int Knapsack(int v[], int w[], int n, int cap){

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]= -1;
        }
    }

    if(n==0 || cap==0){
        return dp[n][cap]=0;
    }
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }else{
    if(w[n]<=cap){
        return dp[n][cap]= max(v[n]+Knapsack(v,w,n, cap-w[n]), Knapsack(v,w,n-1,cap));
    }else{
        return dp[n][cap]=Knapsack(v,w,n-1,cap);
    }
  }
}

int main(){
    int n=4;
    int v[]={12,7,10,100};
    int w[]={5,3,2,25};
    int cap=10;

    int profit=Knapsack(v,w,4,10);
    cout << "Your maximum profit is :"<<profit;
}
