#include <iostream>
#include <cstring>

using namespace std;

int dp[100][100];

int lcs(char* X, char* Y, int m, int n) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

void traceback(char* X, char* Y, int m, int n) {
    int i = m, j = n;
    string lcsResult = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsResult = X[i - 1] + lcsResult;
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << lcsResult;
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n) << endl;
    cout << "LCS is :" << endl;
    traceback(X, Y, m, n);

    return 0;
}
