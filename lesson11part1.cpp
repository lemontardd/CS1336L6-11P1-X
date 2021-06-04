#include<iostream>
#include<string>
#include<cstring>
#include <fstream>
#include <cstdlib>
#include<cstdbool>
using namespace std;
#define SIZE 3
bool readSquare(int square[SIZE][SIZE], string inputFileName) {
   fstream infile(inputFileName, ios::in);
   if (!infile) {
      return false;
   }
   int i = 0, j = 0;//read file and stores data
   for (i = 0;i < SIZE;i++)
      for (j = 0;j < SIZE;j++)
         infile >> square[i][j];
   return true;
}
bool validDigit(const int square[SIZE][SIZE]) {
   int flag = 0;
   for (int num = 1;num <= 9;num++) {
      flag = 0;
      for (int i = 0;i < SIZE;i++) {
         for (int j = 0;j < SIZE;j++) {
            if (num == square[i][j]) {
               flag = 1;
            }
         }
      }
   }
   if (flag == 0)
      return false;
   return true;
}
bool validateSquare(const int square[SIZE][SIZE]) {
   if (!validDigit(square))
      return false;
   int sum = 0;
   for (int i = 0;i < SIZE;i++) {
      sum = 0;
      for (int j = 0;j < SIZE;j++) {
         sum += square[i][j];
      }
      if (sum != 15)
         return false;
   }
   for (int i = 0;i < SIZE;i++) {
      sum = 0;
      for (int j = 0;j < SIZE;j++) {
         sum += square[j][i];
      }
      if (sum != 15)
         return false;
   }
   //for diagonal from left up to right down
   sum = 0;
   for (int i = 0;i < SIZE;i++) {
      for (int j = 0;j < SIZE;j++) {
         if (i == j)
            sum += square[i][j];
      }
   }
   if (sum != 15)
      return false;
   //for diagonal from right up to left down
   sum = 0;
   for (int i = 2, j = 0;i >= 0;i--, j++) {
      sum += square[i][j];
   }
   if (sum != 15)
      return false;
   //if square is magic one return true
   return true;
}
//display square
void display(const int square[SIZE][SIZE]) {
   cout << "\nMagic square\n";
   for (int i = 0;i < SIZE;i++) {
      for (int j = 0;j < SIZE;j++) {
         cout << square[i][j] << " ";
      }
      cout << endl;
   }
}
//main function
int main() {
   //declaring necessary variables
   string fileName;
   int square[SIZE][SIZE];
   //taking input of filename
   cout << "Enter file name: ";
   getline(cin, fileName);
   //reading data from file
   bool isOpen = readSquare(square, fileName);
   //if file opens display message accordingly
   if (isOpen) {
      //displaying the content of square
      display(square);
      //calling the validSquare function
      bool isValid = validateSquare(square);
      //print result accordingly
      if (isValid)
         cout << "\nValid magic square\n";
      else
         cout << "\nInvalid magic square\n";
   }
   //if file does not open
   else
      cout << "File \"" << fileName << "\" could not be opened\n";
   return 0;
}