#include<bits/stdc++.h>
using namespace std;

int dp[10010];

int minCoins(int amount, vector<int> coins) {
    if(amount == 0)
        return amount;
    if(dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for(auto coin: coins)
        if(amount-coin >= 0)
            ans = min(ans+0LL, minCoins(amount-coin, coins)+1LL);
    return dp[amount] = ans;
}

int main() {
    int N, K;
    vector<int> coins;
    cin >> N >> K;
    while(N--) {
        int coin; cin >> coin;
        coins.push_back(coin);
    }
    memset(dp, -1, sizeof(dp));
    cout << minCoins(K, coins) << endl;

    return 0;
}
