#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &g,int start,bool vis[],int V,int end,int parent[])
{
    if(start==end)
    {
        return true;
    }
    vis[start]=true;

    for(int i=0;i<V;i++)
    {
        if(vis[i]==false &&g[start][i]>0)
        {
           parent[i]=start;
           bool b=dfs(g,i,vis,V,end,parent);
           if(b==true)
           {
               return true;
           }
        }

    }

    return false;
}
int fordfulkerson(vector<vector<int>> &g,int V,int start,int end)
{
    bool vis[V]={false};
    int parent[V]={0};
    parent[start]=-1;
    int ans=0;
    int minpath=INT_MAX;
    while(dfs(g,start,vis,V,end,parent))
    {
        int v=end;
        while(v!=start)
        {
            int u=parent[v];
            minpath=min(minpath,g[u][v]);
            v=u;
        }
        v=end;
        while(v!=start)
        {
           int u=parent[v];
           g[u][v]=g[u][v]-minpath;
           g[v][u]=g[v][u]+minpath;
           v=u;
        }
        ans=ans+minpath;
        fill(vis, vis + V, false);
        fill(parent, parent + V, -1);
    }
    return ans;
}
int main()
{
    int V=6;
     vector<vector<int>>graph=
         { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
     int l=fordfulkerson(graph,V,0,5);
     cout<<l<<endl;
}
