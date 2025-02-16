#include <iostream>
#include <algorithm>
using namespace std;

struct Task {
    int start, end;
};

bool cmp(const Task& a, const Task& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    Task tasks[n];
    for (int i = 0; i < n; i = i+1) {
        cin >> tasks[i].start >> tasks[i].end;
    }
    sort(tasks, tasks + n, cmp);
    int ans = 1, last_end = tasks[0].end;
    for (int i = 1; i < n; i = i+1) {
        if (tasks[i].start >= last_end) {
            ans = ans+1;
            last_end = tasks[i].end;
        }
    }
    cout << ans << endl;
    return 0;
}
