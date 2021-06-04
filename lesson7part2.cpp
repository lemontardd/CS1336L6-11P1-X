#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main() {
   ifstream infile; // input file
   ofstream outfile; // output file
   string name;

   double numbers[100]; // numbers array
   double number; // variable for numbers
   int i = 0;
   int valid = 0, invalid = 0, total = 0; // true false
   double sum = 0.0;
   
   cout << "Enter input file name" << endl; // recieve input for file name
   cin >> name;

   infile.open(name); // open file
   if (infile.fail())
   {
      cout << "File \"" << name << "\" could not be opened" << endl; // if file cant open
      return 0;
   }

   cout << "Reading from file \"" << name << "\"" << endl;

   while (infile >> number) { // output file values
      numbers[i] = number;
      i++;
      total++;
   }

   cout << "Total values: " << total << endl; // output total values

   outfile.open("invalid-values.txt"); // open file
   for (int i = 0;i < total;i++)
   {
       if (numbers[i] >= 0 && numbers[i] <= 105) // condition what numbers are valid
      {
         sum = sum + numbers[i];
         valid++;
      }
      else
      {
         outfile << fixed << setprecision(5) << numbers[i] << endl;
         invalid++;
      }
   }
   outfile.close(); // close file

   infile.close(); // clode file

   cout << "Invalid values: " << invalid << endl; // output results
   cout << "Valid values: " << valid << endl;

   if (sum / valid >= 0) { // output avg if possible
      cout << "Average of valid values: " << setprecision(4) << fixed << sum / valid << endl;
   }
   else
   {
      cout << "An average cannot be calculated" << endl;
   }
}