#include <bits/stdc++.h>
using namespace std;
vector<vector<double>>dp ;
double max(vector<pair<double,double>>& items,double a, double b)
{
    if(a>b){
      return a;
    }
    return b;

}
double knapseek(vector<pair<double, double>>& items, int capacity,int n) {


    double weight = items[n-1].first;
    double value = items[n-1].second;

    if(n==0 || capacity==0)
    {
        return 0;
    }
    if(dp[n][capacity]!=-1)
    {
        return dp[n][capacity];
    }
    if(weight<=capacity)
    {
        return dp[n][capacity]=max(value+knapseek(items,capacity-weight,n-1),knapseek(items,capacity,n-1));
    }
    else if(weight>capacity){
        return dp[n][capacity]=knapseek(items,capacity,n-1);
    }


}
int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    int capacity;
    cin >> capacity;

    vector<pair<double, double>> items;


    for (int i = 0; i < n; i++) {
        double weight, value;
        cin >> weight >> value;
        items.push_back({weight, value});
    }

     vector<vector<double>> dp(n + 1, vector<double>(capacity + 1, -1));

    double profit=knapseek(items,capacity,n);
    cout<<"maximum value:"<<profit<<endl ;

}
