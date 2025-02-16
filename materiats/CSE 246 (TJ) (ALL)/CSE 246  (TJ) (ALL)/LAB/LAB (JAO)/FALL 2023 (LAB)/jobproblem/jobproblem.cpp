#include<iostream>

using namespace std;

struct job{
    int id;
    int deadline, profit;
    };

struct job joblist[100] ;

int main(){
    struct job temp;
    int I;
    int n,d,p;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> I;
        cin >> d;
        cin >> p;

        temp.id = I;
        temp.deadline = d;
        temp.profit = p;
        joblist[i] = temp;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(joblist[j].profit > joblist[i].profit){
                temp = joblist[i];
                joblist[i] = joblist[j];
                joblist[j] = temp;
            }
        }
    }
    cout << "After" << endl ;
    for (int i = 0 ; i < n ; i++){
        cout<<joblist[i].deadline <<" " << joblist[i].profit << endl ;
    }
    int schedule[n];
    int profit = 0;

    for(int i=0; i<n; i++)
        schedule[i] = -1;


        for(int i=0; i<n; i++){
            int d = joblist[i].deadline;
            for(int j=d-1; j>=0; j--){
                if(schedule[j] == -1){
                    schedule[j] = joblist[i].id;
                    profit = profit+joblist[i].profit;
                    break;
                }
          }
    }
    for(int i = 0; i <n; i++){
        if(schedule[i] != -1)
            cout << schedule[i] << " ";
    }

    cout << "Profit: " << profit << endl ;
}



