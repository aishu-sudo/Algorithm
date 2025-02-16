#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>g;
int dist[10000];
int node,edge;
map<int,int>parent;

void print(int i){
    if(parent[i]==0){
        return;
    }
    print(parent[parent[i]]);
    cout<<parent[i]<<"->";
}

void Belmnfrd(int src){
    for(int i=0;i<node;i++)dist[i]=2e9;
    dist[src]=0;
    for(int i=1;i<node;i++) {
        for(int j=0;j<edge;j++) {
            int uu=g[j].second.first;
            int vv=g[j].second.second;
            int w=g[j].first;
            if (dist[uu]!=2e9 and dist[uu]+w<dist[vv])
                dist[vv]=dist[uu]+w;
                parent[vv]=uu;
        }
    }

    for(int i=0;i<edge;i++) {
        int uu=g[i].second.first;
        int vv=g[i].second.second;
        int w=g[i].first;
        if (dist[uu]!=2e9 and dist[uu]+w<dist[vv]) {
            cout<<"Negative cycle detected";
            return;
        }
    }

    for(int i=1;i<node;i++){
        cout<<"Path 0 to "<<i<<": "<<0<<"->";
        print(i);
        cout<<i<<' ';
        cout<<"Cost: "<<dist[i]<<'\n';
    }
}


int main(){
    cout<<"Enter the number of nodes: ";
    cin>>node;
    cout<<"Enter the number of edges: ";
    cin>>edge;
    cout<<"Enter the edges and their weight: ";
    for(int i=0;i<node;i++){
        int n,v,w;
        cin>>n>>v>>w;
        g.push_back({w,{n,v}});
    }
    cout<<"Enter the source: ";
    int source;
    cin>>source;
    Belmnfrd(source);
    return 0;
}
