#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Function declarations
unsigned int readDataFromFile(ifstream& fInput, double& P, double& i, int& t);
double futureValue(double presentValue, double rate, int months);
void writeDataToOutputFile(ofstream& fOutput, double F, double P, double i, int t);

//Driver function
int main()
{
   //Declare the needed variables
   ifstream fInput;
   ofstream fOutput;
   string nameOfInputFile, nameOfOutputFile;
   double presentValue, interestRate, futValue;
   int months;
   unsigned int result;


   //Prompt for input file
   cout << "Enter input file name" << endl;

   //Read input file name
   cin >> nameOfInputFile;
   //nameOfInputFile = "input.txt";

   //Open the input file
   fInput.open(nameOfInputFile.c_str());

   //Check condition
   if (fInput.fail())
   {
      //Error message
      cout << "File \"" << nameOfInputFile << "\" could not be opened" << "\n";
   }
   else
   {
      //Open a file for writing output
      fOutput.open("output.xls");

      //Write to output file
      fOutput << "Future Value" << "\t" << "Present Value" << "\t" << "Monthly Interest" << "\t" << "Months" << endl;

      //Loop to iterate and compute
      while (true)
      {
         //Assign result with the function return
         result = readDataFromFile(fInput, presentValue, interestRate, months);

         //Check condition
         if (result == 1)
         {
            //Assign F with function return
			 double rate = (interestRate / 100);
            futValue = futureValue(presentValue, rate, months);

            //Function call
            writeDataToOutputFile(fOutput, futValue, presentValue, interestRate, months);
         }
         //Check condition
         else if (result == 2)
         {
            //Display
			cout << setprecision(2) << fixed << presentValue << " " << setprecision(3) << fixed << interestRate << " " << months << endl;
            //Display
            cout << "One or more of the above values are not greater than zero\n";

            //Continue
            continue;
         }
         else
         {
            //Close input file
            fInput.close();
            //Close output file
            fOutput.close();
            //Stop
            break;
         }
      }
   }

   //Return
   return 0;
}

//Function definition - readDataFromFile()
unsigned int readDataFromFile(ifstream& fInput, double& presentValue, double& interestRate, int& months)
{
   //Check condition
   if (fInput >> presentValue >> interestRate >> months)
   {
      //Check condition
	   if (presentValue <= 0 || interestRate <= 0 || months <= 0)
	   {
		   return 2;
	   }
	   else
	   {
		   return 1;
	   }
   }
   else
   {
      return 0;
   }
}

//Function definition - calculateFutureValue()
double futureValue(double presentValue, double rate, int months)
{
   double futValue = (presentValue)*pow(1 + rate, months);
   //Return futValue
   return futValue;
}

//Function definition - writeDataToOutputFile()
void writeDataToOutputFile(ofstream& fOutput, double futureValue, double presentValue, double interestRate, int months)
{
   //Write to output file
   fOutput << setprecision(2) << fixed << futureValue << "\t" << setprecision(2) << fixed << presentValue << "\t" << setprecision(3) << fixed << interestRate << "\t" << months << endl;
   //cout <<  futureValue << "\t" <<  presentValue << "\t" <<  interestRate << "\t" << months << endl;
}