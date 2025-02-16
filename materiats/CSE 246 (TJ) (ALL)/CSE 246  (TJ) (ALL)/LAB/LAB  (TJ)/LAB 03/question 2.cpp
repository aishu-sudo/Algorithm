#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define forn(i,n)    for (int i = 0; i < n; i++)

bool compare(const pair<int,int> &a,const pair<int,int> &b){
return (a.second < b.second);
}
int main(){
ll n;
cin>>n;
vector< pair<int ,int> >p,r;
ll start,finish;
forn(i,n){

cin>>start>>finish;
p.push_back(make_pair(start,finish));
}
sort(p.begin(),p.end(),compare);
 int i = 0;
cout<<"Activities are:";
ll c=1;
	cout<< "(" <<p[i].first<< ", " <<p[i].second << ")\n";
    for (int j = 1; j < n; j++)
    {
    	if (p[j].first>= p[i].second)
      	{
			cout<< "(" <<p[j].first<< ", "<<p[j].second << ") \n";
			i = j;
			c++;
      	}
    }
cout<<"Number of activities can be selected: "<<c<<endl;
}

