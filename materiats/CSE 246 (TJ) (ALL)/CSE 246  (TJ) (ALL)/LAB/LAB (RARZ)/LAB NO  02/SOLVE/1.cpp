#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, p;
    cin >> m;
    vector < pair< double, int >> students(m);
    for (int j = 0; j < m; j = j+1) {
        cin >> students[j].first;
        students[j].second = j+1;
    }
    cin >> p;

    sort(students.begin(), students.end());

    cout << students[p-1].second << endl;

    return 0;
}
