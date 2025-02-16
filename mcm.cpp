#include <iostream>
#include <vector>
#include <climits>

using namespace std;


    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));


    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }


    cout << "Minimum number of scalar multiplications: " << dp[0][n - 1] << endl;
}

int main() {

    vector<int> dimensions = {10, 30, 5, 60};


    matrixChainMultiplication(dimensions);

    return 0;
}
