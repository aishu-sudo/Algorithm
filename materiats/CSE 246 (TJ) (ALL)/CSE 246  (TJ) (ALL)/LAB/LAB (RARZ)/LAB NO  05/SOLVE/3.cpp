#include<bits/stdc++.h>
using namespace std;

long long dp[35][1005];
int wt[35], val[35];
long long knapsack(int idx, int wt_left) {
    if(wt_left == 0)
        return 0;
    if(idx < 0)
        return 0;
    if(dp[idx][wt_left] != -1)
        return dp[idx][wt_left];

    long long ans = knapsack(idx-1, wt_left);
    if(wt_left- wt[idx] >= 0)
        ans = max(ans, knapsack(idx-1, wt_left- wt[idx])+ val[idx]);
    return dp[idx][wt_left] = ans;
}

int main() {
    int N, W;
    cin >> N >> W;
    for(int i = 0; i < N; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> wt[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << knapsack(N-1, W) << endl;

    return 0;
}
