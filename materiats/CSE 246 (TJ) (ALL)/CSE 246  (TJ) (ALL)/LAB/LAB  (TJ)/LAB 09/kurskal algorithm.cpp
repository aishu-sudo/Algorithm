#include<bits/stdc++.h>
using namespace std;
struct edge{
int a,b,w;
};
edge arr[100000];
int par[10001];
bool comp(edge a,edge b){
if(a.w<b.w)return true;
return false;
}
int find(int vertex){
if(par[vertex]==-1){
 return vertex;
}
return par[vertex]=find(par[vertex]);
}
void union_t(int a,int b){
par[a]=b;
}
int main(){
int n,m,a,b,w;
cin>>n>>m;
for(int i=1;i<=n;i++)par[i]=-1;
for(int i=0;i<m;i++){
  cin>>arr[i].a>>arr[i].b>>arr[i].w;
}
int sum=0;
sort(arr,arr+m,comp);
for(int i=0;i<m;i++){
 int a=find(arr[i].a);
 int b=find(arr[i].b);
 if(a!=b){
    sum+=arr[i].w;
    union_t(a,b);
 }
}
cout<<sum<<endl;
}
