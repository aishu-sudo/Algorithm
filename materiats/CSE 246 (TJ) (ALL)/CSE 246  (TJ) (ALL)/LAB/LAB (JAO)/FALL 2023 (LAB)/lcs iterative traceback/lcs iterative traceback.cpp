#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
 int dp[100][100];
int trace[100][100];

void lcs(char* X, char* Y, int m, int n)
{
    int dp[m + 1][n + 1];


    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                 dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    int index = dp[m][n];


    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1];
            i--;
            j--;
            index--;
        }


        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }


    cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
void traceback(char* X,char* Y,int i,int j){

 if(i == 0|| j == 0)return;

 if(X[i-1] == Y[j-1]) {
 traceback(i-1, j-1);
 cout << X[i-1];
 }
 else if(dp[i-1][j] > dp[i][j-1])
 traceback(i-1, j);
 else traceback(i, j-1);
}

int main()
{
    char X[] = "ABBTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    traceback(X,Y,m,n);
    return 0;
}
