#include<bits/stdc++.h>
using namespace std;
int maxim(vector<vector<char>>&matrix)
{
    if(matrix.empty()) return 0;
    int m=matrix.size();
    int n=matrix[0].size();
    int  pre,sz;
    vector<int> cur(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = cur[j];
            if (!i || !j || matrix[i][j] == '0')
            {
                cur[j] = matrix[i][j] - '0';
            }
            else
            {
                cur[j] = min(pre, min(cur[j], cur[j - 1])) + 1;
            }
            sz = max(cur[j], sz);
            pre = temp;
        }
    }
    return sz * sz;
}

int main()
{

    vector<vector<char>> matrix =
    {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };


    int maxSize = maxim(matrix);


    cout << "Size of the largest square of 1s: " << maxSize << endl;

    return 0;
}
