#include<bits/stdc++.h>
using namespace std;

long long Hill[100][100];
long long dp[500][500];

// this is top down approach
// time complexity O(m*n)
long long Hillclimb(int i, int j, int m, int n) {
    if(i >= m)
        return 0;
    if(j <= -1 || j >= n)
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];

    long long ans = Hillclimb(i+1, j-1, m, n)+ Hill[i][j];
    ans = min(ans, Hillclimb(i+1, j, m, n)+ Hill[i][j]);
    ans = min(ans, Hillclimb(i+1, j+1, m, n)+ Hill[i][j]);

    return dp[i][j] = ans;
}

int main() {
    int M, N;
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> Hill [i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    long long ans = INT_MAX;
    for(int j = 0; j < N; j++) {
        ans = min(ans, Hillclimb(0, j, M, N));
    }
    cout << ans << endl;

    return 0;
}
