#include<iostream>

using namespace std;

struct product
{
    int itemno ;
    double weight ;
    double value ;
    double priceperweight ;
}item[100], temp;
int main()
{
    int n, i, j ;
    double w ;
   cin>> w;
   cin>>n;
    for(i = 0 ; i < n ; i++){
        item[i].itemno = i+1 ;
        cout << " " << item[i].weight, &item[i].value ;
        item[i].priceperweight = item[i].value/item[i].weight ;
    }

    for(i = 0 ; i < n ; i++){
        for(j = i+1 ; j < n ; j++){
            if(item[i].priceperweight < item[j].priceperweight){
                temp = item[i] ;
                item[i] = item[j] ;
                item[j] = temp ;
            }
        }
    }

    double currentweight = 0.0 ;
    double totalProfit = 0.0 ;

    for(i = 0 ; i < n ; i++){
        if(currentweight + item[i].weight <= w){
            currentweight += item[i].weight ;
            totalProfit += item[i].value ;
            cout<< " " <<item[i].itemno, item[i].weight, item[i].value ;
        }

        else
        {
            double remain = w - currentweight ;
            totalProfit += item[i].priceperweight*remain ;
           cout<<item[i].itemno, remain, item[i].priceperweight*remain ;
            break ;
        }
    }
    cout<<" total profit:" << totalProfit ;

}
