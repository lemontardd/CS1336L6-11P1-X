#include <fstream>
#include <iostream>
#include <iomanip>
int tt;
using namespace std;
void calc(int a, int& b)
{
   static int c;
   c = a + 2;
   a = a * 3;
   b = c + a;
   return;
}

const int SIZE = 5;
int main()
{

   string str1 = "Mary";
      string str2 = "Matthew";
      string str3 = "Matthew Smith";
      string str4 = "MaryAnne";
      string str5 = "MarYAnne";



      if(str1 >= str2 ) cout << "true1";
      if(str1 <= str2 ) cout << "true2";
      if(str2 >= str3 ) cout << "true3";
      if(str2 < str3 ) cout << "true4";
      if(str2 <= str4 ) cout << "true5";
      if(str2 > str4 ) cout << "true6";
      if (str5 <= str1) cout << "true7";
   int numbers[4] = { 99, 87 };
   cout << numbers[3] << endl;

   int xxx[] = { 2,3,4 };

   int x = 1;
   int k = 2;

   int gg = 0;
   gg = ++x;
   double ddd = 1;
   
   for (int c=0,x=2;;)
   {
   }
   int y = sizeof(x);
   int z = sizeof(ddd);
   calc(x, y);
   cout << x << " " << y << " " << z << endl;
}