#include<bits/stdc++.h>
using namespace std;
vector<pair<double,double>>p;
bool cmp(pair<double,double>a,pair<double,double>b)
{
    return b.second>a.second;
}
double cal(pair<double,double>a,pair<double,double>b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double dist(int l,int r)
{
    double mnss=2e9;
    for(int i=l; i<=r-1; i++)
    {
        for(int j=i+1; j<=r; j++)
        {
            mnss=min(cal(p[i],p[j]),mnss);
        }
    }
    return mnss;
}

vector<pair<double,double>> copyFromP(int l,int r,int d,pair<double,double> midp)
{
    vector<pair<double,double>>nwp;
    for(int i=l; i<=r; i++)
    {
        if(abs(p[i].first-midp.first)<d)
        {
            nwp.push_back(p[i]);
        }
    }
    return nwp;
}

double minDiss(vector<pair<double,double>>nwp)
{
    sort(nwp.begin(),nwp.end(),cmp);
    double mnss=2e9;
    for(int i=0; i<nwp.size()-1; i++)
    {
        for(int j=i+1; j<nwp.size()&&(nwp[j].second-nwp[i].second)<mnss; j++)
        {
            mnss=min(cal(nwp[i],nwp[j]),mnss);
        }
    }
    return mnss;
}

double closestPair(int l,int r)
{
    double ans=2e9,d=2e9,ds=2e9;
    if(r-l<=2)
    {
        return dist(l,r);
    }
    else
    {
        int mid=(r+l)/2;
        pair<double,double> midp=p[mid];
        double d1=closestPair(l,mid);
        double d2=closestPair(mid+1,r);
        d=min(d1,d2);
        vector<pair<double,double>>nwp=copyFromP(l,r,d,midp);
        ds=minDiss(nwp);
        return min(d,ds);
    }
}

int main()
{
    cout<<"Enter the number of points: ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        double x,y;
        cin>>x>>y;
        p.emplace_back(x,y);
    }
    sort(p.begin(),p.end());
    cout<<closestPair(0,n-1)<<'\n';
    return 0;
}
