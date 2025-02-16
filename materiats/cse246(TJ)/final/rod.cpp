#include<bits/stdc++.h>
using namespace std;

int solution(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int ind = i; ind <= j; ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] + solution(i, ind - 1, cuts, dp) + solution(ind + 1, j, cuts, dp);
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

int cut(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    return solution(1, c , cuts, dp);
}

int main() {
    int n = 15;
   vector<int> cuts = {8, 11, 3, 2};
    cout << cut(n, cuts) << endl;
    return 0;
}



