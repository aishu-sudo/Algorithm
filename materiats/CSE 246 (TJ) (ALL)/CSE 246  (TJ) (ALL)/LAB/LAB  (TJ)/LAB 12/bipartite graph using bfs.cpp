#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX=1e5+1;
vector<int>graph[MAX];
vector<bool>visited(MAX);
vector<int>color(MAX);
bool bfs(ll node){
queue<ll>q;
q.push(node);
visited[node]=true;
color[node]=1;
while(!q.empty()){
    ll curr=q.front();
    q.pop();

    for(ll child:graph[curr]){
        if(!visited[child]){
          color[child]=color[curr]*(-1);
           q.push(child);
           visited[child]=true;
        }
        else if(color[child]==color[curr]){
            return false;
        }
    }
}
return true;
}

int main(){
ll n,m;
cin>>n>>m;
int a,b;
visited.assign(MAX,false);
for(int i=0;i<m;i++){
  cin>>a>>b;
  graph[a].push_back(b);
  graph[b].push_back(a);
}
bfs(1)?cout<<"Bipartite"<<endl:cout<<"Not Bipartite"<<endl;
}
