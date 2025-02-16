#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    double b;
    int w;
};

bool cmp(Item a, Item b) {
    return a.b > b.b;
}

int main() {
    int n, W;
    cin >> n >> W;

    Item items[n];
    for (int i = 0; i < n; i++) {
        cin >> items[i].b;
    }
    for (int i = 0; i < n; i++) {
        cin >> items[i].w;
    }

    sort(items, items + n, cmp);
    int    totalBenefit = 0;
    int remainingWeight = W;

    for (int i = 0; i < n && remainingWeight > 0; i++) {
        int take = min(remainingWeight, items[i].w);
        totalBenefit += take * items[i].b;
        remainingWeight -= take;
    }

    cout.precision(2);
    cout << fixed << totalBenefit << endl;

    return 0;
}
