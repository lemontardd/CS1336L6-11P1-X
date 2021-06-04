#include<iostream>
#include <fstream>
using namespace std;

//main function
int main() {

   //int num, sales;
   string filename;

   cout << "Enter input file name" << endl;
   cin >> filename;

   ifstream inputFile(filename);
   string outfile = "saleschart.txt";


   if (inputFile.is_open()) 
   {
      unsigned int num = 0;
      long long int sales = 0;
      ofstream outputFile(outfile);
      // the input file opened successfully
	  bool firstValidData = true;
      while (inputFile >> num >> sales) 
	  {
         if (num < 1 || num >99) 
		 {
            cout << "The store number " << num << " is not valid" << endl;
            continue;
         }
         if (sales < 0) 
		 {
            cout << "The sales value for store " << num << " is negative" << endl;
            continue;
         }
         int no_of_stars = (int)(sales / 5000);
		 if (firstValidData) //Write header only when there is a valid record
		 {
			 outputFile << "SALES BAR CHART" << endl;
			 outputFile << "(Each * equals 5,000 dollars)" << endl;
			 firstValidData = false;
		 }
		 //cout << "Store " << num << ": " << string(no_of_stars, '*') << endl;
		 if (num < 10)
		 {
			outputFile << "Store  " << num << ": " << string(no_of_stars, '*') << endl;
		 }
		 else
		 {
			outputFile << "Store " << num << ": " << string(no_of_stars, '*') << endl;
		 }
      }
      // close files
      inputFile.close();
      outputFile.close();
   }
   else 
   {
      cout << "File \"" << filename << "\" could not be opened" << endl;
      return -1;
   }

   return 0; // end int main function
}