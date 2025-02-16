#include<bits/stdc++.h>
using namespace std;

int dp[50][50];

// this is top down approach
// time complexity O(n3)
int mcm(int i, int j, vector<int> &v) {
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for(int k = i; k < j; k++)
        mini = min(mini, (v[i-1]* v[k]* v[j])+ mcm(i, k, v)+ mcm(k+1, j, v));

    return dp[i][j] = mini;
}

int main() {
    int N; cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(i == 0) {
            v.push_back(x);
            v.push_back(y);
            continue;
        }
        v.push_back(y);
    }

    memset(dp, -1, sizeof(dp));
    cout << mcm(1, N, v) << endl;

    return 0;
}

