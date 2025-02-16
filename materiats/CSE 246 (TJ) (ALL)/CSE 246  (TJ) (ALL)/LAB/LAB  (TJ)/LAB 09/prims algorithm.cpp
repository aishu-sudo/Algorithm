#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
int graph[100][100];
int selectminvertex(vector<int>&dist,vector<int>&flag,int n){
int m=INT_MAX;
int vertex;
for(int i=0;i<n;i++){
    if(flag[i]==false && dist[i]<m){
        vertex=i;
        m=dist[i];
    }
}
return vertex;
}
int main(){
int n,m,a,b,w;
cin>>n>>m;
while(m--){
     cin>>a>>b>>w;
graph[a][b]=w;
graph[b][a]=w;
}
int parent[n];
vector<int>dist(n,INT_MAX);
vector<int>flag(n,false);
parent[0]=-1;
dist[0]=0;
for(int i=0;i<n-1;i++){
  int v=selectminvertex(dist,flag,n);
  flag[v]=true;
   for(int j=0;j<n;j++){

    if(graph[v][j]!=0 && flag[j]==false && graph[v][j]<dist[j]){
        dist[j]=graph[v][j];
        parent[j]=v;
    }
   }
}
for(int i=1;i<n;++i)
cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}
