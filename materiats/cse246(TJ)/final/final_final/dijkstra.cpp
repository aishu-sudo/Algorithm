#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector<pair<int,int>>adj[6000];
int dist[6000];
map<int,int>par;
void print(int i){
if(par[i]==0)return;
print(par[par[i]]);
cout<<par[i]<<" >> ";
}
void djk(int src){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 for(int i=0;i<node;i++)dist[i]=2e9;
    dist[src]=0;
pq.push({0,0});
  while(!pq.empty()){
        auto p=pq.top();
        int u=p.second;
        pq.pop();
        for(auto x:adj[u]){
            int w=x.second;
            int v=x.first;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
                par[v]=u;
            }
        }
    }
for(int i=1;i<node;i++){
   cout<<"Path 0 to "<<i<<": ";
    print(i);
    cout<<i<<' ';
    cout<<"Cost" <<dist[i]<<"\n";
}
}
int main(){
    cout<<"Enter the number of nodes: ";
    cin>>node;
    cout<<"Enter the number of edges: ";
    cin>>edge;
    cout<<"Enter the edges and their weight: ";
    for(int i=0;i<node;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
    }
    cout<<"Enter the source: ";
    int src;
    cin>>src;
    djk(src);
    return 0;
}
