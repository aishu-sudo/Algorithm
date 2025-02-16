#include <bits/stdc++.h>
using namespace std;

using Point = vector<pair<int, int>>;

bool cmp(const <point>&a,const <point>&b)
{
    return a.second < b.second;
}
double distance(const point&a,const point&b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
void stripdistance(const<point>&strip,double d)
{
    sort(strip.begin(),strip.end(),cmp);
    double mindist=d;
    int n=strip.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n&&(strip[j].second-strip[i].second)<mindist;j++)
        {
            mindist=min(mindist,distance(strip[i],strip[j]));
        }
    }
}

void closetpairrecursive(const<point>&points,int left,int right)
{

    int n=left-right;
    if(n<=3)
    {
        double mindist=DBL_MAX;
        for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n&&(points[j].second-points[i].second)<mindist;j++)
        {
            mindist=min(mindist,distance(points[i],points[j]));
        }
    }
    return mindist;
    }

    int mid=left+(left-right)/2;
    point midpoint=point[mid];

    double d1 = closestPairRecursive(points, left, mid);
    double d2 = closestPairRecursive(points, mid, right);
    double d = min(d1, d2);

     vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].first - midPoint.first) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, closestStrip(strip, d));


}


