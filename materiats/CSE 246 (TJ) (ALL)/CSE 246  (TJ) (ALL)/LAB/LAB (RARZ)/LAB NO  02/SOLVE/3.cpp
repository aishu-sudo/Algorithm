
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    int a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a, a + m);

    int maxCount = 1, currCount = 1;
    int maxElement = a[0], currElement = a[0];

    for (int i = 1; i < m; i++) {
        if (a[i] == currElement) {
            currCount++;
        } else {
            if (currCount > maxCount || (currCount == maxCount && currElement > maxElement)) {
                maxCount = currCount;
                maxElement = currElement;
            }
            currElement = a[i];
            currCount = 1;
        }
    }

    if (currCount > maxCount || (currCount == maxCount && currElement > maxElement)) {
        maxCount = currCount;
        maxElement = currElement;
    }

    cout << maxElement << endl;

    return 0;
}































