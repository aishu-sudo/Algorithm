#include <bits/stdc++.h>
using namespace std;


bool sortdesc(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) > get<2>(b);
}

int main() {
    int n = 50;
    vector<tuple<int, int, int>> v;


    v.push_back(make_tuple(1, 2, 50));
    v.push_back(make_tuple(2, 1, 15));
    v.push_back(make_tuple(3, 2, 10));
    v.push_back(make_tuple(4, 1, 25));

    sort(v.begin(), v.end(), sortdesc);


    vector<int> jobseq(n, -1);
    vector<bool> s(n, false);

    int totalProfit = 0;
    vector<int> scheduledJobs;


    for (int i = 0; i < v.size(); i++) {
        int id = get<0>(v[i]);
        int deadline = get<1>(v[i]);
        int profit = get<2>(v[i]);


        for (int j = deadline - 1; j >= 0; j--) {
            if (!s[j]) {
                s[j] = true;
                jobseq[j] = id;
                totalProfit += profit;
                scheduledJobs.push_back(id);
                break;
            }
        }
    }


    cout << "Scheduled Jobs (ID): ";
    for (int i = 0; i < scheduledJobs.size(); i++) {
        cout << scheduledJobs[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
