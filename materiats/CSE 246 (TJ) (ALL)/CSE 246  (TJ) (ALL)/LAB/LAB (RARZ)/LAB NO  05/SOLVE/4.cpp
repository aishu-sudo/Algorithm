#include<bits/stdc++.h>
using namespace std;

int a1[41], a2[41];
int c[41][41];

class dir {
    public:
    int i, j;
};

dir d[41][41];

int main() {
    string M, N;
    cin >> M >> N;

    // this is tabular method or botton up approach

    for(int i = 0; i < M.size(); i++)
        a1[i+1] = M[i];
    for(int j = 0; j < N.size(); j++)
        a2[j+1] = N[j];

    memset(c, 0, sizeof(c));

    for(int i = 1; i <= M.size(); i++) {
        for(int j = 1; j <= N.size(); j++) {
            if(a1[i] == a2[j]) {
                c[i][j] = 1+ c[i-1][j-1];
                d[i][j].i = i-1;
                d[i][j].j = j-1;
            }
            else {
                if(c[i][j-1] >= c[i-1][j]) {
                    c[i][j] = c[i][j-1];
                    d[i][j].i = i;
                    d[i][j].j = j-1;
                } else {
                    c[i][j] = c[i-1][j];
                    d[i][j].i = i-1;
                    d[i][j].j = j;
                }
            }
        }
    }
    cout << c[M.size()][N.size()] << endl;

    // path print
    stack<char> st;
    int m = M.size(), n = N.size();
    while(true) {
        if(m == 0 || n == 0) {
            break;
        }
        if(d[m][n].i == m-1 && d[m][n].j == n-1) {
            st.push((int)a1[m]);
            m = m-1;
            n = n-1;
        }
        else if(d[m][n].i == m && d[m][n].j == n-1) {
            n = n-1;
        }
        else if(d[m][n].i == m-1 && d[m][n].j == n) {
            m = m-1;
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}
