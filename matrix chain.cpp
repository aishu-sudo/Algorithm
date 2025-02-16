#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(101, vector<int>(101, 0));

1

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the dimensions array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m = matrix_multiplication(n, arr);

    cout << "Minimum number of multiplications: "
         << m << endl;

    return 0;
}
