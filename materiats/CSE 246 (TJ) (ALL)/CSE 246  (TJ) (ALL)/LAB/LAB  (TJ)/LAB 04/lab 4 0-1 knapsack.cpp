#include<bits/stdc++.h>
using namespace std;
void knapsack(int W, int wt[], int val[], int n)
{

int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1]+ dp[i - 1][j - wt[i - 1]],dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
   for(int i=0;i<=n;i++){
 for(int j=0;j<=W;j++){
  cout<<dp[i][j]<<" ";
 }
 cout<<endl;
}
}

int main(){
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n;i++)cin>>wt[i];

/*int val[]={3,4,5,6};
int wt[]={2,3,4,5};
int w=5;*/
knapsack(w,wt,val,n);
}
