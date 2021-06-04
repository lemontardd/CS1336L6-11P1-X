#include<iostream> 
#include <iomanip>
using namespace std;
int main()
{
   double start, end, celsius, increment, cnt, kelvin; // variables

   cin >> start >> end >> increment; // input from user

   while (start > end || increment <= 0) // conditional loop
   {
      cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
      cin >> start >> end >> increment;
   }

   cout << setw(18) << "Fahrenheit" << std::setw(18) << "Celsius" << std::setw(18) << "Kelvin" << endl; // output to display results

   for (cnt = start;cnt <= end;cnt = cnt + increment) // loop calculates input to output
   {
      celsius = (cnt - 32) / 1.8;
      kelvin = celsius + 273.15;
      cout << showpoint;
      cout.setf(ios::fixed, ios::floatfield);
      cout << setw(18) << setprecision(4) << cnt << setw(18) << setprecision(4) << celsius << setw(18) << setprecision(4) << kelvin << endl;
   }

   return 0; // end int main function
}