#include <bits/stdc++.h>
using namespace std;
int max(int x, int y)
{
    return (x>y)?x:y;
}
 int lps(char*seq, int i, int j)
{
    if(i==j)
        return 1; //if only 1 character match
    if(seq[i]==seq[j] && i+1==j)
        return 2; //if two & both are same
    if(seq[i]==seq[j])
        return lps(seq,i+1,j-1)+2; //if 1st and last character match
    else
        return max(lps(seq,i,j-1), lps(seq,i+1,j));

}

int main(){
    char seq[]= "BANANA";
    int n=strlen(seq);
    cout<<"the length of LPS:"<<lps(seq,0,n-1);
    return 0;
}
