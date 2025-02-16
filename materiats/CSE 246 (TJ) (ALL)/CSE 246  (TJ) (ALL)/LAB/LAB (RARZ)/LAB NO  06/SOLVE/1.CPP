#include<bits/stdc++.h>
using namespace std;

int dp[70];

// top down approach
// time complexity O(n2)
int lis(vector<int> &v, int i) {
    if(dp[i] != -1)
        return dp[i];
    int ans = 1;
    for(int j = 0; j < i; j++) {
        if(v[i] > v[j]) {
            ans = max(ans, lis(v, j)+ 1);
        }
    }
    return dp[i] = ans;
}

int main() {
    int N; cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, lis(v, i));
    }
    cout << ans << endl;

    return 0;
}
