#include<bits/stdc++.h>
using namespace std;
#define max 100000
int v,e;
vector<pair<int,pair<int,int>>>adj;
int findd(int n,int *parent)
{
    if(n!=parent[n] )
    {
        parent[n]=findd(parent[n],parent);
    }
    return parent[n];

}
int merge(int x,int y, int *par, int *rankk){
x=findd(x,par);
y=findd(y,par);
if(rankk[x]>rankk[y]){
    par[y]=x;
}
else {
    par[x]=y;
}
if(rankk[x]==rankk[y])
    rankk[y]++;

}
int kruskal(){
int weght=0;
sort(adj.begin(),adj.end());
int *par=new int[v];
int *rankk=new int[v];
for(int i=0;i<v;i++){
    par[i]=i;
    rankk[i]=0;
}
for(auto ii=adj.begin();ii!=adj.end();ii++){
    int uu= ii->second.first;
    int vv= ii->second.second;
    int a = findd(uu,par);
    int b = findd(vv,par);
    if(a!=b){
        cout<<uu<<' '<<vv<<'\n';
        weght+=ii->first;
        merge(a,b,par,rankk);
    }
}return weght;

}

int main(){
    cin>>v>>e;
    for(int i=1;i<=e;i++){
        int u,vv,w;
        cin>>u>>vv>>w;
        adj.push_back({w,{u,vv}});
    }
    cout<<kruskal();
    return 0;
}

