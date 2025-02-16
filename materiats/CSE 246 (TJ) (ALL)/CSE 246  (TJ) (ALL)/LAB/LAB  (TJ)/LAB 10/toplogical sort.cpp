#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
vector<int>graph[MAX];
vector<int>indegree;
vector<int>res;
void topsort(int v){
queue<int>q;
for(int i=1;i<=v;i++){//vertics start from node 1 not 0
 if(indegree[i]==0)q.push(i);
}
while(!q.empty()){
  int parent=q.front();
    res.push_back(parent);
    q.pop();
    for(auto child:graph[parent]){
      indegree[child]--;
      if(indegree[child]==0)q.push(child);

    }

}
cout<<"topsort: ";
for(auto node:res){
  cout<<node<<" ";
}
}
int main(){
int v,e;
cin>>v>>e;
indegree.assign(v+1,0);
for(int i=0;i<e;i++){
 int a,b;
 cin>>a>>b;
 graph[a].push_back(b);
 indegree[b]++;

}
topsort(v);

}
