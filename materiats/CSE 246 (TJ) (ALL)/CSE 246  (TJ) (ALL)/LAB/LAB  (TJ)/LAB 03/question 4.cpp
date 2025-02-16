#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define forn(i,n)    for (int i = 0; i < n; i++)
int main(){
   ll n,week;
    cin>>n;

vector<int>arr(n),d(n);

forn(i,n) cin>>d[i];
sort(d.begin(),d.end(),greater<int>());
ll total=0;
ll r=n;
forn(i,n){
    ll j=i+1;
total+=d[i]*(r-j);
}
cout<<total<<endl;



}
