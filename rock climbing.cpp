#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void rockClimbing(vector<int> &energyCosts) {
    int n = energyCosts.size();
    if (n == 0) {
        cout << "No rocks to climb!" << endl;
        return;
    }


    vector<int> dp(n, 0);


    dp[0] = energyCosts[0];
    if (n > 1) {
        dp[1] = energyCosts[1];
    }


    for (int i = 2; i < n; i++) {
        dp[i] = energyCosts[i] + min(dp[i - 1], dp[i - 2]);
    }


    cout << "Minimum energy to reach the top: " << dp[n - 1] << endl;
}

int main() {

    vector<int> energyCosts = {10, 20, 30, 40, 50};


    rockClimbing(energyCosts);

    return 0;
}
