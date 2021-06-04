#include<iostream>
#include<iomanip>

using namespace std;

int main() {
   bool validInput = false;
   unsigned int lower, upper; // variable for ascii values

   while (!validInput) { // loops till input is recieved
      cout << "Enter lower and upper values" << endl;
      cin >> lower >> upper;

      if (lower < 32 || lower>126 || upper < 32 || upper>126 || lower > upper) { // catagorizing values
         cout << "Values must be in range 32 to 126 inclusive" << endl;
      }
      else {
         validInput = true;
      }
   }

   cout << "Characters for ASCII values between " << lower << " and " << upper << endl; // output results
   cout << "----+----+----+----+" << endl;

   int counter = 0;

    for (unsigned char c = lower;c <= upper;c++) { // loop to go through c
     cout << c;
     counter++;
      if (counter % 20 == 0 || c == upper) { // limiting counter and c
         cout << endl;
      }
   }

   cout << "----+----+----+----+" << endl;

   return 0; // end int main function
}