#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int trace[100][100];

int lcs(char* X, char* Y, int m, int n)
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]= -1;
        }
    }

	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	return dp[m][n] = max(lcs(X, Y, m, n - 1),
						lcs(X, Y, m - 1, n));
}

void traceback(char* X, char* Y, int m, int n) {
    if (m == 0 || n == 0)
        return;

    if (X[m - 1] == Y[n - 1]) {
        traceback(X, Y, m - 1, n - 1);
        cout << X[m - 1];
    } else if (dp[m - 1][n] > dp[m][n - 1]) {
        traceback(X, Y, m - 1, n);
    } else {
        traceback(X, Y, m, n - 1);
    }

}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	cout << "Length of LCS is " << lcs(X, Y, m, n)<<endl;
	cout<< "LCS is :"<<endl;
	traceback(X,Y,m,n);

	return 0;
}
