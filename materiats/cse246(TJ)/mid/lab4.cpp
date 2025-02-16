#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    return (double)a.first/(double)a.second>(double)b.first/(double)b.second;
}

int main(){
    vector<pair<int,int>>v;
    cout<<"Enter the number of items and capacity of knapsack: ";
    int n,capacity;
    cin>>n>>capacity;
    for(int i=0;i<n;i++){
        double p,w;
        cin>>p>>w;
        v.emplace_back(p,w);
    }
    sort(v.begin(),v.end(),cmp);
    int c=0;
    for(int i=0;i<n;i++){
        if(v[i].second<=capacity){
            c+=v[i].first;
            capacity-=v[i].second;
        }
        else{
            c+=(double)(capacity)*((double)v[i].first/(double)v[i].second);
            capacity=0;
        }
    }
    cout<<c<<'\n';
    return 0;
}




