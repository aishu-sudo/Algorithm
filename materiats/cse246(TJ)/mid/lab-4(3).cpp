#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    bool static cmp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<vector<int>>v;
    	for(int i=0;i<n;i++)
    	{
    	    v.push_back({arr[i],dep[i]});
    	}
    	sort(v.begin(),v.end(),cmp);
       priority_queue<int,vector<int>,greater<int>>pq;
       pq.push(v[0][1]);
       int platforms=1;
       for(int i=1;i<n;i++)
       {
           if(v[i][0]>=pq.top())
           {
               pq.pop();
               pq.push(v[i][1]);
           }
           else
           {
               platforms=platforms+1;
               pq.push(v[i][1]);
           }
       }
       return platforms;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    }
   return 0;
}
