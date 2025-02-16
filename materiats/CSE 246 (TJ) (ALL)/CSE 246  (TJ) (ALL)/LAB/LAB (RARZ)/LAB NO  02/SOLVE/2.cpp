#include<bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;

    double  coords[m];
    for (int j = 0; j < m; j = j+1) {
        cin >> coords[j];
    }

    sort(coords, coords + m);

    int minDist = abs(coords[0] - coords[1]);
    for (int j = 1; j < m - 1; j= j+1) {
        int dist = abs(coords[j] - coords[j + 1]);
        if (dist < minDist) {
            minDist = dist;
        }
    }

    cout << minDist << endl;

    return 0;
}
