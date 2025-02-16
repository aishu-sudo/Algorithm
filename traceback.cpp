#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(101, vector<int>(101, -1));
vector<vector<int>> trace(101, vector<int>(101, 0));

int lcs(string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (x[n - 1] == y[m - 1]) {
        trace[n][m] = 1;
        return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
    } else {
        if (lcs(x, y, n, m - 1) >= lcs(x, y, n - 1, m)) {
            trace[n][m] = 2;
            return dp[n][m] = lcs(x, y, n, m - 1);
        } else {
            trace[n][m] = 3;
            return dp[n][m] = lcs(x, y, n - 1, m);
        }
    }
}

void trackback(string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return;
    }
    if (trace[n][m] == 1) {
        trackback(x, y, n - 1, m - 1);
        cout << x[n - 1];
    } else if (trace[n][m] == 2) {
        trackback(x, y, n, m - 1);
    } else if (trace[n][m] == 3) {
        trackback(x, y, n - 1, m);
    }
}

int main() {
    string x, y;
    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;

    int n = x.size();
    int m = y.size();


    cout << "Length of LCS: " << lcs(x, y, n, m) << endl;
    cout << "LCS: ";
    trackback(x, y, n, m);
    cout << endl;

    return 0;
}
