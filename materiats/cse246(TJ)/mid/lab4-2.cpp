#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){
    vector<pair<int,int>>v;
    cout<<"Enter the number of activities: ";
    int n;
    cin>>n;
    int start[n];
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        double f;
        cin>>f;
        v.emplace_back(start[i],f);
    }
    sort(v.begin(),v.end(),cmp);
    int c=1;
    int prev=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>=prev){
            prev=v[i].second;
            c++;
        }
    }
    cout<<c<<'\n';
    return 0;
}
