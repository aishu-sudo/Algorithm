#include <iostream>
using namespace std;

int main() {
    int p, m;
    cin >> p >> m;

    int coins[p];
    for (int i = 0; i < p; i= i+1)
        cin >> coins[i];

    int minCoins[m+1];
    for (int i = 0; i <= m; i = i+1)
        minCoins[i] = m+1;
    minCoins[0] = 0;

    for (int i = 1; i <= m; i= i+1)
        for (int j = 0; j < p; j = j+1)
            if (coins[j] <= i && minCoins[i-coins[j]] + 1 < minCoins[i])
                minCoins[i] = minCoins[i-coins[j]] + 1;

    if (minCoins[m] > m)
        cout << "-1\p";
    else
        cout << minCoins[m] << endl;

    return 0;
}
