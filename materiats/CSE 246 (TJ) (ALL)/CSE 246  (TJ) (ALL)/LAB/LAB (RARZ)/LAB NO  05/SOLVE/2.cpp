#include<bits/stdc++.h>
using namespace std;

int main() {
    // this is the tabular method or bottom up approach
    int N, K;
    cin >> N >> K;
    int coins[N];
    for(int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins, coins+N);

    int a[N][K+1];

    int i = 0;
    int j = 0;
    a[i][j] = 0;
    for(j = 1; j < K+1; j++) {
        if(coins[i] > j)
            a[i][j] = 0;
        else if(j%coins[i] == 0)
            a[i][j] = j/coins[i];
        else
            a[i][j] = 0;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < K+1; j++) {
            if(coins[i] > j) {
                a[i][j] = a[i-1][j];
            }
            else if(a[i-1][j] == 0) {
                a[i][j] = 1+ a[i][j-coins[i]];
            }
            else {
                int t = j-coins[i];
                if(t != 0 && a[i][t] == 0)
                    a[i][j] = a[i-1][j];
                else
                    a[i][j] = min(a[i-1][j], 1+a[i][t]);
            }
        }
    }

    // find the coins
    map<int, int> m;
    i = N-1;
    j = K;
    while(true) {
        if(j == 0) {
            break;
        }
        if(a[i][j] != a[i-1][j]) {
            m[coins[i]]++;
            j = j-coins[i];
        } else {
            i--;
        }
    }

    for(auto data: m) {
        cout << data.first << " " << data.second << endl;
    }

    return 0;
}
