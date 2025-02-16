#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int traceArr[1000][1000];

struct dimension{
    int a;
    int b;
};

char x = 'A';
void trace(int i, int j){
    if(i == j){
        cout<<x;
        x = (int)x + 1;
        return;
    }
    else{
        cout<<"(";
        trace(i, traceArr[i][j]);
        trace(traceArr[i][j]+1, j);
        cout<<")";
    }
}

void multiplication(int n, int arr[]){
    int j, min, q;
    for(int d = 1 ; d < n-1 ; d++){
        for(int i = 1 ; i < n-d ; i++){
            j = i+d;
            min = INT_MAX;
            for(int k=i ; k <= j-1 ; k++){
                q = dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
                if(q < min){
                    min = q;
                    traceArr[i][j] = k;
                }
            }
            dp[i][j] = min;
        }
    }
    cout<<dp[1][n-1];
}

int main(int argc, char const *argv[]){
    cout<<"enter the number of matrices: ";
    int n;
    cin>>n;

    cout<<"enter the dimensions of "<<n<<" matrices: "<<endl;
    struct dimension array[n];
    int arr[n+1];
    for(int i=0 ; i<n ; i++){
        cin>>array[i].a;
        arr[i] = array[i].a;
        cin>>array[i].b;
    }
    arr[n] = array[n-1].b;

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++){
            dp[i][j] = 0;
            traceArr[i][j] = 0;
        }
    }

    cout<<endl<<endl<<"------------------- OUTPUT -------------------";
    cout<<endl<<"Minimum number of operations to complete the multiplication: ";

    multiplication(n+1, arr);
    cout<<endl;
    cout<<"Sequence of Matrix for minimum number of operations: ";
    trace(1, n);

    return 0;
}
