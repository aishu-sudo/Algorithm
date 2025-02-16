#include<bits/stdc++.h>
using namespace std;
int INF=1e9;
int floydwarshall(vector<vector<int>>&a,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][k]+a[k][j]<a[i][j])
                {
                    a[i][j]= a[i][k]+a[k][j];
                }
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>d[i][j];
        }
    }

    floydwarshall(d,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(d[i][j]==INF)
           {
               cout<<"INF" ;
           }
           else{
            cout<<d[i][j]<<" ";
           }
        }

    }

}
