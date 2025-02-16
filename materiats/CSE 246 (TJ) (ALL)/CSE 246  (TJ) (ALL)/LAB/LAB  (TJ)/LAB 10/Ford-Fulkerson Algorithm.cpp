#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
int graph[MAX][MAX];
int rgraph[MAX][MAX];
vector<int>par;
vector<bool>visited;
bool bfs(int s,int t,int n){
visited.assign(n+1,false);
queue<int>q;
q.push(s);
visited[s]=true;
par[s]=-1;
while(!q.empty()){
  int node=q.front();
  q.pop();
  for(int i=0;i<n;i++){
  if(!visited[i] && rgraph[node][i]>0){
  if(i==t){
  par[i]=node;
  return true;
  }
  q.push(i);
  par[i]=node;
  visited[i]=true;
  }
  }

}
return false;
}

void fordfulkerson(int s,int t,int n){
int u,v;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
rgraph[i][j]=graph[i][j];
}
}
int maxflow=0;
  while(bfs(s,t,n)){
 int pathflow=INT_MAX;
 for( v=t;v!=s;v=par[v]){
  u=par[v];
  pathflow=min(pathflow,rgraph[u][v]);

 }
 for( v=t;v!=s;v=par[v]){
 u=par[v];
 rgraph[u][v]-=pathflow;
 rgraph[v][u]+=pathflow;

 }
maxflow+=pathflow;
  }
cout<<maxflow<<endl;
}
int main(){
int n,m;
cin>>n>>m;
par.resize(n+1);
for(int i=0;i<m;i++){
  int a,b,w;
  cin>>a>>b>>w;
   graph[a][b]=w;
}
int s,t;
cin>>s>>t;//s indicates source and t indicates sink

fordfulkerson(s,t,n);
}
//input
/*6 10->n,m
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5*->s,t/
