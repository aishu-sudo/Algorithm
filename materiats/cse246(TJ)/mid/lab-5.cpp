#include<bits/stdc++.h>
using namespace std;
void find(vector<vector<int>> &p,int i,int j,int wt[])
{
    if(i==0||j==0)
    {
        return;
    }
    if(p[i-1][j]==p[i][j])
    {
        find(p,i-1,j,wt);
    }
    else
    {
        cout<<i<<endl;
        find(p,i-1,j-wt[i-1],wt);

    }

}

int main()
{
    int val[] = {30,60,40,60,70,50,10,10};
    int wt[] = {3, 1, 2, 3, 4, 3, 1, 2};
    int W = 10;
    int n=8;
    vector<vector<int>>p(n+1,vector<int>(W+1,-1));
    for(int i=0; i<=n; i++)
    {
        p[i][0]=0;
    }
    for(int i=0; i<=W; i++)
    {
        p[0][i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(j-wt[i-1]>=0)
            {
                p[i][j]=max(p[i-1][j],p[i-1][j-wt[i-1]]+val[i-1]);
            }
            else
            {
                p[i][j]=p[i-1][j];
            }
        }
    }
    cout<<p[n][W]<<endl;
    find(p,n,W,wt);


}

