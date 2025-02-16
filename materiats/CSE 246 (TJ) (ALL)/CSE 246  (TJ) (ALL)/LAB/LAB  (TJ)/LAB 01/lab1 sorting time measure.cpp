#include<bits/stdc++.h>
#include<limits.h>
#include<time.h>
#define SIZE 50000
using namespace std;

int arr[SIZE];
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}

int bubblesort()
{

    for (int i = 0; i < SIZE-1; i++)
    for (int j = 0; j < SIZE-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
int  selectionsort()
{
    int m=INT_MAX;
    for (int i = 0; i < SIZE-1; i++)
    {
        m = i;
        for (int j = i+1; j < SIZE; j++)
        if (arr[j] < arr[m])
            m = j;
        swap(&arr[m], &arr[i]);
    }
}
int insertionsort()
{

int key;
   for (int i = 1; i < SIZE; i++)
    {
        int value = arr[i];
       int  j = i - 1;
        while ( j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", arr[i]);
    }
}
void menu()
{
 cout << "------------------" << endl;
    cout << " (1) sort from random integer... " << endl;
    cout << " (2) sort from previous sorted number.... "<< endl;
    cout << " (3) Display ..... "<< endl;
    cout << "------------------" << endl;
}
int main(){
    int choice;
    int index;
    int n;
    int r;
    clock_t start, end;
    int i, ans;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    while(true)
    {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        int c;
        while(true)
        {

        if(choice==1){
    double time_taken;
      start = clock();
     ans = bubblesort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"Bubblesort time taken:"<<time_taken<<endl;
       start = clock();
     ans = selectionsort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"selectionsort time taken:"<<time_taken<<endl;
       start = clock();
     ans = insertionsort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"insertionsort time taken:"<<time_taken<<endl;

      break;
        }
        else if(choice==2){
       selectionsort();
         double time_taken;
      start = clock();
     ans = bubblesort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"Bubblesort time taken:"<<time_taken<<endl;
       start = clock();
     ans = selectionsort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"selectionsort time taken:"<<time_taken<<endl;
       start = clock();
     ans = insertionsort();
     end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
       cout<<"insertionsort time taken:"<<time_taken<<endl;

      break;
        }
          else if(choice==3){
             insertionsort();
            WriteToConsole();
        }


    }
    return 0;

}
}


