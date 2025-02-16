#include <bits/stdc++.h>
using namespace std;

struct item {
    double weight;
    double value;
};


bool cmp(const pair<double, double>& a, const pair<double, double>& b) {
    return (a.second / a.first) > (b.second / b.first); // Descending order
}

double knapseek(vector<pair<double, double>>& items, double capacity) {

    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        double weight = items[i].first;
        double value = items[i].second;

        if (capacity > 0 && weight <= capacity) {

            capacity -= weight;
            totalValue += value;

        } else if (capacity > 0 && weight > capacity) {
            totalValue += (capacity / weight) * value;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<pair<double, double>> items;

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    double capacity;
    cin >> capacity;


    for (int i = 0; i < n; i++) {
        double weight, value;
        cin >> weight >> value;
        items.push_back({weight, value});
    }

    double maxValue = knapseek(items, capacity);

    for (int i = 0; i < n; i++) {
        cout << "weight: " << items[i].first << ", value: " << items[i].second << endl; //a pair does not have member variables named weight or value
    }

    cout << "\nMaximum value in Knapsack: " << maxValue << endl;

    return 0;
}

