#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX=1e5+1;
vector<pair<int,int> >graph[MAX];
int main(){
int n,m,a,b,w;
cin>>n>>m;
while(m--){
     cin>>a>>b>>w;
graph[a].push_back({b,w});
graph[b].push_back({a,w});
}
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >pq;
vector<int>dist(n+1,INT_MAX);

pq.push({0,1});
dist[1]=0;
while(!pq.empty()){
 int curr=pq.top().second;
 int curr_d=pq.top().first;
 pq.pop();
 for(pair<int,int>edge: graph[curr]){
   if(curr_d+edge.second<dist[edge.first]){
    dist[edge.first]=curr_d+edge.second;
    pq.push({dist[edge.first],edge.first});
   }
 }

}
for(int i=1;i<=n;i++){
  cout<<dist[i]<<" ";
}

}
