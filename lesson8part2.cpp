#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function declarations
double readFutureValue();
double readInterestRate();
double readNoOfYears();
double presentValue(double futureValue, double interestRate, double noOfyears);

// main function
int main()
{

   // Declaring variables
   double pValue, futureValue, interestRate;
   double noOfyears;

   // calling the functions
   futureValue = readFutureValue();
   interestRate = readInterestRate();
   noOfyears = readNoOfYears();


   // calling the function by passing the result values of each function
   double rate = (interestRate / 100);
   pValue = presentValue(futureValue, rate, noOfyears);

   // Displaying the output
   cout << "Present value: $" << std::setprecision(2) << std::fixed << pValue << endl;
   cout << "Future value: $" << std::setprecision(2) << std::fixed << futureValue << endl;
   cout << "Annual interest rate: " << std::setprecision(3) << std::fixed << interestRate << "%"  << endl;
   cout << "Years: " << std::setprecision(0) << std::fixed << noOfyears << endl;

   return 0;
}

// This function will read the valid future value
double readFutureValue()
{
   double futureVal;
   while (true)
   {
      cout << "Enter future value" << endl;
      cin >> futureVal;
      if (futureVal <= 0)
      {
         cout << "The future value must be greater than zero" << endl;
         continue;
      }
      else
      {
         break;
      }
   }

   return futureVal;
}

// This function will read the valid annual interest rate
double readInterestRate()
{
   double interestRate;
   while (true)
   {
      cout << "Enter annual interest rate" << endl;
      cin >> interestRate;
      if (interestRate <= 0)
      {
         cout << "The annual interest rate must be greater than zero" << endl;
         continue;
      }
      else
      {
         break;
      }
   }
   if (interestRate < 1) // Convert interest rate
   {
	   interestRate = interestRate * 100;
   }

   return interestRate;

   // This function will read the valid no of years
}
double readNoOfYears()
{
   int years;
   while (true)
   {
      cout << "Enter number of years" << endl;
      cin >> years;
      if (years <= 0)
      {
         cout << "The number of years must be greater than zero" << endl;
         continue;
      }
      else
      {
         break;
      }
   }

   return years;
}

// This function will calculate the present value
double presentValue(double futureValue, double interestRate, double noOfyears)
{
   double r = pow((1 + interestRate), noOfyears);
   double preValue = futureValue / r;
   return preValue;
}