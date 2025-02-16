#include <bits/stdc++.h>
using namespace std;
int LCSubStr(string x,string y)
{
    int m=x.length();
    int n=y.length();
    int result=0;
    int len[2][n];
    int currRow=0;
    for(int i=0;i<=m;i++){
        for(int j=0; j<=n; j++)
        {
            if(i==0||j==0)
            {
                len[currRow][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                len[currRow][j]=len[1-currRow][j-1]+1;
                result=max(result, len[currRow][j]);
            }
            else
                {
                len[currRow][j]=0;
                }
        }
        currRow=1-currRow;
    }
    return result;
}
int main()
{
    string x="ABBNAB";
    string y="GAABBC";
    cout<<LCSubStr(x,y);
    return 0;
}
