#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int tr[1001][2001];

int Sumtest(int arr[], int n, int sum)
{

    if (sum == 0)
        return 1;

    if (n <= 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n - 1][sum];

    if (arr[n - 1] > sum)
        {   tr[n][sum]=3;
        return dp[n][sum] = Sumtest(arr, n - 1, sum);
        }
    else
    {
        if(Sumtest(arr, n - 1, sum - arr[n - 1])> Sumtest(arr, n - 1, sum)){
            tr[n][sum]=1;
            return dp[n][sum]= Sumtest(arr, n - 1, sum - arr[n - 1]);

        }
        else{
            tr[n][sum]=2;
            return dp[n][sum] = Sumtest(arr, n - 1, sum);
        }

    }
}

void traceback(int arr[], int n, int sum){
    if (n <= 0 || sum == 0)
        return;
    if(tr[n][sum]==1){
        traceback(arr,n-1,sum-arr[n-1]);
        cout<<arr[n-1];
        cout<<", ";
    }
    else if(tr[n][sum]==2){
        traceback(arr, n - 1, sum);
    }
    else if(tr[n][sum]==3){
        traceback(arr, n - 1, sum);
    }

}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 5;
    int arr[] = {7, 3, 2, 5, 8};
    int sum = 14 ;

    if (Sumtest(arr, n, sum))
    {
        cout<<"YES"<<endl;
    }
    else
       {cout<<"NO"<<endl;}
    traceback(arr, n, sum);



}

