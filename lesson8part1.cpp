#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototypes
double readSeconds();
double calculateEarthDistance(double);
double calculateMoonDistance(double);
void displayResults(double, double, double);

// Main function which includes function calls
int main()
{
   bool loopUntilZero = true;
   do
   {
      double secondsReceived;
      secondsReceived = readSeconds();

      // Used to terminate the program
      if (secondsReceived == 0)
      {
         return 0;
      }

      if (secondsReceived > 0)
      {
         double earthDistanceCalculation;
         earthDistanceCalculation = calculateEarthDistance(secondsReceived);

         double moonDistanceCalculation;
         moonDistanceCalculation = calculateMoonDistance(secondsReceived);

         displayResults(secondsReceived, earthDistanceCalculation, moonDistanceCalculation);
      }

      else
      {
         secondsReceived = readSeconds();
      }
   } while (loopUntilZero == true);
}

// Function used for reading in the seconds input
double readSeconds()
{
   double secondsInput;

   cout << "Enter the time (in seconds)" << endl;
   cin >> secondsInput;

   // Input validation
   while (secondsInput < 0)
   {
      cout << "The time must be zero or more" << endl;
      cout << "Enter the time (in seconds)" << endl;
      cin >> secondsInput;
   }

   return secondsInput;
}

// Function used for taking in seconds to calculate the distance an object fell on Earth
double calculateEarthDistance(double seconds)
{
   double earthDistance = 0,
      earthAcceleration = 9.8; // 9.8 for acceleration due to Earth's gravity

   earthDistance = 0.5 * earthAcceleration * pow(seconds, 2);

   return earthDistance;
}

// Function used for taking in seconds to calculate the distance an object fell on the Moon
double calculateMoonDistance(double seconds)
{
   double moonDistance = 0,
      moonAcceleration = 1.6; // 1.6 for acceleration due to Earth's gravity

   moonDistance = 0.5 * moonAcceleration * pow(seconds, 2);

   return moonDistance;
}

// Function used for displaying the calculations done over multiple functions
void displayResults(double seconds, double earthDistance, double moonDistance)
{
   cout << "The object traveled " << setprecision(4) << fixed << earthDistance << " meters in " << setprecision(2) << fixed << seconds << " seconds on Earth" << endl;

   cout << "The object traveled " << setprecision(4) << fixed << moonDistance << " meters in " << setprecision(2) << fixed << seconds << " seconds on the Moon" << endl;
}