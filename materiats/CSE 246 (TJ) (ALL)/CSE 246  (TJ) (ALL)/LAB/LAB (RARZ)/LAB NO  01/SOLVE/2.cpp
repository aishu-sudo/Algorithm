
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int num;
   cin >> num;
   float temp, sqrt;

   sqrt = num / 2;
   temp = 0;

   while (temp != sqrt)
   {
      temp = sqrt;
      sqrt = (num / temp + temp) / 2;
   }

   cout << fixed << setprecision(3) << sqrt << endl;
   return 0;
}
