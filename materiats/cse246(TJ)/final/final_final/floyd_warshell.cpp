#include<bits/stdc++.h>
using namespace std;
void floydwarshell(vector<vector<int>>&G,int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(G[i][j]==-1)
            {
                G[i][j]=1e9;
            }
            if(i==j)
                G[i][j]=0;

        }
    }
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(G[i][j]==1e9)
            {
                G[i][j]=-1;
            }
        }
    }
}
int main()
{
    int V=4;
    vector<vector<int>>G= {{0,5,-1,10},
        {-1,0,3,-1},
        {-1,-1,0,1},
        {-1,-1,-1,0}
    };
    floydwarshell(G,V);
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

}
