#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define forn(i,n)    for (int i = 0; i < n; i++)
typedef struct {
   ll value;
    ll weight;
    double fraction;
}knapsack;
bool compare(knapsack a,knapsack b){
return (a.fraction > b.fraction);
}
int main(){
ll w,n;
cin>>n;
cin>>w;
knapsack arr[n];
forn(i,n){
cin>>arr[i].weight;
}
forn(i,n){
cin>>arr[i].value;
}
double total=0,currweight=0;
forn(i,n){
arr[i].fraction=(double)arr[i].value/(double)arr[i].weight;
}
sort(arr, arr+n,compare);
  forn(i,n){
    if(currweight + arr[i].weight<= w){
      total += arr[i].value ;
      currweight += arr[i].weight;
    } else {
      double wt = w-currweight;
      total += (wt * (double)arr[i].fraction);
      currweight += wt;
      break;
    }
}
cout<<total<<endl;
}
